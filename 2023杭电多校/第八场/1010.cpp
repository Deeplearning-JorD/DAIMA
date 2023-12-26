/*
 * @Author: JorD
 * @LastEditTime: 2023-08-10 13:08:24
 * how to Get
 */
#pragma GCC optimize(2)
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
void Solve(){
    ll a, b;
    cin >> a >> b;
    auto check = [&](ll mid){
        ll f = sqrt(mid);
        return (f * f) == mid;
    };
    a = abs(a - b);
    if(check(a)){
        cout << 1 << endl;
        return;
    }
    if(a % 2 == 1){
        cout << 2 << endl;
        return;
    }
    if(a % 4 == 0){
        cout << 2 << endl;
        return;
    }
    for(ll i = 1;i * i <= a;i ++){
        if(check(a - i * i)){
            cout << 2 << endl;
            return;
        }
    }
    cout << 3 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}