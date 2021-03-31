//
//  main.cpp
//  movie-festival-II
//
//  Created by Saba Khutsishvili on 3/31/21.
//

#include <iostream>
#include <array>
#include <set>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long

int main() {
    ll n, k, a, b, ans = 0;
    multiset<array<ll, 2>> mt;
    multiset<ll> mq;
    
    cin >> n >> k;
    for (ll i = 0; i < n; ++i) {
        cin >> a >> b;
        mt.insert({b, a});
    }
    for (ll i = 0; i < k; ++i) {
        mq.insert(0);
    }
    for (auto it = mt.begin(); it != mt.end(); ++it) {
        auto end = mq.upper_bound((*it)[1]); // choose the latest end time
        if (end != mq.begin()) {
            mq.erase(prev(end));
            mq.insert((*it)[0]);
            ans++;
        }
    }
    cout << ans << "\n";
    
    return 0;
}
