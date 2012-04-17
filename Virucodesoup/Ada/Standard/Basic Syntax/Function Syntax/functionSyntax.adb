-- ===========================
-- File : functionSyntax.adb
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

-- # This is to do Function block. In Ada, you can use "function". You also must put "return" so the function will return value.

with Ada.Text_IO; -- to enable printing in string type
with Gnat.IO; -- to enable printing in integer type

procedure FunctionSyntax is 
	
	-- Function Declaration --
	
	function add(a_number1,a_number2: Integer) return Integer is
	-- Do a_number1+a_number2
	
	begin
		return (a_number1+a_number2);
	end add;
	
	
	-- Variable Declaration --
	
	pause : String(1..1);
	
begin

	Gnat.IO.Put(add(100,100));
	
	Ada.Text_IO.Get(pause); -- prevents program to close instantly when done
	
end FunctionSyntax;
