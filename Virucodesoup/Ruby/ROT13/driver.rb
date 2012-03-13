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

require_relative "rot13"

print "\n===== ROT13 =====\n"

print "\n\n== START PROGRAM ==\n\n"

rot13driver = ROT13.new
rot13driver.menu()

print "\n\n== END PROGRAM ==\n\n"

gets;