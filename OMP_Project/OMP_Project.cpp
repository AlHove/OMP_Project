/* Alyssa Hove and Katheryn Weeden

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

void main(){
	int totalThreads;
	int maxThreads = 7;
	int m, n, h, start, x, y, b, t;

	srand(static_cast <unsigned int> (time(0))); // initialize rand

	printf("\Please Input Value m\n");
	cin >> m;
	printf("\Please Input Value n\n");
	cin >> n;
	while (n<m) {
		printf("\Sorry please input a value that is greater than m\n");
		cin >> n;
	}
	printf("Please Input Value for the height of your rectangle, h");
	cin >> h;
    
	start = GetTickCount();
	//rand() % n + m;
	// (b/t) * (h*(n-m))

#pragma omp parallel num_threads (maxThreads) 
	{
		
		
#pragma omp parallel


#pragma omp critical
			
			
		}
	}