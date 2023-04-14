//#include <iostream>
//#include <fstream>
//#include <string>
//#include <omp.h>
//#include <vector>
//#define THREAD_NUM 8
//using namespace std;
//
//int main()
//{
//	string str;
//	ifstream input("input.txt");
//	int count = 0;
//	int p = 0;
//	while (getline(input, str)) {
//		count++;
//	}
//	input.close();
//	vector<int> x;
//	vector<int> y;
//	vector<int> z;
//	ifstream input2("input.txt");
//	int n;
//	while (input2 >> n) {
//		if (p % 3 == 0) x.push_back(n);
//		if (p % 3 == 1) y.push_back(n);
//		if (p % 3 == 2) z.push_back(n);
//		p++;
//	}
//	input2.close();
//	int sumX = 0, sumY = 0, sumZ = 0;
//#pragma omp parallel for
//		for (int i = 0; i < count; i++) {
//			sumX += x[i];
//			sumY += y[i];
//			sumZ += z[i];
//		}
//		sumX /= count;
//		sumY /= count;
//		sumZ /= count;
//		cout << "x=" << sumX << endl;
//		cout << "y=" << sumY << endl;
//		cout << "z=" << sumZ << endl;
//	sumX = 0, sumY = 0, sumZ = 0;
//#pragma omp parallel sections
//	{
//		#pragma omp section 
//		{
//			for (int i = 0; i < count; i++) {
//				sumX += x[i];
//			}
//			sumX /= count;
//		}
//		#pragma omp section 
//		{
//			for (int i = 0; i < count; i++) {
//				sumY += y[i];
//			}
//			sumY /= count;
//		}
//		#pragma omp section 
//		{
//			for (int i = 0; i < count; i++) {
//				sumZ += z[i];
//			}
//			sumZ /= count;
//		}
//		cout << "x=" << sumX << endl;
//		cout << "y=" << sumY << endl;
//		cout << "z=" << sumZ << endl;
//	}
//	return 0;
//}