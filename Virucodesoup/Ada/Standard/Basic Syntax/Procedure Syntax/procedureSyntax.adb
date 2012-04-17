-- ===========================
-- File : procedureSyntax.adb
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

-- This is to do Procedure block. In Ada, you can use "procedure".

with Ada.Text_IO; -- to enable printing in string type
with Gnat.IO; -- to enable printing in integer type

procedure ProcedureSyntax is 
	
	-- Procedure Declaration --
	
	procedure printNumber(a_number :in Integer) is
	-- prints number into display
	
	begin
		Ada.Text_IO.Put("The number is ");
		Gnat.IO.Put(a_number);
		Ada.Text_IO.Put_Line("");
	end printNumber;
	
	
	-- Variable Declaration --
	
	pause : String(1..1);
	
begin

	printNumber(100);
	
	Ada.Text_IO.Get(pause); -- prevents program to close instantly when done
	
end ProcedureSyntax;
