#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int N, a, d;
	vector<int> D, A;
	
	cin >> N;
	vector<int> B(N, 0);

	for(int i = 0; i < N; i++) { cin >> d; D.push_back(d); }
	for(int i = 0; i < N; i++) { cin >> a; A.push_back(a); }

	for(int i = 0; i < N; i++) {
		int begin = max(0, i - D[i]);
		int end = min(N, i + D[i] + 1);
		for(int j = begin; j < end; j++) {
			if(i == j) continue;
			B[j] += A[i];
		}
	}

	for(int i = 0; i < N; i++) {
		printf("%3d", B[i]);
	}
}

