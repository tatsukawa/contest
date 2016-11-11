#include <bits/stdc++.h>

using namespace std;

void debug(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main() {
    int N, K, X;
    int a, b;
    char skip;
    vector<pair<int, int>> v;
    cin >> N >> K >> X;

    vector<int> forward;
    vector<int> backward(N);

    for(int i = 0; i < K; i++) {
        if(i == X-1) {
            cin >> skip >> skip;
            v.emplace_back(make_pair(-1, -1));
        } else {
            cin >> a >> b;
            v.emplace_back(make_pair(a, b));
        }
    }

    for(int i = 0; i < N; i++) {
        cin >> backward[i];
        forward.emplace_back(i+1);
    }

    // back
    for(int i = K-1; i >= X; i--) {
        a = backward[v[i].first - 1];
        backward[v[i].first - 1] = backward[v[i].second - 1];
        backward[v[i].second - 1] = a;
    }

    // forward
    for(int i = 0; i < X - 1; i++) {
        a = forward[v[i].first - 1];
        forward[v[i].first - 1] = forward[v[i].second - 1];
        forward[v[i].second - 1] = a;
    }

    vector<int> diff;

    for(int i = 0; i < N; i++) {
        if(forward[i] == backward[i]) continue;
        diff.emplace_back(i);
    }

    cout << diff[0]+1 << ' ' << diff[1]+1 << endl;

}
