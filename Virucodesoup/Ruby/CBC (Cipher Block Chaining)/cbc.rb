# ===========================
# File : cbc.rb
#
# Credit:
# - Coded by (aka in cyber) Vsio Stitched
#
# Misc:
# - Written in Ruby programming language
#
# License:
# - Free to use
# - May include me or not in credit if included in other project
# ===========================

class CBC
	attr_accessor:inputText_,:key_,:outputText_
	# inputText_: text input whicih will be encrypted or decrypted
	# key_: binary input
	# outputText_: text output which is resulted from encryption or decryption
	
	def initialize()
	# inits variables value since initialization
		
		@inputText_  = ""
		@key_ = ""
		@outputText_ = ""
	end
	
	def menu()
	# displays command menu
	
		index = 0
		while (index!="3")
			puts "\n\n==> MENU\n\n"
			puts "1. Encrypt"
			puts "2. Decrypt"
			puts "3. Exit"
			print "\nSelect a number : ";
			index = gets.strip
			puts "\n"
			
			case index
			
				when "1" then
					loadFile()
					inputKey()
					encipher()
					saveFile(0)
					break

				when "2" then
					loadFile()
					inputKey()
					decipher()
					saveFile(1)
					break
					
				when "3" then 
					break
					
				else 
					puts "> Invalid Input"
					index = 0;
			end
		end
	end
	
	def inputKey()
	# input key_ value
	
		value = " "
		regexConstraint = /[^0-1]/
		while (regexConstraint.match(value))
			print "\nInput binary string: "
			value = gets.strip
			if (regexConstraint.match(value))
				puts "> Error: Only 0 or 1 is allowed"					
			end
		end
		
		@key_ = value
	end
	
	def generateIV()
	# generates Initialization Vector randomly
	
		blockLength = @key_.length
		iv = ""
		
		for i in 0..blockLength-1
			iv += rand.round.to_s
		end
		
		print "\n> IV generated: ", iv, "\n"
		
		saveIV(iv)
		
		return iv
	end
	
	def encipher()
	# enciphers with CBC method
	
		inputBit = @inputText_.unpack("B*")[0]
		inputBitLength = inputBit.length
		key = @key_
		blockLength = key.length
		blockPlain = "";
		blockCipher = "";
		iv = generateIV()
		output = ""
		outputText = ""
		i = 0
		j = 0
		
		while (inputBit.length % key.length != 0)
			inputBit += '0'
		end
		
		for i in 0..key.length-1
			blockCipher += (inputBit[j].to_i ^ iv[i].to_i ^ key[i].to_i).to_s			
			j += 1		
		end		
		
		output += blockCipher
		blockPlain = blockCipher
		blockCipher = ""
		
		while (j != inputBit.length)			
			for i in 0..key.length-1				
				blockCipher += (inputBit[j].to_i ^ blockPlain[i].to_i ^ key[i].to_i).to_s
				j += 1
			end	
			output += blockCipher
			blockPlain = blockCipher
			blockCipher = ""
		end
		
		output = output[0..inputBitLength-1]
		
		i = 0
		
		while (i!=output.length)
			outputText += [output[i..i+7]].pack("B*")
			i+=8
		end
		
		@outputText_ = outputText
		puts "\n>Encryption Result:"
		puts outputText
	end
	
	def decipher()
	# deciphers with CBC method

		inputBit = @inputText_.unpack("B*")[0]
		inputBitLength = inputBit.length
		key = @key_
		blockLength = key.length
		blockPlain = ""
		blockCipher = ""
		blockTemp = ""
		iv = loadIV()
		output = ""
		outputText = ""
		i = 0
		j = 0
		
		while (inputBit.length % key.length != 0)
			inputBit += '0'
		end
		
		for i in 0..key.length-1
			blockCipher += inputBit[j]
			blockPlain += (blockCipher[i].to_i ^ iv[i].to_i^ key[i].to_i).to_s			
			j += 1		
		end		
		
		output += blockPlain
		blockPlain = ""
		
		while (j != inputBit.length)			
			for i in 0..key.length-1				
				blockPlain += (inputBit[j].to_i ^ key[i].to_i ^ blockCipher[i].to_i).to_s
				blockTemp += inputBit[j]
				j += 1
			end	
			output += blockPlain
			blockPlain = ""
			blockCipher = blockTemp
			blockTemp = ""
		end
		
		output = output[0..inputBitLength-1]
		
		i = 0
		
		while (i!=output.length)
			outputText += [output[i..i+7]].pack("B*")
			i+=8
		end
		
		@outputText_ = outputText
		puts "\n>Decryption Result:"
		puts outputText
		
	end
	
	def loadFile()
	# loads input from a file
		
		begin
			print "Input File: "
			fileString = gets.strip
			file = File.new(fileString,"rb")			
			buffer = ''
			
			file.each_line do |line|
				buffer += line
			end
			
			@inputText_ = buffer
			puts "\n"+@inputText_
			file.close
		rescue
			puts "> File not found. Try again."
			loadFile()
		end
	end

	def loadIV()
	# loads Initialization Vector from a file
		
		begin
			print "Input IV File: "
			fileString = gets.strip
			file = File.new(fileString,"rb")			
			buffer = ''
			
			file.each_line do |line|
				buffer += line
			end
			
			output = buffer
			puts "\n"+output
			file.close
		rescue
			puts "> File not found. Try again."
			loadFile()
		end
		
		return output
	end
	
	def saveFile(_index)
	# saves output a file
	
		if (_index == 0)
			begin
				file = File.new("output_encipher.txt","wb")			
				file.print @outputText_;
				file.close;
				puts "\n> CBC enciphering result has been saved into output_encipher.txt"
			rescue
				puts "> File not found."
			end
		elsif (_index == 1)
			begin
				file = File.new("output_decipher.txt","wb")			
				file.print @outputText_;
				file.close;
				puts "\n> CBC deciphering result has been saved into output_decipher.txt"
			rescue
				puts "> File not found."
			end
		end
	end	
	
	def saveIV(_iv)
	# saves output a file
	
		begin
			file = File.new("iv.txt","wb")			
			file.print _iv;
			file.close;
			puts "\n> IV has been saved into iv.txt"
		rescue
			puts "> File not found."
		end
	end	
	
	def driver()
	# simulates instance functionality
		
		menu()
	end
	
end
