#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

// TODO: あとで解く
// 思いついた解法は、
// 文字列の先頭からの長さをBITで持っておく
// 途中で挿入したら、挿入した分の文字列の長さを挿入位置から末尾まで足す
// みたいな感じのデータ構造で殴っていけば、O(N log N)で実装できる。
// (なぜなら、N回文字列を分解して、N個分の要素を持つリストができるから。データを取得するときは、要素にある先頭からの文字の長さが単調増加なのを利用して二部探索すればlogが生える)

struct List {
    string s;
    List *next;

    List() {
        s = "";
        next = NULL;
    }

    List(int str, List *n) {
        s = str;
        next = n;
    }

    int size() {
        // TODO:
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int K, M, N, a, b, c;
    string s;
    cin >> K >> M;
    cin >> s;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a >> b >> c;

        // TODO:
    }
}

