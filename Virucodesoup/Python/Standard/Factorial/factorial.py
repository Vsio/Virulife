# ===========================
# File : factorial.py
#
# Credit:
# - Coded by (aka in cyber) Vsio Stitched
#
# Misc:
# - Written in Python programming language
#
# License:
# - Free to use
# - May include me or not in credit if included in other project
# ===========================


# FUNCTION DEFINITION

def factorial(_value):
# does factorial calculation

	try:
		value = int(_value)
	except ValueError:
		print "> Error: Input must number"
		return ""
	
	if (value < 0):
		print "> Error: Input must be higher than 0"
		return ""
			
	if (value == 0):
		return 1;
	elif (value > 0):
		return ( value*factorial(value-1) )

