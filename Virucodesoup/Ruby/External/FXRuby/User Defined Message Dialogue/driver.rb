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

require_relative "userDefinedMessageDialogue"

app_messageDialogue = FXApp.new()
win_messageDialogue = MessageDialogue.new(app_messageDialogue,"Message Dialogue",100,30)
win_messageDialogue.driver()
app_messageDialogue.create()
app_messageDialogue.run()

