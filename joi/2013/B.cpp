#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 1 << 30;

int main() {
	int n, m, a;
	vector<int> A;
	cin >> n >> m;
	vector<int> B(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> a;
		A.push_back(a);
	}

	for(int i = 0; i < m; i++) {
		int p = -1;
		cin >> a;
		for(int j = 0; j < n; j++) {
			if(a >= A[j]) {
				p = j;
				break;
			}
		}

		B[p]++;
	}

	int ans = -1;
	a = 0;

	for(int i = 0; i < n; i++) {
		if(a < B[i]) {
			ans = i;
			a = B[i];
		}
	}

	cout << ans+1 << endl;
}

