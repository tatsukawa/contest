#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;
const int INF = 1e8;

struct Team {
    int s, p, u;
    int index;
    int rank;

    Team(int _s, int _p, int _u, int _index) {
        s = _s;
        p = _p; u = _u;
        index = _index;
    }

    bool operator<(const Team &x) const {
        if(x.s > s) {
            return false;
        } 

        if(x.s < s) {
            return true;
        }

        if(x.s == s) {
            if(x.rank > rank) {
                return true;
            }
            if(x.rank < rank) {
                return false;
            }
            if(x.rank == rank) {
                if(x.p < p) {
                    return false;
                } else {
                    return true;
                }
            }
        }

        return false;

    }

    void print() {
        cout << s << ' ' << u << ' ' << p << ' ' << index << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int N, K;
    int S, P, U;
    cin >> N >> K;
    vector<Team> v;
    vector<int> name;
    map<int, int> conv;


    for(int i = 0; i < N; i++) {
        cin >> S >> P >> U;
        v.emplace_back(Team(S, P, U, i));
        name.emplace_back(U);
    }
    
    sort(name.begin(), name.end());
    name.erase(unique(name.begin(), name.end()), name.end());

    for(int i = 0; i < name.size(); i++) {
        conv[name[i]] = i;
    }

    vector<Team> w[name.size()];
    for(int i = 0; i < N; i++) {
        w[conv[v[i].u]].push_back(v[i]);
    }

    priority_queue<Team, std::vector<Team>> queue;
    
    for(int i = 0; i < name.size(); i++) {
        sort(w[i].begin(), w[i].end());
        for(int j = 0; j < w[i].size(); j++) {
            w[i][j].rank = j;
            queue.push(w[i][j]);
        }
    }

    vector<int> ans;

    while(!queue.empty()) {
        ans.emplace_back(queue.top().index);
        queue.pop();
    }

    reverse(ans.begin(), ans.end());

    for(int i = 0; i < K; i++) {
        cout << ans[i] << endl;
    }
}

