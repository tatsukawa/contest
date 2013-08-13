#include <algorithm>

using namespace std;

const int INF = 1e8;

class DivisorInc {
    int dp[100001];

public:
    int countOperations(int N, int M) {
        fill(dp + 0, dp + 100001, INF);
        dp[N] = 0;

        for(int i = N; i < M; i++) {
            if(dp[i] != INF) {
                for(int j = 2; j * j <= i; j++) {
                    if(i % j) continue;
                    int d = i / j;
                    if(i + j <= M) dp[i + j] = min(dp[i + j], dp[i] + 1);
                    if(i + d <= M) dp[i + d] = min(dp[i + d], dp[i] + 1);
                }
            }
        }

        return (dp[M] == INF ? -1 : dp[M]);
    }
};
