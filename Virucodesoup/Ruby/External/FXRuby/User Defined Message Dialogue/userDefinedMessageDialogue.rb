# ===========================
# File : userDefinedMessageDialogue.rb.rb
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

class MessageDialogue < FXMainWindow
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
		b_button = FXButton.new(self, "Click Me!",:opts=>FRAME_SUNKEN|FRAME_THICK)
		
		# action
		b_button.connect(SEL_COMMAND) do |sender, sel, ptr|
			messagePop("You clicked me!")		
		end
	end
	
	def messagePop(_message)
	# shows user defined message dialogue
		popMessage = FXMessageBox.new(self, "Message Dialogue says:", _message,nil, MBOX_OK|DECOR_TITLE|DECOR_BORDER, self.x, self.y)
		popMessage.execute
	end
	
	def driver()
	# performs object functionally
		interface()
	end
end