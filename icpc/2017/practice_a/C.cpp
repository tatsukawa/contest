#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        if(N == 0 and M == 0) {
            break;
        }
        int S, k;
        vector<int> min_points(N, 0);
        vector<int> max_points(N, 0);

        for (int i = 0; i < M; i++)
        {
            cin >> S >> k;
            vector<int> c(k);
            for (int j = 0; j < k; j++)
            {
                cin >> c[j];
                c[j]--;
                max_points[c[j]] += S;
            }
            if (k == 1)
            {
                min_points[c[0]] += S;
            }
        }

        int ans = 0;

        for (int i = 0; i < N; i++)
        {
            int x = max_points[i];

            for (int j = 0; j < N; j++)
            {
                if(i == j) continue;
                ans = max(ans, x - min_points[j] + 1);
            }
        }

        cout << ans << endl;
    }
}