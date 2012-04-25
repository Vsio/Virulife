# ===========================
# File : gjs_SpeakingInTongues.rb
#
# Credit:
# - Coded by (aka in cyber) Vsio Stitched
# - Problem case and example (in A-small-attempt0.in and Speaking_in_Toungues_example.txt) from Google Code Jam 2012 Qualification Round (http://code.google.com/codejam/contest/1460488/dashboard#s=p0)
# Misc:
# - Written in Ruby programming language
#
# License:
# - Free to use
# - May include me or not in credit if included in other project
# ===========================

class GJS_SpeakingInTongues
	attr_accessor:inputCase_,:inputFile_,:outputCase_
	# inputCase_: input case
	# inputFile_: input file
	# outputCase_ : output case

	def initialize()
	# inits variables value since initialization
		@inputCase_ = ""
		@inputFile_ = ""
		@outputCase_ = ""
	end
	
	def inputCaseParsing()
	# parsing the input case string
		input = @inputCase_
		output = []
		
		output = input.split("\n")
		return output
	end
	
	def SpeakingInTonguesSolve()
	# solved Speaking in Tongues problems
	
		inputArr = inputCaseParsing()	
		t = inputArr[0].to_i(10)
		
		# Constraint
		
		if !(1<=t)
			raise "Error: T is less than 1"
		end
		
		if !(t<=30)
			raise "Error: T is more than 30"
		end
		
		#############
		
		g = inputArr[1..t]
		output = []
		
		i = 0
		
		while (i != (t))
		
			input = g[i]
			input = input.gsub("a","Y")
			input = input.gsub("b","H")
			input = input.gsub("c","E")
			input = input.gsub("d","S")
			input = input.gsub("e","O")
			input = input.gsub("f","C")		
			input = input.gsub("g","V")
			input = input.gsub("h","X")
			input = input.gsub("i","D")
			input = input.gsub("j","U")
			input = input.gsub("k","I")
			input = input.gsub("l","G")				
			input = input.gsub("m","L")
			input = input.gsub("n","B")
			input = input.gsub("o","K")		
			input = input.gsub("p","R")
			input = input.gsub("q","Z")
			input = input.gsub("r","T")
			input = input.gsub("s","N")
			input = input.gsub("t","W")
			input = input.gsub("u","J")
			input = input.gsub("v","P")
			input = input.gsub("w","F")
			input = input.gsub("x","M")		
			input = input.gsub("y","A")
			input = input.gsub("z","Q")
			output[i] = "Case #"+(i+1).to_s(10)+": "+input.downcase
			
			i += 1
		end
	
		i = 0
		puts "> Output:\n"
		puts output
		
		while (i<output.length)
			@outputCase_ += output[i].gsub("\r","")+"\n"
			i+=1
			if (i == output.length)
				@outputCase_ = @outputCase_[0..@outputCase_.length-2]
			end
		end
		
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
			@inputFile_ = fileString
			@inputCase_ = buffer
			puts "> Input:\n"
			puts @inputCase_
			puts "\n"
			file.close
		rescue
			puts "> File not found. Try again."
			loadFile()
		end
	end
	
	def saveFile()
	# saves output a file
	
		begin
			file = File.new("solution_"+@inputFile_,"wb")			
			file.print @outputCase_
			file.close;
			
			puts "\n> Solution has been saved into solution_"+@inputFile_
		rescue
			puts "> File not found."
		end
	end	
	
	def driver()
	# simulates instance functionality
		
		loadFile()
		SpeakingInTonguesSolve()
		saveFile()
	end
	
end
