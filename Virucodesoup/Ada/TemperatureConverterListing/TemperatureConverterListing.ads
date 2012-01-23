-- ===========================
-- File : temperatureConverterListing.ads
-- 
-- Credit:
-- - Coded by (aka in cyber) Vsio Stitched.
-- - Problem case inspired from >> http://www.cprogramming.com/challenges/celsius_converter_table.html
-- 
-- License:
-- - Free to use
-- - May include me or not in credit if included in other project
-- ===========================

with Ada.Text_IO;
with Ada.Float_Text_IO;
with Ada.Integer_Text_IO;

package TemperatureConverterListing is

LOWER_LIMIT : constant integer := 0;
HIGHER_LIMIT : constant integer := 50000;
TAB : constant Character := Character'Val(9);

procedure HeaderText;
procedure Main;

end TemperatureConverterListing;