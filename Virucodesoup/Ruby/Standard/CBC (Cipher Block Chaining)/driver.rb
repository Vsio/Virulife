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

require_relative "cbc"

print "\n===== CBC (Cipher-Block Chaining) =====\n"
print "\n\n== START PROGRAM ==\n\n"

cbcDriver = CBC.new
cbcDriver.driver()

print "\n\n== END PROGRAM ==\n\n"

gets