#include <iostream>

using namespace std;

int main()
{
    int deg, dis; cin >> deg >> dis;

    string dir[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};
    int idx = (deg*10 + 1125) / 2250;

    int w = 12;
    int m[] = {3, 16, 34, 55, 80, 108, 139, 172, 208, 245, 285, 327};
    for(int i = 0; i < 12; i++)
    {
        float t = m[i]*6-3;
        if(dis < t)
        {
            w = i;
            break;
        }
    }

    if(w == 0) cout << "C" << " " << w << endl;
    else cout << dir[idx] << " " << w << endl;
}