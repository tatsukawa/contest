#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;

    int cnt = INF;

    for(int i = 0; i < N; i++) {
        int x = i;
        for(int j = 0; j < N - i; j++) {
            if(s[i+j] != t[j]) {
                x += (N - (i + j));
                x += N - i;
                break;
            }
            x++;
        }
        x += N - (N - i);
        cnt = min(x, cnt);
    }

    cout << cnt << endl;

}

