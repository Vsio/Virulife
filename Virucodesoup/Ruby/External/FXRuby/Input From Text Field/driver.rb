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

require_relative "inputFromTextField"

app_InputFromTextField = FXApp.new()
win_InputFromTextField = InputFromTextField.new(app_InputFromTextField,"Input From Text Field",350,100)
win_InputFromTextField.driver()
app_InputFromTextField.create()
app_InputFromTextField.run()

