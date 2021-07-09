//
//  main.cpp
//  substring-order-II
//
//  Created by Saba Khutsishvili on 09.07.21.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <map>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

struct State {
    int len, link;
    map<char, int> next;
};

const int M = 1e1;
State st[M * 2];
int sz, last;
string s;
ll ss, k, p = 0;

void sa_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

void klex(int ver) {
    vector<int> ans;
    for (int i = 0; i < 26; i++) {
        if (st[ver].next[i]) {
            p++;
            if (p == k) {
                ans.push_back((char)('a' + i));
                return;
            }
//            klex(st[ver].next[i], ans);
            if (p == k) {
                ans.push_back((char)('a' + i));
                return;
            }
        }
    }
}

int main() {
    
    cin >> s;
//    cin >> k;
    ss = (ll)s.size();
    sa_init();
    for (ll i = 0; i < ss; ++i) {
        sa_extend(s[i]);
    }
    cout << "\n";
    
    return 0;
}
