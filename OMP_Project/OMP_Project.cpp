/* Alyssa Hove and Katheryn Weeden


Do tests with 

y < f(x) <= h
// (b/t) * (h*(n-m))
*/

#include <iostream>
#include <string>
#include <random>
#include <stdio.h> // printf
#include <stdlib.h>  // Rand
#include <ctime> //time
#include <omp.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

double f(double x) { // current test y = x
	return x;
}

int main() 
{
	int start, t;
	double b = 0.0; // initialize b with 0
	double area, h , m, n, x, y;

	// Input values
	h = 2;
	//end

	printf("\Please Input Value m\n");
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

	/* Set Up the Randomizer */
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_real_distribution<> disX(1.0, 2.0);
	uniform_real_distribution<> disY(0.0, h);
	
	start = GetTickCount();

#pragma omp parallel for private(x, y, b, i)
		for (int i = 0; i < t; i++) {
			srand(i); // i is used as seed for more randomizing
			x = disX(rd);
			x = f(x);
			y = disY(rd);
#pragma omp critical
			if (y < x) 
			{
				b++;
			}
		}
	area = (b / t) * (h*(n - m));
	cout << "Program ran in " << GetTickCount() - start << " TickCounts" << endl;
	cout << "The area is: " << area << endl;
}

/*
run with omp: y = x2 m= 1 n=2 h=4
Please Input Value m
1
Please Input Value n
2
Please Input Value for the amount of tests.
100000
Program ran in 78 TickCounts
The area is: 2.3262

run 2: y = x m=1 n=2 h=2
Please Input Value m
1
Please Input Value n
2
Please Input Value for the amount of tests.
10000
Program ran in 16 TickCounts
The area is: 1.5034

run 3: 
Please Input Value m
0
Please Input Value n
2
Please Input Value for the amount of tests.
10000000
Program ran in 7297 TickCounts
The area is: 1.99974

My machine has 8 processors


*/

