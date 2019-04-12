/* Alyssa Hove and Katheryn Weeden


Do tests with 

y < f(x) <= h
// (b/t) * (h*(n-m))
*/

#include <iostream>
#include <string>
#include <stdio.h> // printf
#include <stdlib.h>  // Rand
#include <ctime> //time
#include <omp.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

void main() 
{
	int start, b, t, h, m, n;
	double x, y, area;

	// Input values
	b = 0;
	h = 2;
	//end

	cout << "Please Input Value m" << endl;
	cin >> m;
	printf("\Please Input Value n\n");
	cin >> n;
	while (n < m) 
	{
		printf("\Sorry please input a value that is greater than m\n");
		cin >> n;
	}
	printf("\Please Input Value for the amount of tests. \n");
	cin >> t;
	
	start = GetTickCount();


#pragma omp private(i, b, y, x)
	{
		for (int i = 0; i < t; i++) {
			srand(i); // i is used as seed for more randomizing
			cout << (rand() % (m + 1)) << endl;
			// = f(x); // x = f(x) for simplicity and the fact it can be rewritten easily
			y = ((double)rand()*(h - 0) / (double)h - 0);
			if (y < h)
			{
				b++;
			}
		}

		area = (b / t) * (h*(n - m));
	}
	cout << "Program ran in " << GetTickCount() - start << " TickCounts" << endl;
	printf("The area is: %f", area);
}

