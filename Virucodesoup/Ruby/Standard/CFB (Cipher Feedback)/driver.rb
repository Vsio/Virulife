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

require_relative "cfb"

print "\n===== CFB (Cipher Feedback) =====\n"
print "\n\n== START PROGRAM ==\n\n"

cfbDriver = CFB.new
cfbDriver.driver()

print "\n\n== END PROGRAM ==\n\n"

gets