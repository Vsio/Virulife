# ===========================
# File : readLoadFile.rb
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

require 'fox16'
include Fox

class ReadFile < FXMainWindow
	def initialize(_app, _title, _w, _h)
	# inits value when get instantiated
		super(_app, _title, :width => _w, :height => _h)  
	end
	
	def create()
	# to activate create event from parent class
		super
		show(PLACEMENT_SCREEN)
	end
	
	def interface()
	# sets interface 
	
		# component initialization			
		b_save = FXButton.new(self, "Load",:opts=>FRAME_SUNKEN|FRAME_THICK)
		FXLabel.new(self,"Loaded Text:")
		tf_output = FXTextField.new(self, 20,NIL,0,FRAME_SUNKEN|FRAME_THICK|TEXT_READONLY)	
		
		# action
		b_save.connect(SEL_COMMAND) do |sender, sel, ptr|
			fileload = FXFileDialog.getSaveFilename(self, "Load Text", ".txt", "*.txt")
			loadResult = loadFile(fileload)			
			tf_output.text = loadResult[1]
			if loadResult[0]
				messagePop("Loaded successfully.")
			end
		end
	end
	
	def messagePop(_message)
	# shows user defined message dialogue
		popMessage = FXMessageBox.new(self, "WriteFile says:", _message,nil, MBOX_OK|DECOR_TITLE|DECOR_BORDER, self.x, self.y)
		popMessage.execute
	end
	
	def loadFile(_filename)
	# loads input from a file		
		begin
			fileString = _filename
			file = File.new(fileString,"rb")			
			buffer = ''
			output = "";
			
			file.each_line do |line|
				buffer += line
			end
			
			output = buffer
			file.close
			return [true,output]
		rescue
			puts "> Load Failed: File not found."
			loadFile()
			return false
		end
	end
	
	def driver()
	# performs object functionally
		interface()
	end
end