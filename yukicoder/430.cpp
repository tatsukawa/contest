#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using P = std::pair<int, int>;

const int INF = 1e8;

const ll B = 100000007;

int cnt(string b, string a) {
   
    int res = 0; 
    int al = a.size();
    int bl = b.size();

    ll t = 1;
    for(int i = 0; i < al; i++) t *= B;

    ll ah = 0, bh = 0;
    for(int i = 0; i < al; i++) ah = ah * B + a[i];
    for(int i = 0; i < al; i++) bh = bh * B + b[i];

    for(int i = 0; i + al <= bl; i++) {
        if(ah == bh) res++;
        if(i + al < bl) bh = bh * B + b[i+al] - b[i] * t;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);

    string S, C;
    int M;
    int ans = 0;
    cin >> S >> M;

    for(int i = 0; i < M; i++) {
        cin >> C;
        ans += cnt(S, C);
    }
    cout << ans << endl;
}

