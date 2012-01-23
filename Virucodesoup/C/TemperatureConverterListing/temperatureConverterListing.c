/* ===========================
File : temperatureConverterListing.c

Credit:
- Coded by (aka in cyber) Vsio Stitched.
- Problem case inspired from >> http://www.cprogramming.com/challenges/celsius_converter_table.html

License:
- Free to use
- May include me or not in credit
=========================== */

#include "temperatureConverterListing.h"
#include <stdio.h>

void header() {
	printf("\n== Temperature Converter Listing ==\n");
	
	printf("\n------------------------------------\n\n");
	printf(">> Small application for listing temperature in Celcius, Reaumur, and Fahrenheit\n\n");
	
	printf("> Credit:\n");
	printf("- Coded by (aka in cyber) Vsio Stitched.\n");
	printf("- Problem case inspired from >> http://www.cprogramming.com/challenges/celsius_converter_table.html << \n");
	
	printf("\n------------------------------------\n\n");
}

void driver() {

	int lower = -1; 
	int higher = -1;
	int step = -1;

	while ( (lower < LOWER_LIMIT) || (lower > HIGHER_LIMIT) ) {
		printf("\nPlease give in a lower limit, limit >= %d: and limit <= %d: ",LOWER_LIMIT, HIGHER_LIMIT);
		scanf("%d", &lower);
		
		if (lower < LOWER_LIMIT) {
			printf("\ninvalid input: 'lower limit' input is lower than %d \n \n", LOWER_LIMIT);
		}
		if (lower > HIGHER_LIMIT) {
			printf("\ninvalid input: 'lower limit' input is higher than %d \n \n", HIGHER_LIMIT);
		}
	}

	while ( (higher <= lower) || (higher > HIGHER_LIMIT) ) {
		printf("Please give in a higher limit, %d > limit <= %d: ", lower, HIGHER_LIMIT);
		scanf("%d", &higher);
		
		if (higher <= lower) {
			printf("\ninvalid input: 'higher limit' input is equal or lower than %d \n \n", lower);
		}
		if (higher > HIGHER_LIMIT) {
			printf("\ninvalid input: 'higher limit' input is higher than %d \n \n", HIGHER_LIMIT);
		}
	}

	int maxStep = higher - lower;

	while ( (step <= 0) || (step > maxStep) ) {
		printf("Please give in a step, %d < step <= %d: ", 0, maxStep);
		scanf("%d", &step);
		
		if (step <= 0) {
			printf("\n");
			printf("invalid input: 'step' input is equal or lower than 0 \n \n");
		}
		if (step > maxStep) {
			printf("\n");
			printf("invalid input: 'step' input is higher than %d \n \n", lower);
		}
	}

	// Print 
	
	float tempC = lower;
	float tempR;
	float tempF;
	
	printf("\nCelcius \t Reaumur \t Fahrenheit \n");
	printf("------- \t ------- \t ---------- \n");
	while (tempC < higher) {
		tempF = ( (tempC * 9) / 5 ) + 32;
		tempR = ( (tempC * 4) / 5 );
		printf("\n%f \t %f \t %f", tempC, tempR ,tempF);
		tempC += step;
	}

}