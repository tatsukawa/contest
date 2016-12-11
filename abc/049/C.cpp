#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl
#define rep(i, begin, end) for(int (i) = (begin); (i) < (end); (i)++)

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

string pattern[] = {"remaerd", "resare", "maerd", "esare"};

string solve(const string& s) {
    int cur = 0;
    while(cur < s.size()) {
        bool ok = false;
        for(auto p : pattern) {
            string t = s.substr(cur, p.size());
            if(t == p) {
                ok = true;
                cur += p.size();
                break;
            }
        }
        if(!ok) return "NO";
    }
    return "YES";
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    cout << solve(s) << endl;
}

