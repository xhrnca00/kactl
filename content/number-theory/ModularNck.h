/**
 * Author: HaroldVemeno
 * Date: 2025-03-12
 * Description: Need to set {\tt mod} first.
 * Status: tested
 */
#pragma once

constexpr int mod = 1000000009;
constexpr int N = 400000;
constexpr int bpow(int b, int e) {
    int r = 1;
    while (e > 0) {
        if(e&1) r = (1ll*r*b) % mod;
        b = (1ll*b*b) % mod;
        e /= 2;
    }
    return r;
}
int inv(int n) {
    return bpow(n, mod-2);
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
