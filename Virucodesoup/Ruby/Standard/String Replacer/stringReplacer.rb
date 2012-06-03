# ===========================
# File : stringReplacer.rb
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

class StringReplacer
	attr_accessor:inputText_,:replaceTarget_,:replaceAfter_,:outputText_ 
	# inputText_:  text input whicih will be encrypted or decrypted
	# replaceTarget_: string which wants to be replaced
	# replaceAfter_: string which replaces the string target
	# outputText_: text output which is resulted from encryption or decryption
	
	def initialize()
	# inits variables value since initialization
		
		@inputText_  = ""
		@replaceTarget_ = ""
		@replaceAfter_ = ""
		@outputText_ = ""
	end
	
	def promptGetStringTarget()
	# prompt to get @replaceTarget_ value
	
		puts "> Input string which want to be replaced "
		@replaceTarget_ = gets.strip
		
		return @replaceTarget_
	end
	
	def promptGetStringAfter()
	# prompt to get @replaceAfter_
	
		puts "> Input string which replaces the target string"
		@replaceAfter_ = gets.strip
		
		return @replaceAfter_
	end
	
	def doStringReplace()
	# replaces string
	
		@outputText_ = @inputText_.gsub(@replaceTarget_,@replaceAfter_)
		
		puts @outputText_
		
		return @outputText_	
	end
	
	def loadFile()
	# loads input from a file
		
		begin
			print "> Input File: "
			fileString = gets.strip
			file = File.new(fileString,"rb")			
			buffer = ''
			
			file.each_line do |line|
				buffer += line
			end
			
			@inputText_ = buffer
			puts @inputText_
			puts ""
			file.close
			return true
		rescue
			puts "> File not found. Try again."
			loadFile()
		end
	end
	
	def saveFile()
	# saves output a file
		
		begin
			file = File.new("output.txt","wb")			
			file.print @outputText_;
			file.close;
			puts "\n> New string has been saved into output.txt"
			return true
		rescue
			puts "> File not found."
			return false
		end
	end	
	
	def driver()
	# performs object's functionality
	
		loadFile()
		promptGetStringTarget()
		promptGetStringAfter()
		doStringReplace()
		saveFile()
	end
	
end
