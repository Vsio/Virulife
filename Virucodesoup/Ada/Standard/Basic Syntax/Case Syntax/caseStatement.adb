-- ===========================
-- File : case.adb
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

-- This is to do Case statement. "when others" is optional, to do something if there is no values that fit any criteria.

with Ada.Text_IO;

procedure CaseStatement is 

	button : Integer := 3; -- random value
	pause : String(1..1);
	
begin

	case button is
		when 1 | 2 =>
			Ada.Text_IO.Put_Line("You pressed 1 or 2.");
		when 3 =>
			Ada.Text_IO.Put_Line("You pressed 3.");
		when 4 =>
			Ada.Text_IO.Put_Line("You pressed 4.");
		when others =>	
			Ada.Text_IO.Put_Line("You pressed others.");
	end case;
	
	Ada.Text_IO.Get(pause); -- prevents program to close instantly when done
	
end CaseStatement;
