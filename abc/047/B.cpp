#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)

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
    int W, H, N;
    cin >> W >> H >> N;
    int min_x = 0, min_y = 0, max_x = W, max_y = H;
    int x, y, a;
    rep(i, N) {
        cin >> x >> y >> a;
        switch(a) {
            case 1:
                min_x = max(min_x, x);
                break;
            case 2:
                max_x = min(max_x, x);
                break;
            case 3:
                min_y = max(min_y, y);
                break;
            case 4:
                max_y = min(max_y, y);
                break;
        }
    }

    int h = max_y-min_y;
    int w = max_x-min_x;
    if(h < 0 or w < 0) {
        cout << 0 << endl;
    } else {
        cout << h*w << endl;
    }
}

