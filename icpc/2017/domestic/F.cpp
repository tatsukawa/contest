#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int64_t x, y;

    while (cin >> n >> y >> x)
    {
        if(x == 0 and y == 0) {
            break;
        }

        x--, y--;

        int64_t x_l = 1LL;
        int64_t y_l = 1LL;

        for (int i = 0; i < n; i++)
        {
            y_l *= 2LL;
            x_l *= 2LL;
        }

        vector<int64_t> Y(n + 1);
        Y[n] = y_l - y - 1LL;

        for (int i = n - 1; i >= 0; i--, y_l /= 2LL)
        {
            if (y_l / 2LL > Y[i + 1])
            {
                Y[i] = Y[i + 1];
            }
            else
            {
                Y[i] = y_l - Y[i + 1] - 1LL;
            }
        }

        for (int i = 0; i < n; i++, x_l /= 2LL)
        {
            if ((x_l / 2LL) > x)
            {
                if (Y[i + 1] == Y[i])
                {
                    cout << "R";
                }
                else
                {
                    cout << "L";
                    x = x_l / 2LL - x - 1LL;
                }
            }
            else
            {
                if (Y[i + 1] == Y[i])
                {
                    cout << "L";
                    x = x - x_l / 2LL;
                }
                else
                {
                    cout << "R";
                    x = x_l - x - 1LL;
                }
            }
        }

        cout << endl;
    }
}