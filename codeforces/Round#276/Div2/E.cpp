#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <numeric>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;
int P[2][1 << 20], Q[1 << 20], R[1 << 20];

void make(int v) {
    for(int i = 0; i < N; i++) {
        Q[i] = i;
    }
    for(int i = 0; i < 20; i++) {
        int cur = i & 1, next = cur ^ 1;
        if(v & (1 << i)) {
            for(int j = 0; j < N; j++) R[j] = Q[P[cur][j]];
            for(int j = 0; j < N; j++) Q[j] = R[j];
            v ^= (1 << i);
            if(v == 0) return;
        }
        for(int j = 0; j < N; j++) P[next][j] = P[cur][P[cur][j]];
    }
}

int main() {
    int k, d;
    string s;
    cin >> s;
    N = s.size();

    cin >> M;

    for(int t = 0; t < M; t++) {
        cin >> k >> d;
        // is d-sorting from 0-index to k-index
        for(int i = 0, x = 0; i < d; i++) {
            for(int j = i; j < k; j += d) {
                P[0][j] = (x + (N - 1)) % N;
                x++;
            }
        }
        for(int i = k; i < N; i++) {
            P[0][i] = (i + (N - 1)) % N;
        }

        // doubling 
        make(N - k + 1);

        string S = s;
        for(int i = 0; i < N; i++) S[Q[i]] = s[i];
        for(int i = 0; i < N; i++) s[i] = S[(i + (k - 1)) % N];
        cout << s << endl;
    }
}

