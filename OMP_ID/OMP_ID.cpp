/* Alyssa Hove and Katheryn Weeden
 Task 3: A small college wants to know how many id numbers exist that meet these criteria:

1. 6 digits 9^6
2. first digit is non-zero : 8 * (9^5)
3. two consecutive digits may not be the same:
4. sum of the digits may not be 7, 11 or 13

Plan create mulitple threads to run each count, split the into into many 
talk to kruse about simplification if possible
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <omp.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

void main()
{

	int start, total;
	int idNum[5];

	start = GetTickCount();
#pragma omp parallel sections private(idNum[])
	{  
		for (int a = 1; a < 4; a++) {
			for (int b = 0; b < 10; b++) {
				for (int c = 0; c < 10; c++) {
					
					for (int d = 0; c < 10; d++) {

						for (int e = 0; e < 10; e++) {

							for (int f = 0 < 10; e++) {

							}
						}
					}
				}
			}
		}
	}
#pragma omp section
	// thread 2 first digit is not 0
	{
	}
#pragma omp section
	// thread 3 two consecutive 
	{
	}
#pragma omp section
	// thread 4 sum of digits 
	{

	}
#pragma omp critical
	cout << "Program ran in " << GetTickCount() - start << " TickCounts" << endl;
	cout <<
}