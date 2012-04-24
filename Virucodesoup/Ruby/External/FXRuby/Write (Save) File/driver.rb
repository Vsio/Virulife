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

require_relative "writeSaveFile"

app_writeFile = FXApp.new()
win_writeFile = WriteFile.new(app_writeFile,"Write (Save) File",350,75)
win_writeFile.driver()
app_writeFile.create()
app_writeFile.run()

