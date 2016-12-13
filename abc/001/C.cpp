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

string f(double dir) {
    const vector<string> d = {"NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};
    const double e = 11.25;
    dir /= 10.0;
    for(int i = 1, j = 0; (i+2)*e < 360.0; i += 2, j++) {
        if(i*e <= dir and dir < (i+2)*e) {
            return d[j];
        }
    }
    return "N";
}

int g(double w) {
    const vector<int> d = {0, 3, 16, 34, 55, 80, 108, 139, 172, 208, 245, 285, 327};
    w /= 60.0;
    int ww = round(w*10);
    for(int i = 0; i < d.size() - 1; i++) { 
        if(d[i] <= ww and ww <= d[i+1]-1) {
            return i;
        }
    }
    return 12;
}

int main() {
    ios::sync_with_stdio(false);
    double dir, w;
    cin >> dir >> w;
    if(g(w) == 0) {
        cout << "C" << ' ' << 0 << endl;
    } else {
        cout << f(dir) << ' ' << g(w) << endl;
    }
}

