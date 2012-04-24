# ===========================
# File : inputFromTextField.rb
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

class InputFromTextField < FXMainWindow
	def initialize(_app, _title, _w, _h)
	# inits value when instantiated
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
		FXLabel.new(self,"Input some text: ")
		tf_input = FXTextField.new(self, 20)
		b_submit = FXButton.new(self, "Submit",:opts=>FRAME_SUNKEN|FRAME_THICK)
		l_input = FXLabel.new(self,"Your input: ")
		
		# action
		b_submit.connect(SEL_COMMAND) do |sender, sel, ptr|
			l_input.text = 	"Your input: "+tf_input.text
		end
	end
	
	def driver()
	# performs object functionally
		interface()
	end
end