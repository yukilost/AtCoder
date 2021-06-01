#include <bits/stdc++.h>

const int MAX = 1e7;  // 最大値
int prime[MAX];       // i番目の素数
int divisor[MAX+1];   // iを割り切る最大の素数

/**
 * @fn sieve
 * @brief エラトステネスの篩 O(n log log n)
 * @param[in] n ふるいにかける範囲
 * @return n以下の素数の個数
 */
int sieve(int n)
{
    int p = 0;
    for(int i = 0; i <= n; i++) divisor[i] = i;
    for(int i = 2; i*i <= n; i++)
    {
        if(divisor[i] == i)
        {
            prime[p++] = i;
            for(int j = 2*i; j <= n; j+=i) divisor[j] = i;
        }
    }
}