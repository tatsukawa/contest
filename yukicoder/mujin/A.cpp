#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;
const ll MOD = 1e9 + 7;

vector<pair<int, int>> p;
int N;

bool check(vector<bool> &w, int index) {
    int cnt = 0;
    int width = p[0].first - 1;
    for(int i = 0; i < N; i++, width += p[i].first - p[i-1].first - 1) {
        if(cnt == 2) return false;
        if(w[p[i].second]) {
            width++;
            continue;
        }
        if(p[i].second == index) {
            return true;
        }
        if(width == 0) {
            cnt++;
        } else {
            width--;
        }
    }
    return false;
}

int main() {
    cin >> N;
    vector<int> x(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i];
        p.emplace_back(make_pair(x[i], i));
    }


    ll ans = 1; 
    for(int i = 0; i < N; i++) {
        ans *= (i+1);
        ans %= MOD;
    }

    cout << ans << endl;
}