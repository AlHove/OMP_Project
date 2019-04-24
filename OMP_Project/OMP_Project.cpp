/* Alyssa Hove and Katheryn Weeden
Monte Carlo Simulation with OMP
Due 4/12/19 at 19:00 pm
*/

#include <iostream> // for IO
#include <string> // for strings
#include <random> // random
#include <stdio.h> // printf
#include <stdlib.h>  
#include <ctime> //time
#include <omp.h>
#include <cstdlib>
#include <chrono>
#include <windows.h>
using namespace std;
using namespace std::chrono;

double f(double x) { // current test y = x
	return x;
}

int main() 
{
	int t;
	double b = 0.0; // initialize b with 0
	double area, h , m, n, x, y;

	// Input height value
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
	uniform_real_distribution<> disX(m,n);
	uniform_real_distribution<> disY(0.0, h);
	// End
	
	auto start = high_resolution_clock::now();
//#pragma omp parallel for private(i)
		for (int i = 0; i < t; i++) {
			x = disX(rd);
			x = f(x);
			y = disY(rd);
//#pragma omp critical
			if (y <= x) 
			{
				b++;
			}
		}
	area = (b / t) * (h*(n - m));
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Program ran in " << duration.count() << " microseconds" << endl;
	cout << "The area is: " << area << endl;
}

/*
with omp:
Please Input Value m
0
Please Input Value n
2
Please Input Value for the amount of tests.
100000
Program ran in 73682 microseconds
The area is: 2.00592
w/o omp:
Please Input Value m
0
Please Input Value n
2
Please Input Value for the amount of tests.
100000
Program ran in 88957 microseconds
The area is: 1.9968

OMP is about 18% faster
*/

