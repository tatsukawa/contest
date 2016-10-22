#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

ll lcm(ll a, ll b) {
    return a*b / __gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);

    string s;
    while(cin >> s) {
        if(s == "#") {
            break;
        }

        vector<int> v;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'n') {
                i += 4;
                v.emplace_back(-90);
            } else {
                i += 3;
                v.emplace_back(90);
            }
        }


        reverse(v.begin(), v.end());
        ll a = v[0];
        ll d = 1;

        if(v[0] == -90) {
            a = 0;
        }

        for(int i = 1; i < v.size(); i++) {
            ll dd = pow(2, i);
            ll x = lcm(dd, d);
            a = a * (x / d) + v[i] * (x / dd);
            d = x; 
            x = __gcd(a, d);
            a /= x;
            d /= x;
        }

        if(d == 1) {
            cout << a << endl;
        } else {
            cout << a << '/' << d << endl;
        }
    }   
}

