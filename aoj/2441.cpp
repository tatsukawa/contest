#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

ll index(ll n) {
    // 最初に包除原理するんじゃなくて，桁を上げていって伝搬させると良い．DPみたいな感じ
    ll a = n / 15LL;
    ll b = n / 5LL - a;
    ll c = n / 3LL - a;
    ll d = n - a - b - c;
  
    ll m = n; 
    // 255452 => 1-9 + 10 - 99 + 100 - 999 + 1000 + 9999 + 10000 + 99999 + 100000 - 255452
    ll length = 0LL;
    for(ll digit = 10LL, ll l = 1LL; ; digit *= 10LL, l++) {
        if(m / digit == 0) {
            length += l * (m - digit / 10LL);
            break;
        } else {
            length += (digit * 10 - digit - (l == 1 ? 0 : 1)) * l;
        }
    } 

    length += 

}

int main() {
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    // TODO
}

