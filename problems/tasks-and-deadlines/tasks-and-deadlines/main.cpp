//
//  main.cpp
//  tasks-and-deadlines
//
//  Created by Saba Khutsishvili on 3/24/21.
//

#include <iostream>
#include <array>
#include <algorithm>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
 
int main() {
    ll n, t = 0, s = 0;
    
    cin >> n;
    array<ll, 2> arr[n];
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr, arr + n);
    
    for (ll i = 0; i < n; ++i) {
        t += arr[i][0];
        s += (arr[i][1] - t);
    }
    cout << s << "\n";
    
    return 0;
}
