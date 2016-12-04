#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl

#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort((x).begin(), (x).end())
#define REVERSE(x) reverse( (x).begin(),(x).end())
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define PW(x) (1LL<<(x))

using namespace std;
using ll = int64_t;
using P = pair<int, int>;

template<class T,class U>
ostream& operator<<(ostream &os, const pair<T, U> &p) {
    os << get_variable_name(p) << " = (" << p.first <<", " << p.second << ")";
    return os;
}

template<class T>
ostream& operator <<(ostream& os, const vector<T> &v){
    cout << get_variable_name(v) << " = [";
    for(auto i : v) 
        os << " " << i;
    os << " ]";
    return os;
}


const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);

    vector<int> p(3);
    for(int i = 0; i < 3; i++) cin >> p[i];

    sort(ALL(p));

    if(p[0]+p[1] == p[2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

