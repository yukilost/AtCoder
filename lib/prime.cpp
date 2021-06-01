#include <bits/stdc++.h>

const int MAX = 1e7;  // 最大値
int prime[MAX];       // i番目の素数
bool is_prime[MAX+1]; // trueなら素数

/**
 * @fn sieve
 * @brief エラトステネスの篩
 * @param[in] n ふるいにかける範囲
 * @return n以下の素数の個数
 */
int sieve(int n)
{
    int p = 0;
    for(int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= n; i++)
    {
        if(prime[i])
        {
            prime[p++] = i;
            for(int j = 2*i; j <= n; j+=i) is_prime[j] = false;
        }
    }
}