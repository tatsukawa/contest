#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	int a;
	vector<int> A;
	for(int i = 0; i < 5; i++) {
		cin >> a;
		A.push_back((a >= 40 ? a : 40));
	}
	
	cout << accumulate(A.begin(), A.end(), 0) / 5 << endl;
}

