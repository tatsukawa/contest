#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Projections {
public:
    vector<int> count(string front, string right) {
        int r = 0, f = 0;
        for(int i = 0; i < front.size(); i++) if(front[i] == 'x') f++;
        for(int i = 0; i < right.size(); i++) if(right[i] == 'x') r++;
        return {max(f, r), f * r};
    }
};
