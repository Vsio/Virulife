# ===========================
# File : palindromeCheck.rb
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


def isPalindrome(_string)
# Checks whether a string is a palindrome

	raise "Input is null." unless (_string.length != 0)
	raise "Input is a single character." unless (_string.length != 1)	

	if (_string == _string.reverse)
		return true
	else
		return false
	end
end
