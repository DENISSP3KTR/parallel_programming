#include <iostream>
#include <fstream>
#include <string>
#include <omp.h>
#include <vector>
#define THREAD_NUM 8
using namespace std;

int main()
{
	string str;
	ifstream input("input.txt");
	int count = 0;
	int p = 0;
	while (getline(input, str)) {
		count++;
	}
	input.close();
	vector<int> x;
	vector<int> y;
	vector<int> z;
	ifstream input2("input.txt");
	int n;
	while (input2 >> n) {
		if (p % 3 == 0) x.push_back(n);
		if (p % 3 == 1) y.push_back(n);
		if (p % 3 == 2) z.push_back(n);
		p++;
	}
	input2.close();
	int sumX = 0, sumY = 0, sumZ = 0;
	int i = 0;
#pragma omp parallel for shared(x,y,z) private(i) reduction(+:sumX, sumY, sumZ)
		for (i = 0; i < count; i++) {
			sumX += x[i];
			sumY += y[i];
			sumZ += z[i];
		}
		cout << (sumX + sumY + sumZ) / 3 * count << endl;

	sumX = 0, sumY = 0, sumZ = 0;
#pragma omp parallel
	{
#pragma omp critical (first)
		{
			for (i = 0; i < count; i++) {
				sumX += x[i];
				cout << 1 << endl;
			}
		}
#pragma omp critical (second) 
		{
			for (i = 0; i < count; i++) {
				sumY += y[i];
				cout << 2 << endl;
			}
		}
#pragma omp critical (third) 
		{
			for (i = 0; i < count; i++) {
				sumZ += z[i];
				cout << 3 << endl;
			}
		}
	}
	cout << sumX << " " << sumY << " " << sumZ << endl;
	cout << (sumX + sumY + sumZ) / 3 * count << endl;
	return 0;
}