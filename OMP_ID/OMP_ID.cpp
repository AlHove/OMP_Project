/* Alyssa Hove and Katheryn Weeden
 Task 3: A small college wants to know how many id numbers exist that meet these criteria:

1. 6 digits done
2. first digit is non-zero  done
3. two consecutive digits may not be the same: done
4. sum of the digits may not be 7, 11 or 13: done

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

int main(void)
{
	int start, total, count;
	int idNum[6] = { 0,0,0,0,0,0 };

	start = GetTickCount();

#pragma omp parallel sections private(idNum[])
	{
		// first thread 100000 - 399999
		idNum[0] = 1;
		int sum = 0;
		int count = 0;
		bool valid;
		while (idNum[0] < 4) {
			valid = true;
			idNum[5]++;
			if (idNum[5] == idNum[4] || idNum[5] == idNum[3]) {
				valid = false;
			}
			if (idNum[4] == idNum[3] || idNum[4] == idNum[2]) {
				valid = false;
			}
			if (idNum[3] == idNum[2] || idNum[3] == idNum[1]) {
				valid = false;
			}
			if (idNum[2] == idNum[1] || idNum[2] == idNum[0]) {
				valid = false;
			}
			if (idNum[5] = 10) {
				idNum[5] = 0;
				idNum[4]++;
			}
			if (idNum[4] = 10) {
				idNum[4] = 0;
				idNum[3]++;
			}
			if (idNum[3] = 10) {
				idNum[3] = 0;
				idNum[2]++;
			}
			if (idNum[2] = 10) {
				idNum[2] = 0;
				idNum[1]++;
			}
			if (idNum[1] = 10) {
				idNum[1] = 0;
				idNum[0]++;
			}
			sum = idNum[0] + idNum[1] + idNum[2] + idNum[3] + idNum[4] + idNum[5];
			if (!((sum == 7) || (sum = 13) || (sum = 11)) && valid) {
				count++;
			}
		}

	}
#pragma omp section // 400000 - 699999
	{
		idNum[0] = 4;
		int sum = 0;
		int count = 0;
		bool valid;
		while (idNum[0] < 7) {
			idNum[5]++;
			if (idNum[5] == idNum[4] || idNum[5] == idNum[3]) {
				valid = false;
			}
			if (idNum[4] == idNum[3] || idNum[4] == idNum[2]) {
				valid = false;
			}
			if (idNum[3] == idNum[2] || idNum[3] == idNum[1]) {
				valid = false;
			}
			if (idNum[2] == idNum[1] || idNum[2] == idNum[0]) {
				valid = false;
			}
			if (idNum[5] = 10) {
				idNum[5] = 0;
			}
			if (idNum[4] = 10) {
				idNum[4] = 0;
				idNum[3]++;
			}
			if (idNum[3] = 10) {
				idNum[3] = 0;
				idNum[2]++;
			}
			if (idNum[2] = 10) {
				idNum[2] = 0;
				idNum[1]++;
			}
			if (idNum[1] = 10) {
				idNum[1] = 0;
				idNum[0]++;
			}
			sum = idNum[0] + idNum[1] + idNum[2] + idNum[3] + idNum[4] + idNum[5];
			if (!((sum == 7) || (sum = 13) || (sum = 11))) {
				count++;
			}
		}

	}
#pragma omp section // 700000 - 999999
	{
		idNum[0] = 7;
		int sum = 0;
		int count = 0;
		bool valid;
		while (idNum[0] < 10) {
			idNum[5]++;
			if (idNum[5] == idNum[4] || idNum[5] == idNum[3]) {
				valid = false;
			}
			if (idNum[4] == idNum[3] || idNum[4] == idNum[2]) {
				valid = false;
			}
			if (idNum[3] == idNum[2] || idNum[3] == idNum[1]) {
				valid = false;
			}
			if (idNum[2] == idNum[1] || idNum[2] == idNum[0]) {
				valid = false;
			}
			if (idNum[5] = 10) {
				idNum[5] = 0;
			}
			if (idNum[4] = 10) {
				idNum[4] = 0;
				idNum[3]++;
			}
			if (idNum[3] = 10) {
				idNum[3] = 0;
				idNum[2]++;
			}
			if (idNum[2] = 10) {
				idNum[2] = 0;
				idNum[1]++;
			}
			if (idNum[1] = 10) {
				idNum[1] = 0;
				idNum[0]++;
			}
			sum = idNum[0] + idNum[1] + idNum[2] + idNum[3] + idNum[4] + idNum[5];
			if (!((sum == 7) || (sum = 13) || (sum = 11))) {
				count++;
			}
		}
#pragma omp critical
		cout << "Program ran in " << GetTickCount() - start << " TickCounts" << endl;
		cout << endl;
	}
}