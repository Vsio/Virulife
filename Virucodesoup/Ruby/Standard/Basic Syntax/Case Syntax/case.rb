# ===========================
# File : case.rb
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

# This is to do Case statement. "Else" is optional, to do something if there is no value that fits any criteria.

button = 2 # price of something

case button
	when 0 then
		puts "Button 0 Pressed: Nothing happens"

	when 1 then
		puts "Button 1 Pressed: A sound from stomach can be heard."

	when 2 then
		puts "Button 2 Pressed: Gold Coins appear under your bed!"

	when 3 then
		puts "Button 3 Pressed: Ghost appears behind you!"
	
	else # else is optional, to do something if no value (in 'when' statement) fits any criteria
		puts "Huh? What button?"
	
end

gets # pauses command so it doesn't exit immediately
