#include <algorithm>
#include <cmath>

using namespace std;

class Taxi {
public:
    double maxDis( int maxX, int maxY, int taxiDis ) {
        if(maxX + maxY < taxiDis)
            return -1.0;
        else {
            double ans = 0;
            for(long long i = 0; i <= maxX; i++) {
                if(taxiDis - i > maxY || taxiDis - i < 0) continue;
                double k = sqrt(i * i + (taxiDis - i) * (taxiDis - i));
                ans = max(ans, k);
            }
            return ans;
        }
    }
};
