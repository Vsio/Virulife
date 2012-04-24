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

require_relative "textExample"

app_TextExample = FXApp.new()
win_TextExample = TextExample.new(app_TextExample,"Text Example",400,50)
win_TextExample.driver()
app_TextExample.create()
app_TextExample.run()

