#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t --){
        ll p, k;
        cin >> p >> k;
        if(k == 0){
            cout << 0 << endl;
            continue;
        }
        if(p == 1){
            cout << 1 << endl;
            continue;
        }
        auto check = [&](ll mid){
            ll tot = mid;
            ll a = mid;
            while(1){
                tot += a / p;
                if(a / p == 0 || tot >= k) break;
                a = a / p + a % p;
            }
            return tot >= k;
        };
        ll l = 1, r = k;
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }
    return 0;
}