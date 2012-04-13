-- ===========================
-- File : IfThen.adb
--
-- Credit:
-- - Coded by (aka in cyber) Vsio Stitched
--
-- Misc:
-- - Written in Ada programming language
--
-- License:
-- - Free to use
-- - May include me or not in credit if included in other project
-- ===========================

-- This is to simulate conditional If-Then syntax. If true, then it will executes something. If false, nothing happens. For practice, try to change var1 and var2 value.

with Ada.Text_IO;

procedure IfThen is 

	var1 : Integer := 5; -- random value 1
	var2 : Integer := 5; -- random value 2
	pause : String(1..1);
	
begin

	if (var1 = var2) then
		Ada.Text_IO.Put_Line("Value is true"); -- If true, then prints "Value is true"
	end if;
	
	Ada.Text_IO.Get(pause); -- prevents program to close instantly when done
	
end IfThen;
