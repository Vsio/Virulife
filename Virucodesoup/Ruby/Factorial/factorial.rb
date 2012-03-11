# ===========================
# File : helloWorld.rb
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


# FUNCTION DEFINITION

def factorial(_value)
	raise "Input must be higher than 0" unless (_value >= 0)

	if (_value == 0)
		return 1;
	elsif (_value > 0)
		return ( _value*factorial(_value-1) );
	end
end


# DRIVER

print "\n===== FACTORIAL =====\n"

print "\n\n== START PROGRAM ==\n\n"

print "Inputs a number: "; value = gets.strip;

print factorial(value.to_i);

print "\n\n== END PROGRAM ==\n\n"

gets;
