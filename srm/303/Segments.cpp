#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Segments {
public:
    string intersection(vector<int> s1, vector<int> s2) {
        int left = max(min(s1[0], s1[2]), min(s2[0], s2[2]));
        int right = min(max(s1[0], s1[2]), max(s2[0], s2[2]));
        int top = min(max(s1[1], s1[3]), max(s2[1], s2[3]));
        int bottom = max(min(s1[1], s1[3]), min(s2[1], s2[3]));

        if(left > right || top < bottom) return "NO";
        if((top == bottom && left == right) || (right < left && bottom < top)) return "POINT";
        return "SEGMENT";
    }
};
