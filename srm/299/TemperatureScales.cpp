using namespace std;

class TemperatureScales {
public:
    double convert(int f1, int b1, int f2, int b2, int t) {
        return 1.0 * (t - b1) * (f2 - b2) / (f1 - b1) + b2;
    }
};
