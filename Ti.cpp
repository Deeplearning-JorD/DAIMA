/*
 * @Author: JorD
 * @LastEditTime: 2023-09-04 20:02:26
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
const int N = 1e5 + 10, mod = 1e9 + 7;
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
ll ans[N];
void Solve(){
    int n, k; cin >> n >> k;
    for(int i = k;i >= 1;i --){
        ans[i] = fpow(k / i, n, mod);
        for(ll j = 2;j * i <= k;j ++){
            ans[i] -= ans[j * i];
            ans[i] %= mod;
        }
        ans[i] = (ans[i] % mod + mod) % mod;
    }
    ll res = 0;
    for(int i = 1;i <= k;i ++){
        res = (res + ans[i] * i) % mod;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}