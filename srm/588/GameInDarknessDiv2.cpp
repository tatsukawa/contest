#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <cstring>

using namespace std;

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

struct Point {
    int x, y;
    Point(int y = 0, int x = 0) : x(x), y(y) {}
};

Point operator+(Point a, Point b) { return Point(a.y + b.y, a.x + b.x); }

Point& operator+=(Point& a, Point b) { a.x += b.x; a.y += b.y; return a; }

bool operator==(Point& a, Point b) { return (a.x == b.x && a.y == b.y); }

class GameInDarknessDiv2 {
    bool used[2][51][51];
    int maxX, maxY;
    string M;
    map<char, Point> move;

public:
    string check(vector<string> field, vector<string> moves) {
        Point a;
        init(field, a);

        M = accumulate(moves.begin(), moves.end(), string(""));

        for(int i = 0; i < M.size(); i++) {
            a += move[M[i]];
            used[i & 1][a.y][a.x] = false;

            for(int y = 0; y < maxY; y++) for(int x = 0; x < maxX; x++)
                used[(i + 1) & 1][y][x] = false;

            for(int y = 0; y < maxY; y++) for(int x = 0; x < maxX; x++) {
                if(!used[i & 1][y][x]) continue;

                for(int j = 0; j < 4; j++) {
                    Point p = Point(y, x) + move["DRUL"[j]];
                    if(!isInField(p)) continue;
                    if(field[p.y][p.x] == '#') continue;
                    if(p == a) continue;
                    used[(i + 1) & 1][p.y][p.x] = true;
                }
            }
        }

        for(int y = 0; y < maxY; y++) for(int x = 0; x < maxX; x++)
            if(used[M.size() & 1][y][x]) return "Bob wins";

        return "Alice wins";
    }

    bool isInField(Point p) { return 0 <= p.x && 0 <= p.y && p.x < maxX && p.y < maxY; }

    void init(vector<string>& field, Point& a) {
        maxX = field[0].size(); maxY = field.size();
        memset(used, 0, sizeof(used));

        for(int i = 0; i < maxY; i++) for(int j = 0; j < maxX; j++) {
            if(field[i][j] == 'A') a = Point(i, j);
            if(field[i][j] == 'B') used[0][i][j] = true;
        }

        for(int i = 0; i < 4; i++) move["DRUL"[i]] = Point(dy[i], dx[i]);
    }
};
