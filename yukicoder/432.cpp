#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

int f(string S) {
    int K = S.size();
    vector<int> tmp(K);
    vector<int> tmp2(K);

    for(int i = 0; i < K; i++) {
        tmp2[i] = S[i] - '0';
    }

    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K - i; j++) {
            tmp[j] = tmp2[j];
        }
        for(int j = 0; j < K - i - 1; j++) {
            tmp2[j] = tmp[j] + tmp[j+1];
            if(tmp2[j] >= 10) {
                tmp2[j] = (tmp2[j] % 10) + 1;
            }
        }
    }

    return tmp2[0];
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    string S;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> S;
        cout << f(S) << endl;
    }
}

