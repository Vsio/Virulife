-- ===========================
-- File : Driver.adb
-- 
-- Credit:
-- - Coded by (aka in cyber) Vsio Stitched.
-- - Problem case inspired from >> http://www.cprogramming.com/challenges/celsius_converter_table.html
-- 
-- License:
-- - Free to use
-- - May include me or not in credit if included in other project
-- ===========================

with TemperatureConverterListing;
with Ada.Text_IO;

procedure Driver is

	pause : String(1..1);
		
begin

	Ada.Text_IO.Put_Line("");
	Ada.Text_IO.Put_Line("");
	Ada.Text_IO.Put_Line("###### Program starts ######");
	Ada.Text_IO.Put_Line("");
	Ada.Text_IO.Put_Line("");
	
	TemperatureConverterListing.HeaderText;
	TemperatureConverterListing.Main;
	
	Ada.Text_IO.Put_Line("");
	Ada.Text_IO.Put_Line("");
	Ada.Text_IO.Put_Line("###### Program ends ######");
	Ada.Text_IO.Put_Line("");	
	Ada.Text_IO.Put_Line("");
	
	Ada.Text_IO.Get(pause);
	
end Driver;