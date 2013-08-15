#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class MovingAvg {
public:
    double difference(int k, vector<double> data) {
        double sum = accumulate(&data[0], &data[k], 0.0);
        double min_avg = sum, max_avg = sum;

        for(int i = k; i < data.size(); i++, min_avg = min(min_avg, sum), max_avg = max(max_avg, sum))
            sum += (data[i] - data[i - k]);

        return (max_avg - min_avg) / k;
    }
};
