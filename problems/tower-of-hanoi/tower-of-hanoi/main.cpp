//
//  main.cpp
//  tower-of-hanoi
//
//  Created by Saba Khutsishvili on 3/18/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

void hanoi(ll n, ll a, ll b, vector<pair<ll, ll>> &r) {
    if (n == 1) {
        r.push_back(make_pair(a, b));
    } else {
        ll o = 6 - a - b; // other third rod
        hanoi(n - 1, a, o, r); // move top n-1 stack to other rod
        r.push_back(make_pair(a, b)); // move n-th plate to destination rod
        hanoi(n - 1, o, b, r); // move n-1 stack from other rod to destination
    }
}

int main() {
    ll n;
    vector<pair<ll, ll>> r;
    
    cin >> n;
    hanoi(n, 1, 3, r);
    cout << r.size() << "\n";
    for (ull i = 0; i < r.size(); ++i) {
        cout << r[i].first << " " << r[i].second << "\n";
    }
    
    return 0;
}
