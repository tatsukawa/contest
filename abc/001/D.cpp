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

//24*60=1440
//max = 1440+60 = 1500

int x[1600];

int f(int t) {
    int h = t/100;
    int m = t%100;
    return (h*60+m)/5*5;
}

void g(int t) {
    int m = t % 60;
    t -= m;
    t /= 60;
    printf("%02d%02d", t, m);
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    int s, t;
    char c;
    cin >> n;
    rep(i,0,n) {
        cin >> s >> c >> t;
        x[f(s)]++; x[f(t+4)]--;
    }
    bool ok = false;
    rep(i,0,1600) {
        if(i != 0) {
            x[i] += x[i-1];
        }
        if(x[i] > 0 and ok == false) {
            ok = true;
            g(i);
            printf("-");
        }
        if(x[i] == 0 and ok == true) {
            ok = false;
            g(i);
            printf("\n");
        }
    }
}

