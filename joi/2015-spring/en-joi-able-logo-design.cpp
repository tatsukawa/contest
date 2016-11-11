#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

const int M = 1e7;
ll J[M];
ll O[M];
ll I[M];

int main() {
    ios::sync_with_stdio(false);

    int K;
    string s;
    cin >> K;
    cin >> s;

    J[0] = (s[0] == 'J');
    O[0] = (s[0] == 'O');
    I[0] = (s[0] == 'I');

    for(int i = 1; i < 2*(1 << (2*K)); i++) {
        J[i] += J[i-1] + (s[i%(1<<(2*K))] == 'J');
        O[i] += O[i-1] + (s[i%(1<<(2*K))] == 'O');
        I[i] += I[i-1] + (s[i%(1<<(2*K))] == 'I');
//        printf("%d, %d, %d\n", J[i], O[i], I[i]);
    }

    int ans = 1e8;

    for(int i = 0; i < (1 << (2*K)); i++) {
        int sum = 0;
        int head = i;
        for(int level = K-1; level >= 0; level--) {
            for(int j = 0; j < 3; j++) {
                int end = head+(j+1)*(1<<(2*level));
                int begin = head+j*(1<<(2*level));
                int val = (1<<(2*level));
                if(j == 0) { // J
                    sum += val - (J[end] - J[begin]);
                }
                if(j == 1) { // O
                    sum += val - (O[end] - O[begin]);
                }
                if(j == 2) { // I
                    sum += val - (I[end] - I[begin]);
                }
            }
            head += 3*(1<<(2*level));
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;
}

