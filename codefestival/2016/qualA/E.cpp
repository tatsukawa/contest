#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    map<int,int> used;
    vector<int> head(M+1, 0);
    head[1] = M;
    vector<int> a(Q);
    for(int i = 0; i < Q; i++) {
        cin >> a[i];
    }


    if(Q-M >= 0) {
        bool ok = true;
        for(int i = Q-1, j = 1; i >= Q-M; i--, j++) {
            if(j != a[i]) {
                ok = false;
            }
        }

        if(ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    for(int i = 0; i < Q; i++) {
        head[a[i]]--;
        head[a[i]]++;
    }

    for(int i = 1; i <= M; i++) {
        cout << head[i] << endl;
    }
    
    return 0;
}
