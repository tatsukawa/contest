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

double R, N, M;

double f(double d) {
    if(R*R - d*d < 0) return 0;
    return sqrt(R*R - d*d);
}

int main() {
    ios::sync_with_stdio(false);

    cin >> R >> N >> M;

    double dx = (2.0*R) / N;
    double x, y;
    double ans = 0;

    bool used[2000];
    
    memset(used, 0, sizeof used);

    int l;

    for(l = (N-1)/2; l > 0; l--) {
        if(used[l] or used[l+(int)M]) {
            break;
        }
        x = f(R-dx*l);
        y = f(R-dx*(l+M));

        used[l] = true;
        used[l+(int)M] = true;

        ans += 2*max(y,x);
    }

    int r;

    for(r = l+M+1; r < N; r++) {
        if(!used[r]) {
            break;
        }
    }
    cout << r << ' ' << l << endl;

    while(0 < l or r < N) {
        used[l] = used[r] = true;
        dx = (2.0*R) / N;
        ans += 2*max(f(R-dx*l), f(R-dx*r));
        r++, l--;
    }

    for(int i = 1; i < N; i++) {
        if(!used[i]) {
            dx = (2.0*R) / N;
            ans += 2*f(R-dx*i);
        }
    }

    printf("%.10f\n", ans);
}
