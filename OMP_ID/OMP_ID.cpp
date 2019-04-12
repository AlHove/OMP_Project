/* Alyssa Hove and Katheryn Weeden
 Task 3: A small college wants to know how many id numbers exist that meet these criteria:

1. 6 digits done
2. first digit is non-zero  done
3. two consecutive digits may not be the same: done
4. sum of the digits may not be 7, 11 or 13: done

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
	int count = 0;
	int idSet[6] = { 1,0,0,0,0,0 };

	start = GetTickCount();

#pragma omp parallel for private(sum, idSet, i, id, count)
		for (int id = 100000; id < 1000000; id++) 
		{
			int sum = 0;
			bool valid = true;
			for (int i = 5; i > -1; i--)
			{ // goes through idSet array
				sum = idSet[i] + sum; 
				if (idSet[i] > 9) {
					idSet[i] = 0;
					idSet[i - 1] = idSet[i - 1] + 1;
				}
				if (i < 4) {
					if (idSet[i + 2] == idSet[i] || idSet[i + 1] == idSet[i]) {
						valid = false; // set is not valid and should not be counted 
					}
				}
#pragma omp critical 
				if (!(sum == 7 || sum == 11 || sum == 13) && valid && i == 0)
				{
					count = count + 1;
				}
			}
			idSet[5]++;
		}
	cout << "Program ran in " << GetTickCount() - start << " TickCounts" << endl;
	cout << "Count of ids: " << count << endl;
}// end main

/*Run without OMP 
Program ran in 66063 TickCounts
Count of ids: 372102
Run with OMP
Program ran in 47 TickCounts
Count of ids: 372102

My Machine has 8 processors



*/
