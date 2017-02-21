#define DEBUG false

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
    mt19937_64 mt;
    uniform_real_distribution<double> random_gen;

    vector<string> remove_dots(vector<string> b);
    int _count(vector<string>& b, int y, int x);
    int count(vector<string>& b);
    bool can_access(int y, int x);

public:

    Board() : size(0), board(vector<string>()), output_board(vector<string>()), rand_device() {
        mt = mt19937_64(rand_device());
        random_gen = uniform_real_distribution<double>(0.0, 1.0);
    }

    void input() {
        string s;
        size = 0;
        while (cin >> s) {
            board.emplace_back(s);
            output_board.emplace_back(s);
            size++;
        }
    }

    void output() {
        for (auto &s : output_board) {
            cout << s << endl;
        }
    }

    void solve();

    void debug(vector<string> &b) {
#if DEBUG
        cout << "[DEBUG BEGIN]" << endl;
        for(int i = 0; i < size; i++) {
            cout << b[i] << endl;
        }
        cout << "[DEBUG END]" << endl;
#endif
        return;
    }
};

vector<string> Board::remove_dots(vector<string> b) {
    for(int x = 0; x < size; x++) {
        int y = size - 1;
        while(y >= 0) {
            if(b[y][x] == '.') {
                int tail = 0;
                for(int yy = y-1; yy >= 0; yy--) {
                    if(b[yy][x] == '-') {
                        tail = yy+1;
                        break;
                    } else {
                        b[yy+1][x] = b[yy][x];
                    }
                }
                b[tail][x] = '#';
            } else {
                y--;
            }
        }
    }
    return b;
}

bool Board::can_access(int y, int x) {
    return (0 <= y and y < size and 0 <= x and x < size);
}

int Board::_count(vector<string>& b, int y, int x) {
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

int Board::count(vector<string>& b) {
    memset(used, 0, sizeof(used));
    int o = 0, x = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(used[i][j]) continue;
            if(b[i][j] == 'o') {
                o = max<int>(o, _count(b, i, j));
            }
            if(b[i][j] == 'x') {
                x = max<int>(x, _count(b, i, j));
            }
        }
    }
#if DEBUG
//    cout << o << ", " << x << endl;
#endif
    return o + x;
}

void Board::solve() {
    int beam_width = 30;
    int compute_count = 20;
    int max_step = 70;

    double p_plus = 0.4;
    double p_minus = 0.7;

    vector<string> tmp;
    vector<vector<string>> boards(beam_width * compute_count, std::vector<string>(size));
    vector<pair<int, int>> scores(beam_width * compute_count);
    vector<vector<string>> bs(beam_width, vector<string>(size));
    uniform_int_distribution<int> rand_i(0, size - 1);

    for(int i = 0; i < beam_width; i++) {
        bs[i] = board;
    }

    for(int step = 0; step < max_step; step++) {
        for(int beam_index = 0; beam_index < beam_width; beam_index++) {
            for(int compute_cnt = 0; compute_cnt < compute_count; compute_cnt++) {
                int index = beam_index * compute_count + compute_cnt;
                auto& brd = boards[index];
                brd = bs[beam_index];

                if(compute_cnt != 0) {
                    int i = size - rand_i(mt) % (size / 5) - 1;
                    for(int j = 0; j < size; j++) {
                        if(not (brd[i][j] == 'o' or brd[i][j] == 'x')) {
                            double p = random_gen(mt);

                            if(p < p_plus) {
                                brd[i][j] = '+';
                            } else if(p < p_minus) {
                                brd[i][j] = '-';
                            } else {
                                brd[i][j] = '.';
                            }
                        }
                    }
                }
                tmp = remove_dots(brd);
                int score = count(tmp);
                scores[index] = {score, index};
            }
        }

        sort(scores.begin(), scores.end(), greater<pair<int, int>>());

#if DEBUG
        cout << "score: " << scores[0].first << ", index: " << scores[0].second << endl;
#endif

        for(int i = 0; i < beam_width; i++) {
            bs[i] = boards[scores[i].second];
        }
    }

    output_board = bs[0];
}

int main()
{
    Board b;
    b.input();
    b.solve();
    b.output();
}
