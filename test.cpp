//include
//------------------------------------------
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <complex>

using namespace std;
//container util
//------------------------------------------
#define MP make_pair
#define EACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(c, e) ((c).find(e) != (c).end())

//repetition
//------------------------------------------
#define FOR(i, a, b) for (int i = (a);i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

//IO
//------------------------------------------
#define LF(x) cout << (x) << endl;
#define LFA(a, n) cout << a[0]; FOR(itr, 1, n) {cout << " " << a[itr];} cout << endl;
#define LFP(x, w) cout << setprecision((w)); cout << setiosflags(ios::fixed); cout << (x) << endl;

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INF = (int)1e9;
const int DI[] = {0, 1, 0, -1};
const int DJ[] = {1, 0, -1, 0};

//clear memory
//--------------------------------------------
#define CLR(a) memset((a), 0 , sizeof(a))

//conversion
//------------------------------------------
inline int to_int(string s) {int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string to_str(T x) {ostringstream sout; sout << x; return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
template<class T> inline T is_inner(T x, T a, T b) {return a <= x && x < b;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

struct timer {
    time_t start;
    timer() : start(clock()) {}
    ~timer() { cerr << 1.*(clock() - start) / CLOCKS_PER_SEC << "secs" << endl; }
};

int main() {
    cout << "Hello World" << endl;
}

