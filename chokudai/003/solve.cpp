#include <bits/stdc++.h>

using namespace std;

class Board {

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {-1, 0, 1, 0};
    bool used[64][64];

    int size;

    vector<string> board;
    vector<string> output_board;

    random_device rand_device;
    mt19937 mt;
    uniform_real_distribution<double> random_gen;

public:

    Board() : size(0), board(vector<string>()), output_board(vector<string>()), rand_device() {
        mt = mt19937(rand_device());
        random_gen = uniform_real_distribution<double>(0.0, 1.0);
    }

    void input() {
        string s;
        size = -1;
        while(cin >> s) {
            board.emplace_back(s);
            output_board.emplace_back(s);
            size++;
        }
    }

    void output() {
        for(auto& s : output_board) {
            cout << s << endl;
        }
    }

    void solve() {
    }

    void debug(vector<string> &b)
    {
        cout << "[DEBUG BEGIN]" << endl;
        for (auto &s : b)
        {
            cout << s << endl;
        }
        cout << "[DEBUG END]" << endl;
    }

private:
    vector<string> remove_dots(vector<string> b) {
        for(int i = size-1; i >= 0; i--) {
            for(int j = 0; j < size; j++) {
                if(b[i][j] != '.') continue;
                for(int k = i-1; k >= 0; k--) {
                    if(b[k+1][j] != '.') break;
                    b[k+1][j] = b[k][j];
                }
                b[0][j] = '#';
                if(b[i][j] == '.') j--;
            }
        }
        return b;
    }

    bool can_access(int y, int x) {
        if(0 <= y and y < size and 0 <= x and x < size);
    }

    int _count(vector<string>& b, int y, int x) {
        used[y][x] = true;
        int res = 0;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!can_access(ny, nx)) continue;
            if(used[ny][nx]) continue;
            if(b[ny][nx] == b[y][x]) {
                res += _count(b, ny, nx) + 1;
            }
        }

        return res;
    }

    int count(vector<string>& b) {
        memset(used, 0, sizeof(used));
        int o = 0, x = 0;
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(used[i][j]) continue;
                if(b[i][j] == 'o') {
                    o = max(o, _count(b, i, j));
                }
                if(b[i][j] == 'x') {
                    x = max(x, _count(b, i, j));
                }
            }
        }
        return o + x;
    }

    int validate(vector<string> b) {
        auto rb = remove_dots(b);
        return count(rb);
    }

};

int main()
{
    Board b;
    b.input();
    b.solve();
    b.output();
}
