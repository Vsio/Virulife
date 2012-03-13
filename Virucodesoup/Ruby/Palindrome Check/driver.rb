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

require_relative "palindromeCheck"

print "\n===== PALINDROME CHECK =====\n"
print "\n\n== START PROGRAM ==\n\n"
print "Input some string: " 

value = gets.strip

if isPalindrome(value)
	print "> String is a palindrome."
else 
	print "> String is not a palindrome."
end

print "\n\n== END PROGRAM ==\n\n"

gets