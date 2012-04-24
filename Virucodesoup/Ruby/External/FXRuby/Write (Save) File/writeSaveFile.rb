# ===========================
# File : writeSaveFile.rb
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

class WriteFile < FXMainWindow
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
		FXLabel.new(self,"Input Text Here:")
		tf_input = FXTextField.new(self, 20)		
		b_save = FXButton.new(self, "Save",:opts=>FRAME_SUNKEN|FRAME_THICK)
		
		# action
		b_save.connect(SEL_COMMAND) do |sender, sel, ptr|
			filesave = FXFileDialog.getSaveFilename(self, "Save Input", ".txt", "*.txt")
			if saveFile(tf_input.text,filesave)
				messagePop("Saved successfully.")
			end
		end
	end
	
	def messagePop(_message)
	# shows user defined message dialogue
		popMessage = FXMessageBox.new(self, "WriteFile says:", _message,nil, MBOX_OK|DECOR_TITLE|DECOR_BORDER, self.x, self.y)
		popMessage.execute
	end
	
	def saveFile(_input,_filename)
	# saves/writes a file
		begin
			file = File.new(_filename,"wb")			
			file.print _input;
			file.close;
			puts "> Saved successfully."
			return true;
		rescue
			puts "> Save Failed: File not found."
			return false
		end
	end
	
	def driver()
	# performs object functionally
		interface()
	end
end