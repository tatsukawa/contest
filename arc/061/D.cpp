#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


map<pair<int, int>, int> cnt;

int main() {
    long long H, W, N, a, b;
    vector<long long> ans(10, 0);
    cin >> H >> W >> N;

    long long sum = (H-2)*(W-2);
    
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        a--, b--;
        for(int i = -2; i <= 0; i++) {
            for(int j = -2; j <= 0; j++) {
                if(i + a >= 0 and j + b >= 0 and i + a < H-2 and j + b < W-2) {
                    cnt[make_pair(i+a, j+b)]++;
                }
            }
        }
    }

    for(auto i = cnt.begin(); i != cnt.end(); i++) {
        ans[i->second]++;
        sum--;
//        cout << i->first.first << ',' << i->first.second << ':' << i->second << endl;
    }
    ans[0] = sum;
    for(auto &i : ans) {
        cout << i << endl;
    }
}
