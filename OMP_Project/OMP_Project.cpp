/* Alyssa Hove and Katheryn Weeden

*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <omp.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

void main(){
	int totalThreads;
	int maxThreads = 7;
	int m;
	int n;
	int h;
	int start;

	printf("\Please Input Value m\n");
	cin >> m;
	printf("\Please Input Value n\n");
	cin >> n;
	while (n<m) {
		printf("\Sorry please input a value that is greater than m\n");
		cin >> n;
	}
	printf("Please Input Value h");
	cin >> h;
    
	start = GetTickCount();
#pragma omp parallel num_threads (maxThreads) 
	{
		
#pragma omp parallel


#pragma omp critical
			
			
#pragma omp critical
			
		}
	}