//
//  main.cpp
//  pattern-positions
//
//  Created by Saba Khutsishvili on 03.07.21.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <numeric>

using namespace std;

#define ll long long
#define ull unsigned long long

struct SuffixArray {
    vector<int> sa, lcp, rank;
    SuffixArray(string& s, int lim = 256) {
        int n = (int)s.size() + 1, k = 0, a, b;
        vector<int> x(s.begin(), s.end()+1), y(n), ws(max(n, lim));
        rank.resize(n);
        sa = lcp = y;
        iota(sa.begin(), sa.end(), 0);
        for (int j = 0, p = 0; p < n; j = max((int)1, j * 2), lim = p) {
            p = j;
            iota(y.begin(), y.end(), n - j);
            for (int i = 0; i < n; ++i) {
                if (sa[i] >= j) {
                    y[p++] = sa[i] - j;
                }
            }
            fill(ws.begin(), ws.end(), 0);
            for (int i = 0; i < n; ++i) {
                ws[x[i]]++;
            }
            for (int i = 1; i < lim; ++i) {
                ws[i] += ws[i - 1];
            }
            for (int i = n; i--;) {
                sa[--ws[x[y[i]]]] = y[i];
            }
            swap(x, y);
            p = 1;
            x[sa[0]] = 0;
            for (int i = 1; i < n; ++i) {
                a = sa[i - 1];
                b = sa[i];
                x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
            }
        }
        for (int i = 1; i < n; ++i) {
            rank[sa[i]] = i;
        }
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k) {
            for (k && k--, j = sa[rank[i] - 1];
                    s[i + k] == s[j + k]; k++);
        }
    }
};

string s, p;
ll ss, ps;
SuffixArray *sa;
const char *text, *pat;
vector<vector<ll>> spt;
vector<ll> lg;

void calc_spt() {
    lg.resize(ss+1);
    for (ll i = 2; i <= ss; ++i) {
        lg[i] = lg[i/2] + 1;
    }
    
    ll LOG = lg[ss];
    spt.resize(LOG+1);
    for (ll i = 0; i <= LOG; ++i) {
        spt[i].resize(ss+1);
    }
    
    for (ll i = 1; i <= ss; ++i) {
        spt[0][i] = sa->sa[i];
    }
    for (ll j = 1; j <= LOG; ++j) {
        for (ll i = 1; i + (1<<j) <= ss+1; ++i) {
            spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }
}

ll cnt_first() {
    ll l = 0, r = ss;
    while (l <= r) {
        ll m = l + (r-l)/2;
        ll k = strncmp(pat, text+(sa->sa[m]), ps);
        if (k <= 0) {
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return l;
}

ll cnt_last() {
    ll l = 0, r = ss;
    while (l <= r) {
        ll m = l + (r-l)/2;
        ll k = strncmp(pat, text+(sa->sa[m]), ps);
        if (k < 0) {
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return l;
}

ll query() {
    ll f = cnt_first(), l = cnt_last();
    if (f == l) return -1;
    l--;
    ll len = l - f;
    ll log = lg[len];
    ll pos = min(spt[log][f], spt[log][l-(1<<log)+1]);
    return pos+1;
}

int main() {
    ll k;
    
    cin >> s;
    cin >> k;
    ss = (ll)s.size();
    sa = new SuffixArray(s);
    calc_spt();
    text = s.c_str();
    while (k--) {
        cin >> p;
        ps = (ll)p.size();
        pat = p.c_str();
        cout << query() << "\n";
    }
    
    return 0;
}
