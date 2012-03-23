# ===========================
# File : helloWorldApp.rb
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

require_relative "helloWorld"

Shoes.app :title => "Hello World", :width => 300, :height => 100 do
	flow do
		style(:margin_top => "50%",:top => "-12.5%",:margin_left => "50%", :left => "-25%")
		button("Say Hello World!") do
			alert(sayHelloWorld())
		end
	end
end