#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> v;
    for(auto c : s) {
        v.emplace_back(c - '0');
    }

    queue<pair<int, vector<int>>> que;
    int ans = 0;

    for(que.push(make_pair(0, v)); !que.empty(); que.pop()) {
        auto qu = que.front();
        auto cost = qu.first;
        ans = max(ans, cost);
        auto q = qu.second;
        for(int i = 0; i < q.size(); i++) {
            for(int j = i+1; j < q.size(); j++) {
                for(int k = j+1; k < q.size(); k++) {
                    if(q[i] == 0) {
                        continue;
                    }

                    if(q[i] != q[j] and q[j] == q[k]) {
                        vector<int> w;
                        int c = 100*q[i] + 10*q[j] + 1*q[k];
                        for(int l = 0; l < q.size(); l++) {
                            if(l == i or l == j or l == k) continue;
                            w.emplace_back(q[l]);
                        }
                        que.push(make_pair(cost+c, w));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
