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

double G[1010][1010];


struct B {
    double x, y, r;

    B(double _x, double _y, double _r) :
        x(_x), y(_y), r(_r) {}
};

double dist(B a, B b) {
    double x = a.x - b.x;
    double y = a.y - b.y;
    return sqrt(x*x+y*y);
}

double calc(B a, B b) {
    return max(dist(a, b) - (a.r + b.r), 0.0);
}

int main() {
    ios::sync_with_stdio(false);

    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    int N;
    cin >> N;

    vector<B> v;

    v.emplace_back(sx, sy, 0);
    v.emplace_back(gx, gy, 0);

    double x, y, r;
    for(int i = 0; i < N; i++) {
        cin >> x >> y >> r;
        v.emplace_back(B(x, y, r));
    }

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            G[i][j] = calc(v[i], v[j]);
        }
    }


    for(int k = 0; k < v.size(); k++) {
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v.size(); j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    printf("%.10lf\n", G[0][1]);
}


