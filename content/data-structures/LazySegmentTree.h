/**
 * Author: Štěpán Mikéska
 * Date: 2026-02-04
 * License: CC0
 * Source: me
 * Description: Segment tree with range add and sum capability.
 * Can be modified for different operations.
 * Time: O(\log N).
 * Status: not stress tested, but should work
 */
#pragma once

struct Tree {
    struct N { ll sum = 0; ll ladd = 0; };
    vector<N> it;
    int s = 1;
    Tree(vector<int>& as) {
        while(s < as.size()) s *= 2;
        it.resize(2*s);
        for(int i = 0; i < as.size(); ++i) it[s+i].sum = as[i];
        for(int i = s-1; i > 0; --i)       pull(i);
    }
    void tag(int i, ll ladd, int len) {
        it[i].sum += len*ladd;
        it[i].ladd += ladd;
    }
    void push(int i, int len) {
        for(int a : {2*i, 2*i+1}) {
            tag(a, it[i].ladd, len/2);
        }
        it[i].ladd = 0;
    }
    void pull(int i) {
        it[i].sum = it[2*i].sum + it[2*i+1].sum;
    }
    void add(int l, int r, ll a, int la = 0, int ra = -1, int i = 1) {
        if(ra == -1) ra = s;
        if(ra <= l || r <= la) return;
        if(l <= la && ra <= r) {
            tag(i, a, ra - la);
            return;
        }
        push(i, ra - la);
        int ma = (la + ra) / 2;
        add(l, r, a, la, ma, 2*i  );
        add(l, r, a, ma, ra, 2*i+1);
        pull(i);
    }
    ll sum(int l, int r, int la = 0, int ra = -1, int i = 1) {
        if(ra == -1) ra = s;
        if(ra <= l || r <= la) return 0;
        if(l <= la && ra <= r) {
            return it[i].sum;
        }
        push(i, ra - la);
        int ma = (la + ra) / 2;
        return sum(l, r, la, ma, 2*i  ) +
               sum(l, r, ma, ra, 2*i+1);
    }
};
