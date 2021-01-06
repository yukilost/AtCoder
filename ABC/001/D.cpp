#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N; cin >> N;

    vector<pair<int, int>> p(N);
    for(int i = 0; i < N; i++)
    {
        string str; cin >> str;
        p[i].first = stoi(str.substr(0, 4));
        p[i].second = stoi(str.substr(5, 4));

        p[i].first = p[i].first/5*5;
        p[i].second = (p[i].second+4)/5*5;

        if(p[i].first % 100 == 60) p[i].first = p[i].first+40;
        if(p[i].second % 100 == 60) p[i].second = p[i].second+40;
    }

    sort(p.begin(), p.end());

    int s = p[0].first, e = p[0].second;
    for(int i = 1; i < N; i++)
    {
        if(p[i].second <= e) continue;
        if(p[i].first <= e) e = p[i].second;
        else
        {
            cout << setw(4) << setfill('0') << s << "-" << setw(4) << setfill('0') << e << endl;
            s = p[i].first;
            e = p[i].second;
        }
    }
    cout << setw(4) << setfill('0') << s << "-" << setw(4) << setfill('0') << e << endl;
}