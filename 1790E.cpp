/*
 * @Author: JorD
 * @LastEditTime: 2023-01-28 00:38:11
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void jj(int x){
    while(x){
        cout << (x & 1);
        x >>= 1;
    }
    cout << endl;
    return;
}
void Solve(){
    ll n, nn; cin >> n;
    nn = n;
    // if(n & 1){
    //     cout << -1 << endl;
    //     return;
    // }
    // n <<= 1;
    n >>= 1;
    // jj(n);
    ll x = 0, y = 0;
    for(int i = 0;i <= 30;i ++){
        if(n >> i & 1){
            x |= 1ll << i;
            y |= 1ll << i;
        }
    }
    // n <<= 1;
    n = nn;
    for(int i = 0;i <= 30;i ++){
        if(n >> i & 1){
            if((x ^ y) >> i & 1) continue;
            x |= 1ll << i;
        }
    }
    if(!x || !y){
        cout << -1 << endl;
        return;
    }
    if((x ^ y) != (x + y) / 2 || (x ^ y) != nn) cout << -1 << endl;
    else    cout << x << ' ' << y << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}