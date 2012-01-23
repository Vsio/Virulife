-- ===========================
-- File : temperatureConverterListing.adb
-- 
-- Credit:
-- - Coded by (aka in cyber) Vsio Stitched.
-- - Problem case inspired from >> http://www.cprogramming.com/challenges/celsius_converter_table.html
-- 
-- License:
-- - Free to use
-- - May include me or not in credit if included in other project
-- ===========================

package body TemperatureConverterListing is

	procedure HeaderText is 
	
	begin
	
		Ada.Text_IO.Put_Line("== Temperature Converter Listing ==");
		Ada.Text_IO.Put_Line("");
		Ada.Text_IO.Put_Line(">> Small application for listing temperature in Celcius, Reaumur, and Fahrenheit");
		Ada.Text_IO.Put_Line("");
		Ada.Text_IO.Put_Line("> Credit:");
		Ada.Text_IO.Put_Line("- Coded by (aka in cyber) Vsio Stitched.");
		Ada.Text_IO.Put_Line("- Problem case inspired from >> http://www.cprogramming.com/challenges/celsius_converter_table.html << ");
		Ada.Text_IO.Put_Line("");
		Ada.Text_IO.Put_Line("------------------------------------");
		Ada.Text_IO.Put_Line("");
		Ada.Text_IO.Put_Line("");

	end HeaderText;
		
	procedure Main is

		lower : Integer := -1;
		higher : Integer := -1;
		step : Integer := -1;
		maxStep : Integer;
		
		tempC : Float; 
		tempR : Float;
		tempF : Float;

		begin

			-- lower

			while lower < LOWER_LIMIT or lower > HIGHER_LIMIT loop
				Ada.Text_IO.Put("Please give in a lower limit, limit >=" &integer'image(LOWER_LIMIT)& " and limit <=" &integer'image(HIGHER_LIMIT)& " : ");
				Ada.Integer_Text_IO.Get(lower);
				
				if lower < LOWER_LIMIT then
					Ada.Text_IO.Put_Line("invalid input: 'lower limit' input is lower than" &integer'image(LOWER_LIMIT));
				end if;
				
				if lower > HIGHER_LIMIT then
					Ada.Text_IO.Put_Line("invalid input: 'lower limit' input is higher than" &integer'image(HIGHER_LIMIT));
				end if;
				
			end loop;
			
			-- higher
			
			while higher <= LOWER_LIMIT or lower > HIGHER_LIMIT loop
				Ada.Text_IO.Put("Please give in a higher limit," &integer'image(lower)& "> limit <=" &integer'image(HIGHER_LIMIT)&" : ");
				Ada.Integer_Text_IO.Get(higher);
				
				if higher <= lower then
					Ada.Text_IO.Put_Line("invalid input: 'higher limit' input is equal or lower than" &integer'image(lower));
				end if;
				
				if higher > HIGHER_LIMIT then
					Ada.Text_IO.Put_Line("invalid input: 'higher limit' input is higher than" &integer'image(HIGHER_LIMIT));
				end if;
				
			end loop;
			
			-- step
			
			maxStep := higher - lower;
			
			while step <= 0 or step > maxStep loop
			
				Ada.Text_IO.Put("Please give in a step, 0 < step <="&integer'image(maxStep)&" : ");
				Ada.Integer_Text_IO.Get(step);
				
				if step <= 0 then
					Ada.Text_IO.Put_Line("invalid input: 'step' input is equal or lower than 0");
				end if;
				
				if step > maxStep then
					Ada.Text_IO.Put_Line("invalid input: 'step' input is higher than" &integer'image(maxStep));
				end if;
			
			end loop;
			
			-- Print
			
			tempC := Float(lower);
			
			Ada.Text_IO.Put_Line("");
			
			Ada.Text_IO.Put("  Celcius");
			Ada.Text_IO.Put(TAB);
			Ada.Text_IO.Put("  Reaumur");
			Ada.Text_IO.Put(TAB);
			Ada.Text_IO.Put_Line("  Fahrenheit");
			Ada.Text_IO.Put_Line("");
			
			Ada.Text_IO.Put("  -------");
			Ada.Text_IO.Put(TAB);
			Ada.Text_IO.Put("  -------");
			Ada.Text_IO.Put(TAB);
			Ada.Text_IO.Put_Line("  ----------");	
			Ada.Text_IO.Put_Line("");
			
			while tempC < Float(higher) loop		
				
				tempF := Float( ( tempC * Float(9)) / Float(5) ) + Float(32);
				tempR := Float( ( tempC * Float(4)) / Float(5) );
				Ada.Float_Text_IO.Put(tempC, Fore=>5, Aft=>3, Exp=>0);
				Ada.Text_IO.Put(TAB);
				Ada.Float_Text_IO.Put(tempR, Fore=>5, Aft=>3, Exp=>0);
				Ada.Text_IO.Put(TAB);
				Ada.Float_Text_IO.Put(tempF, Fore=>5, Aft=>3, Exp=>0);
				Ada.Text_IO.New_Line;
				tempC := tempC + Float(step);
			
			end loop;
			
	end Main;
			
end TemperatureConverterListing;