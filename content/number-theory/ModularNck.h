/**
 * Author: HaroldVemeno
 * Date: 2025-03-12
 * Description: Need to set {\tt mod} first.
 * Status: tested
 */
#pragma once
#include "ModPow.h"

constexpr int N = 400000;
int inv(int n) {
    return modpow(n, mod-2);
}
int fac[N + 1];
int ifac[N + 1];
int nck(int n, int k) {
    return ((1ll*fac[n]*ifac[k]) % mod)*ifac[n-k] % mod;
}
void init() {
    fac[0] = 1;
    for(int i = 1; i <= N; ++i)
        fac[i] = (1ll*fac[i-1]*i) % mod;
    ifac[N] = inv(fac[N]);
    for(int i = N-1; i >= 0; --i)
        ifac[i] = (1ll*ifac[i+1]*(i+1)) % mod;
}
