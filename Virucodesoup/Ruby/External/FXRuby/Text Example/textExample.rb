# ===========================
# File : textExample.rb
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

class TextExample < FXMainWindow
	def initialize(_app, _title, _w, _h)
	# inits value when instantiated
		super(_app, _title, :width => _w, :height => _h)  
	end
	
	def create()
	# to activate create event from parent class
		super
		show(PLACEMENT_SCREEN)
	end
	
	def showText()
	# shows text
		FXLabel.new(self,"This is an example of displaying text. You can use FXLabel to achieve it.")
	end
	
	def driver()
	# performs object functionally
		showText()
	end
end