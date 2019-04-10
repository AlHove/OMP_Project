/* Alyssa Hove and Katheryn Weeden


since we do not know what a f(x) would be lets use h until further notice/ explanaition
can talk to camanga tomorrow

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

void main() {
	int totalThreads;
	int maxThreads = 7;
	int start, b, t, m, n, h;
	double x, y;

	srand(static_cast <unsigned int> (time(0))); // initialize rand

	printf("\Please Input Value m\n");
	cin >> m;
	printf("\Please Input Value n\n");
	cin >> n;
	while (n < m) {
		printf("\Sorry please input a value that is greater than m\n");
		cin >> n;
	}
	printf("Please Input Value for the height of your rectangle, h");
	cin >> h;

	start = GetTickCount();

#pragma omp parallel num_threads (maxThreads) 
	{
		x = rand() % n + m;
		y = rand() % h;
	}
#pragma omp parallel


#pragma omp critical


}