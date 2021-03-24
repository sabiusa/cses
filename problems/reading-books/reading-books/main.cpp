//
//  main.cpp
//  reading-books
//
//  Created by Saba Khutsishvili on 3/24/21.
//

#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, s = 0;
    
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
        s += arr[i];
    }
    sort(arr, arr + n);
    cout << max(s, arr[n - 1] * 2) << "\n";
    
    return 0;
}
