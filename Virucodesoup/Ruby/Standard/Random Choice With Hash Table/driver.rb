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

require_relative "randomChoiceWithHashTable"


print "\n===== RANDOM CHOICE =====\n"

print "\n\n== START PROGRAM ==\n\n"

# In this case, just say I want to order food from menu randomly.

ht_Food = {0=>"burger",1=>"pizza",2=>"peanut",3=>"fried chicken",4=>"pizza",5=>"tempeh"}

print "You ordered ",randomChoiceWithHashTable(ht_Food)," randomly.\n"

print "\n\n== END PROGRAM ==\n\n"

gets;
