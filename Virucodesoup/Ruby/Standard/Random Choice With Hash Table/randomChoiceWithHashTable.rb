# ===========================
# File : randomChoiceWithHashTable.rb
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


def randomChoiceWithHashTable(_hashTable)
# do a random choice to choose  element from hash table
# _hashTable : hast table which input on left side is number
	
	htSize = _hashTable.length # size of member from hash table
	choice=rand(htSize) # choice whoch is chosen randomly
	
	return _hashTable[choice]
end
