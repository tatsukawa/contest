using namespace std;

class RugSizes {
public:
    int rugCount(int area) {
        int ans = 0;
        for(int i = 1, k = area; i * i <= area; i++, k = area / i) ans += (area % i ? 0 : (k == i ? 1 : (i & 1) | (k & 1)));
        return ans;
    }
};
