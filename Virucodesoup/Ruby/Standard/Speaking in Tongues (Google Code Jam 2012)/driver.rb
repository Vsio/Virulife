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

require_relative "gjs_SpeakingInTongues.rb"

print "\n===== Google Jam Solver =====\n"
print "\n\n== START PROGRAM ==\n\n"

gjs = GJS_SpeakingInTongues.new
gjs.driver()

print "\n\n== END PROGRAM ==\n\n"

gets