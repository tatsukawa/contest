#include <algorithm>
#include <sstream>
#include <string>

typedef long long ll;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

using namespace std;

class SpiralNumbers {
public:
    string getPosition(int N) {
        int cur = 0;
        string ans = "";
        ll npos = 1, x = 0, y = 0;

        for(ll i = 8; npos < N; i += 8, x++, y--) npos += i;

        int n = x * 2;

        for(int i = 1; npos != N; i++, npos--) {
            x += dx[cur], y += dy[cur];
            if(n == i) i = 0, cur++;
        }

        return convert(y, x);
    }

    string convert(ll x, ll y) {
        ostringstream oss;
        oss << "(" << x << "," << y << ")";
        return oss.str();
    }
};
