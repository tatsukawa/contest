#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl
#define rep(i, begin, end) for(int (i) = (begin); (i) < (end); (i)++)

using namespace std;
using ll = int64_t;

int main() {
    ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	bool G[64][64];
	memset(G, 0, sizeof G);
	int a, b;
	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		G[a][b] = 1;
		G[b][a] = 1;
	}

	int ans = 0;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!G[i][j]) continue;
			if(i == j) continue;
			for(int k = 0; k < N; k++) {
				if(!G[j][k]) continue;
				if(i == k or j == k) continue;
				for(int l = 0; l < N; l++) {
					if(!(G[k][l] and G[l][i])) continue;
					if(i == l or j == l or k == l) continue;
					int cnt = 0;
					cnt += G[i][k];
					cnt += G[j][l];
//					printf("%d:%d:%d:%d=%d\n",i,j,k,l,cnt);
					ans += (cnt == 0);
				}
			}
		}
	}

	cout << ans/8 << endl;
}
