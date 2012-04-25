# ===========================
# File : gcj_dancingWithTheGooglers.rb
#
# Credit:
# - Coded by (aka in cyber) Vsio Stitched
# - Problem case and example (in B-small-attempt0.in, B-large.in, and Dancing_With_the_Googlers_example.txt) from Google Code Jam 2012 Qualification Round (http://code.google.com/codejam/contest/1460488/dashboard#s=p1)
#
# Misc:
# - Written in Ruby programming language
#
# License:
# - Free to use
# - May include me or not in credit if included in other project
# ===========================

class GCJ_DancingWithTheGooglers
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
	# parses the input case string
		input = @inputCase_
		output = []
		
		output = input.split("\n")
		return output
	end
	
	def isMaySurprise(_totScore)
	# checks whether total score may contain a surprise
		if (_totScore >= 2 && _totScore <= 28)
			return true
		else 
			return false
		end
	end
	
	def isOneOfBest(_totScore, _p, _isSurprise)
	# checks whether total scores contain one of the best score
		
		min = (_p-1)*3 + 1
		#puts "==="
		#puts min
		#puts _totScore
		#puts "==="
		if ( (_isSurprise == true) )
			min = (_p-2) + ((_p-1)*2)
			
			if (_totScore >= min)
				return true
			else 
				return false
			end
		else		
			if (_totScore >= min)
				return true;
			else 
				return false
			end
		end
		
	end
	
	def DancingWithTheGooglersSolve()
	# solved Dancing With the Googlers problems
	
		inputArr = inputCaseParsing()	
		t = inputArr[0].to_i(10)
		i = 0
		output = []
		
		while (i != t)
			
			tArray = inputArr[i+1].split(" ")  # list of attribute
			n = tArray[0].to_i(10) # number Googler Dancer
			s = tArray[1].to_i(10) # number surprise
			sS = 0 
			p = tArray[2].to_i(10) # minumum at least of one score from triplet
			totScore = tArray[3..tArray.length-1] # list of total score
			tot_i = 0
			moreThanP = 0
			
			while (tot_i != totScore.length)
				#puts totScore[tot_i].to_i(10)

				if (isOneOfBest(totScore[tot_i].to_i(10),p,false))
					moreThanP += 1
				else 
					if (sS!=s)
						
						if (isOneOfBest(totScore[tot_i].to_i(10),p,isMaySurprise(totScore[tot_i].to_i(10))))
							moreThanP += 1
							sS += 1
						end
												
					end
				end
				
				tot_i += 1
				
			end
			
			#print n," ",s," ",p," ",totScore,"\n"
			#print ">"
			#puts moreThanP
			output += [moreThanP]
			i+=1
		end
		puts "> Output:"
		
		i = 0
		
		while (i!=output.length)
			@outputCase_ += "Case #"+(i+1).to_s(10)+": "+output[i].to_s(10).gsub("\r","")+"\n"
			i+=1
			if (i == output.length)
				@outputCase_ = @outputCase_[0..@outputCase_.length-2]
			end
		end
		
		puts @outputCase_
		
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
		DancingWithTheGooglersSolve()
		saveFile()
				
	end
	
end
