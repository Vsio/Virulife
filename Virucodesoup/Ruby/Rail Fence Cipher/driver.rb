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

require_relative "railFenceCipher"

print "\n===== Rail Fence Cipher =====\n"

print "\n\n== START PROGRAM ==\n\n"

RFCdriver = RailFenceCipherAlphabet.new
RFCdriver.menu()

print "\n\n== END PROGRAM ==\n\n"

gets;