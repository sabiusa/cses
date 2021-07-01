//
//  main.cpp
//  word-combinations
//
//  Created by Saba Khutsishvili on 16.06.21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long

//const ll N = 1e6+1, M = 26, MOD = 1e9+7;
//ll ct = 0;
//string w;
//vector<vector<ll>> trie(N, vector<ll> (M));
//vector<bool> we(N); // word end
//vector<ll> mem(N);
//
//void insert(string s) {
//    ll node = 0;
//    for (ll i = 0; i < (ll)s.size(); ++i) {
//        ll c = s[i] - 'a';
//        if (trie[node][c] == 0) {
//            trie[node][c] = ++ct;
//        }
//        node = trie[node][c];
//    }
//    we[node] = 1;
//}
//
//ll search(ll x, ll ws) {
//    ll cnt = 0;
//    for (ll node = 0, i = x; i < ws; ++i) {
//        ll c = w[i] - 'a';
//        if (trie[node][c] == 0) {
//            return cnt;
//        }
//        node = trie[node][c];
//        if (we[node]) {
//            cnt += mem[i+1];
//            cnt %= MOD;
//        }
//    }
//    return cnt;
//}
//
//int main() {
//    ll k;
//    
//    cin >> w;
//    cin >> k;
//    while (k--) {
//        string s;
//        cin >> s;
//        insert(s);
//    }
//    ll ws = (ll)w.size();
//    mem[ws] = 1;
//    for (ll i = ws-1; i >= 0; --i) {
//        mem[i] = search(i, ws);
//    }
//    cout << mem[0] << "\n";
//    
//    return 0;
//}
