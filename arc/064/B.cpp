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
        os << " " << v[i];
    os << " ]";
    return os;
}


const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    bool turn = true;
    
    while(s.size() > 2) {
        bool ok = false;
        for(int i = 1; i+1 < s.size(); i++) {
            if(s[i-1] != s[i+1]) {
                s.erase(i,1);
                ok = true;
                break;
            }
        }

//        cout << ok << ' ' << s << endl;
       
        if(ok) {
            turn ^= 1;
        }

        if(!ok) {
            break;
        }

    }

    if(turn) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
}


