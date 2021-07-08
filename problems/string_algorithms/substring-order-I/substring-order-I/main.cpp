//
//  main.cpp
//  substring-order-I
//
//  Created by Saba Khutsishvili on 06.07.21.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <numeric>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

struct Node {
    int l = -1, r = -1, d = 0;
    Node* par = NULL;
    Node* next[26] = {NULL};
    
    Node() {}
    
    Node(int l, int r, Node* p = NULL) {
        par = p;
        set(l, r);
    }
    
    void set(int l, int r) {
        this->l = l;
        this->r = r;
        d = par->d + (r - l);
    }
    
    int len() {
        return r - l;
    }
};
 
struct SuffixTree {
    int n;
    string s;
    vector<int> sa, lcp, rank;
    Node *root;
    
    SuffixTree(string& orig, int lim = 256) {
        s = orig;
        n = (int)s.size() + 1;
        calc_sa(s, lim);
        calc_lcp(s);
        build_tree();
    }
    
    void calc_sa(string& s, int lim = 256) {
        int a, b;
        vector<int> x(s.begin(), s.end()+1), y(n), ws(max(n, lim));
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
    }
    
    void calc_lcp(string& s) {
        rank.resize(n);
        for (int i = 1; i < n; ++i) {
            rank[sa[i]] = i;
        }
        for (int i = 0, h = 0, k = 0; i < n; ++i) {
            if (rank[i] > 0) {
                k = sa[rank[i]-1];
                while (s[i+h] == s[k+h]) h++;
                lcp[rank[i]] = h;
                if (h > 0) --h;
            }
        }
    }
    
    void build_tree() {
        n--;
        root = new Node();
        Node *nxt = new Node(sa[1], n, root);
        root->next[s[nxt->l] - 'a'] = nxt;
        for (int i = 2; i <= n; ++i) {
            int l = sa[i], cp = lcp[i];
            Node *prev, *cur = nxt;
            while (cur->d > cp) {
                prev = cur;
                cur = cur->par;
            }
            if (cur->d == cp) {
                nxt = new Node(l+cp, n, cur);
                cur->next[s[nxt->l] - 'a'] = nxt;
            } else {
                int d = cp - cur->d;
                Node *split = new Node(prev->l, prev->l+d, cur);
                cur->next[s[split->l] - 'a'] = split;
                prev->par = split;
                prev->l = split->r;
                split->next[s[prev->l] - 'a'] = prev;
                nxt = new Node(l+split->d, n, split);
                split->next[s[nxt->l] - 'a'] = nxt;
            }
        }
    }
};
 
string s, p;
ll ss, ps, k, cnt = 0;
SuffixTree *sa;

void print_path(Node* nd) {
    ll d = k - cnt;
    string ans = s.substr(nd->l, d);
    Node* cur = nd->par;
    while (cur->l != -1) {
        ans = s.substr(cur->l, cur->len()) + ans;
        cur = cur->par;
    }
    cout << ans << "\n";
    exit(0);
}

void dfs(Node* nd) {
    cnt += nd->len();
    for (auto a : nd->next) {
        if (a != NULL) {
            if (cnt + a->len() < k) {
                dfs(a);
            } else {
                print_path(a);
            }
        }
    }
}
 
int main() {
    
    cin >> s;
    cin >> k;
    ss = (ll)s.size();
    sa = new SuffixTree(s);
    dfs(sa->root);
    
    return 0;
}

