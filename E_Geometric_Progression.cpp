/*
 * @Author: JorD
 * @LastEditTime: 2023-03-16 19:44:50
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
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
ll dfs(ll a, ll x, ll m){
    if(x == 1) return 1 % m; 
    if(x % 2){
        return (fpow(a, x - 1, m) + dfs(a, x - 1, m)) % m;
    }else return ((1 + fpow(a, x / 2, m)) % m) * (dfs(a, x / 2, m) % m) % m;
}
void Solve(){   
    ll a, x, m;
    cin >> a >> x >> m;
    cout << dfs(a, x, m);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}