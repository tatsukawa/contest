#include <string>

using namespace std;

const int INF = 1 << 30;

class Dating {
    char x[64];
    bool used[64], end;
    int pos, n, c, capital, lower;
    string output;

public:
    string dates(string circle, int k) {
        end = false;
        string ans = "";
        pos = 0, c = k;
        n = circle.size();

        for(int i = 0; i < n; i++) {
            x[i] = circle[i], used[i] = true;
            if('a' <= x[i] && x[i] <= 'z')
                lower++;
            else
                capital++;
        }

        for(int i = 0; i < n / 2; i++) {
            if(!capital || !lower) break;
            if(i != 0) ans += " ";
            char s = decide(pos);
            char couple = search(s);
            ans += s;
            ans += couple;
        }

        return ans;
    }

    char decide(int& pos) {
        int count = 1;
        while(count < c) {
            //printf("%d:%d\n", pos, count);
            if(used[pos]) {
                pos++;
                count++;
                pos %= n;
            } else {
                pos++;
                pos %= n;
            }
        }

        while(!used[pos]) {
            pos++;
            pos %= n;
        }

        used[pos] = false;
        return x[pos];
    }

    char search(char s) {
        char e = 'z' + 1;

        for(int i = 0; i < n; i++) {
            if(used[i])
                if('a' <= s && s <= 'z') {
                    if('A' <= x[i] && x[i] <= 'Z') {
                        if(e > x[i])
                            e = x[i];
                    }
                } else {
                    if('a' <= x[i] && x[i] <= 'z') {
                        if(e > x[i])
                            e = x[i];
                    }
                }
        }

        for(int i = 0; i < n; i++) {
            if(e == x[i]) {
                used[i] = false;
                break;
            }
        }

        capital--, lower--;

        return e;
    }
};
