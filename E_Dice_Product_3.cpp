/*
 * @Author: JorD
 * @LastEditTime: 2023-04-29 21:33:00
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
const int mod = 998244353;
map<ll,ll> st;
ll n;
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
ll dfs(ll now){
    if(st.count(now)) return st[now];
    ll sum = 0;
    rep(i, 2, 6){
        if(now % i == 0)
            sum += dfs(now / i) * fpow(5, mod - 2, mod) % mod;
        sum %= mod;
    }
    st[now] = sum;
    return sum;
}
void Solve(){
    cin >> n;
    st[1] = 1;
    cout << dfs(n);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}