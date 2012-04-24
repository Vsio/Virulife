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

require_relative "readLoadFile"

app_readFile = FXApp.new()
win_readFile = ReadFile.new(app_readFile,"Read (Load) File",350,75)
win_readFile.driver()
app_readFile.create()
app_readFile.run()

