//
//  main.cpp
//  distinct-substrings
//
//  Created by Saba Khutsishvili on 04.07.21.
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
        for (int i = 0, h = 0; i < n; ++i) {
            if (rank[i] > 0) {
                k = sa[rank[i]-1];
                while (s[i+h] == s[k+h]) h++;
                lcp[rank[i]] = h;
                if (h > 0) --h;
            }
        }
    }
};

string s, p;
ll ss, ps;
SuffixArray *sa;
const char *text, *pat;

ll calc() {
    ll pref = 0, ans = (ss * (ss+1)) / 2;
    for (ll i = 2; i <= ss; ++i) {
        pref += sa->lcp[i];
    }
    return ans - pref;
}

int main() {
    
    cin >> s;
    ss = (ll)s.size();
    sa = new SuffixArray(s);
    cout << calc() << "\n";
    
    return 0;
}
