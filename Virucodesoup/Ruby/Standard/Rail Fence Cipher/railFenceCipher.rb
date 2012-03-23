# ===========================
# File : railFenceCipher.rb
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


# CLASS DEFINITION

class RailFenceCipherAlphabet
	attr_accessor:inputText_,:key_,:outputText_ 
	# inputText_:  text input whicih will be encrypted or decrypted
	# key_ : number of rails which will be used
	# outputText_: text output which is resulted from encryption or decryption
	
	def initialize()
	# inits variables value since initialization
		
		@inputText_  = ""
		@key_ = 0
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
	
		value = 0
		
		while (value<1)
			print "\nInput total of rails: "
			value = gets.strip.to_i
			if (value<1)
				puts "Error: Total Rails may not lower than 1."					
			end
		end
		
		@key_ = value
	end
	
	def encipher()
	# enciphers with Rail Fence Cipher
	
		regex_constrain = /[^A-z0-9]/;
		plainText = @inputText_.upcase
		plainText = plainText.gsub(regex_constrain,"")
		totalRails = @key_
		list_Str = []
		strTemp = ""
		output = ""
		i = 0
		j = 0
		
		begin
			raise unless (totalRails!=1)
		rescue
			if (totalRails==1)
				puts "\n> Deciphering Result:\n"+plainText
				@outputText_ = plainText
				return
			end
		end
		
		for i in 0..(totalRails-1)
			list_Str.push("")		
		end
		
		i = 0
		
		begin
			while (j != plainText.length)
				while (i!=totalRails-1)
					list_Str[i] += plainText[j]
					j+=1
					i+=1
				end
				while (i!=0)
					list_Str[i] += plainText[j]
					j+=1
					i-=1
				end
			end
		rescue
			# I am rescued! :D
		end
		
		i = 0
		
		for i in 0..(totalRails-1)
			output += list_Str.push[i]
		end
		
		puts "\n> Enciphering Result:\n"+output
		
		@outputText_ = output		
	end

	def decipher()
	
	# deciphers with Rail Fence Cipher
		regex_constrain = /[^A-z0-9]/;		
		cipherText = @inputText_.upcase
		cipherText = cipherText.gsub(regex_constrain,"")
		totalRails = @key_
		multiplier = 0
		list_Str = []
		pointer = 0
		output = ""
		
		begin
			raise unless (totalRails!=1)
		rescue
			if (totalRails==1)
				puts "\n> Deciphering Result:\n"+cipherText
				@outputText_ = cipherText
				return 
			end
		end
		
		extra = cipherText.length % (totalRails*2-2)
		base = (cipherText.length-extra) / (totalRails*2-2)	
		extraPointerPeriode = extra / 2
		extraPointer = totalRails*2 - extra
		
		#puts extra
		#puts base
		#puts extraPointerPeriode
		#puts extraPointer
		
		numb = 0
		
		for i in 0..(totalRails-1)			
			if ( (i == 0) || (i == totalRails-1) )
				multiplier = 1
			else 
				multiplier = 2
			end
			if ((cipherText[pointer..(pointer+(base*multiplier)+numb-1)]).length != 0)				
				if (extra != 0)					

					if (extraPointerPeriode == 0)
						if (i < extraPointer)
							numb = 1
						else
							numb = 0
						end
					else
						if (i < extraPointer-1)
							numb = 1
						else
							numb = 2
						end
					end
					
					extra -= 1
				else
					numb = 0
				end
				
				list_Str.push(cipherText[pointer..(pointer+(base*multiplier)+numb-1)])
				#puts list_Str[i]
				pointer = pointer+(list_Str[i]).length
			
			else
				
			end
		end
		
		j = 0
				
		begin
			while (output.length != cipherText.length)
				while (j!=totalRails-1)
					output += list_Str[j][0]
					list_Str[j].slice! list_Str[j][0]
					j+=1
				end
				while (j!=0)
					output += list_Str[j][0]
					list_Str[j].slice! list_Str[j][0]
					j -=1
				end
				j = 0
			end
		rescue
			
		end
		
		puts "\n> Deciphering Result:\n"+output
		
		@outputText_ = output
	end
	
	def loadFile()
	# loads input from a file
		
		begin
			print "> Input File: "
			fileString = gets.strip
			file = File.new(fileString,"r")			
			buffer = ''
			
			file.each_line do |line|
				buffer += line
			end
			
			@inputText_ = buffer
			puts @inputText_
			file.close
		rescue
			puts "> File not found. Try again."
			loadFile()			
		end
	end
	
	def saveFile(_index)
	# saves output a file
	
		if (_index == 0)
			begin
				file = File.new("output_encipher.txt","w")			
				file.print @outputText_;
				file.close;
				puts "\n> Rail Fence Cipher deciphering result has been saved into output_encipher.txt"
			rescue
				puts "> File not found."
			end
		elsif (_index == 1)
			begin
				file = File.new("output_decipher.txt","w")			
				file.print @outputText_;
				file.close;
				puts "\n> Rail Fence Cipher enciphering result has been saved into output_decipher.txt"
			rescue
				puts "> File not found."
			end
		end
	end	
	
end
