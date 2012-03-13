# ===========================
# File : rot13.rb
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

class ROT13
	attr_accessor:inputText_,:outputText_ 
	# inputText_:  text input whicih will be encrypted or decrypted
	# outputText_: text output which is resulted from encryption or decryption
	
	def initialize()
	# inits variables value since initialization
		
		@inputText_  = ""
		@outputText_ = ""
	end
	
	def menu()
	# displays command menu
	
		index = 0
		while (index!="2")
			puts "\n\n==> MENU\n\n"
			puts "1. Do ROT13"
			puts "2. Exit"
			print "\nSelect a number : ";
			index = gets.strip
			puts "\n"
			
			case index
			
				when "1" then
					loadFile()
					doRot13()
					saveFile()
					break
					
				when "2" then 
					break
					
				else 
					puts "> Invalid Input"
					index = 0;
			end
		end
	end
	
	def doRot13()
	# encrypts with ROT13 encryption
	
		i = 0
		plainText = @inputText_
		
		output = ""
		
		while (i != plainText.length)
			if ( /[A-Z]/.match(plainText[i]) )
				output += ( ( (plainText[i].ord - 'A'.ord + 13) % 26)+ 'A'.ord).chr 
			elsif ( /[a-z]/.match(plainText[i]) )
				output += ( ( (plainText[i].ord - 'a'.ord + 13) % 26)+ 'a'.ord).chr
			else
				output += plainText[i]
			end
			i+=1
		end
		
		puts "\n> ROT13 Result:\n"+output
		
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
	
	def saveFile()
	# saves output a file
		
			begin
				file = File.new("output.txt","w")			
				file.print @outputText_;
				file.close;
				puts "\n> ROT13 result has been saved into output.txt"
			rescue
				puts "> File not found."
			end
	end	
	
end
