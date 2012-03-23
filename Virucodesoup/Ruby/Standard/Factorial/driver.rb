# ===========================
# File : driver.rb
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

require_relative "factorial"


print "\n===== FACTORIAL =====\n"

print "\n\n== START PROGRAM ==\n\n"

print "Inputs a number: "; value = gets.strip;

print factorial(value.to_i);

print "\n\n== END PROGRAM ==\n\n"

gets;
