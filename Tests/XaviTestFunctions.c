/*
 * XaviTestFunctions.c: Program to test Xavi's function-calling code.
 * Copyright 2012 Vincent Damewood
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include "XaviFunctionCall.h"

static int IsNumber(XaviNumber n) {
	return n.status == S_INTEGER || n.status == S_FLOAT;
}

int main()
{
	XaviNumber inputs[1]; // Arguments to functions.
	XaviNumber value;     // Return value of function.
	int total = 0;    // Total number of tests run.
	int success = 0;  // Number of successful tests.

	////////////////////////////////////////////////////////////////////
	
	printf("Test 1: abs(-400) returns 400... ");
	inputs[0].status = S_INTEGER;
	inputs[0].i = -400;
	total++;
	value = XaviFunctionCall("abs", 1, inputs);
	if (value.status == S_INTEGER && value.i == 400) {
		printf("success.\n");
		success++;
	}
	else if (value.status == S_FLOAT) {
		printf("failed. Value returned was: %c %i %f",
			   value.status, value.i, value.f);
	}
	else {
		printf("failed. Error code returned.\n");
	}

	////////////////////////////////////////////////////////////////////
	
	// Summary	
	printf("Tests passed/run: %d/%d\n"
		   "Percentage:       %06.2f\n",
		   success, total, ((float) success / (float) total) * 100.00);
	return total - success;
}