//
//  main.cpp
//  creating-strings
//
//  Created by Saba Khutsishvili on 3/17/21.
//

#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
#define ll long long

void perm(string s, string &cur, set<string> &st, vector<bool> &used) {
    if (cur.length() == s.length()) {
        st.insert(cur);
    } else {
        for (ll i = 0; i < s.length(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            cur += s[i];
            perm(s, cur, st, used);
            used[i] = false;
            cur.pop_back();
        }
    }
}
 
int main() {
    string s, cur;
    set<string> st;
    vector<bool> used(8, false);
    
    cin >> s;
    perm(s, cur, st, used);
    cout << st.size() << "\n";
    for (string p : st) {
        cout << p << "\n";
    }
    
    return 0;
}
