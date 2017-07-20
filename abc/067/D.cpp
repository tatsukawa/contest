#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;

int dfs() {

}

int main() {
    int N;
    cin >> N;

    G.assign(N, vector<int>());

    int x, y;
    for(int i = 0; i < N-1; i++) {
        cin >> x >> y;
        x--, y--;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    queue<int> q1, q2, tmp;

    q1.push(0);
    q2.push(N-1);

    vector<bool> used(N, false);

    int fen = 0, snu = 0;

    bool turn = true;
    while(true) {
        if(fen + snu == N) {
            break;
        }
        if(turn) {
            while(!q1.empty()) {
                fen++;
                int v = q1.front();
                used[v] = true;
                q1.pop();

                for(int u : G[v]) {
                    if(used[u]) continue;
                    used[u] = true;
                    tmp.push(u);
                } 
            }
            while(!tmp.empty()) {
                q1.push(tmp.front());
                tmp.pop();
            }
        } else {
            while(!q2.empty()) {
                snu++;
                int v = q2.front();
                used[v] = true;
                q2.pop();

                for(int u : G[v]) {
                    if(used[u]) continue;
                    used[u] = true;
                    tmp.push(u);
                } 
            }
            while(!tmp.empty()) {
                q2.push(tmp.front());
                tmp.pop();
            }

        }

        turn = !turn;
    }

    fen--, snu--;

    if(fen > snu) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl; 
    }
} 