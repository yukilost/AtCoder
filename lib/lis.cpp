#include "template.cpp"

int LIS(const vector<int> &v)
{
    vector<int> dp(v.size()+1, INF);
    for(int i = 0; i < (int)v.size(); i++) *lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}