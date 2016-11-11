#include <bits/stdc++.h>

using namespace std;

bool prime[10000000];
const int m = 1e9;
int main() {
    vector<int> v, ans;
    for(int i = 2; i*i < 100000000; i++) {
        if(prime[i]) continue;
        v.push_back(i);
        if(v.size() == 100) break;
        for(int j = i*2; j < 10000000; j+=i) {
            prime[j] = true;
        }
    }

    int c = 0;
    int n = m;
    while(c < 100) {
        if(n % v[v.size() - c - 1] == 0) {
            cout << n << endl;
            c++;
        }
        n--;
    }
}
