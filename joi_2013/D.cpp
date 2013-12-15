#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MOD = 10007;

// J = 0bit, O = 1bit, I = 2bit
// i日目, 参加した人(bit表現)
int dp[1001][12];

int main() {
	map<char, int> D;
	D['J'] = 0, D['O'] = 1, D['I'] = 2;
	int N, ans = 0;
	string S;

	cin >> N >> S;

	for(int i = 0; i < 1 << 3; i++) {
		if(((i >> D[S[0]]) & 1) && ((i >> D['J']) & 1)) {
			dp[0][i] = 1;
		}
	}

	for(int i = 1; i < N; i++) {
		for(int j = 0; j < 1 << 3; j++) {
			for(int k = 0; k < 1 << 3; k++) {
				for(int l = 0; l < 3; l++) {
					if((k >> D[S[i]] & 1) && ((k >> l) & 1) && ((j >> l) & 1))
					{
						dp[i][k] += dp[i-1][j];
						dp[i][k] %= MOD;
						break;
					}
				}
			}
		}
	}

	for(int i = 0; i < 1 << 3; i++) {
		ans += dp[N-1][i];
		ans %= MOD;
	}

	cout << ans << endl;
}

