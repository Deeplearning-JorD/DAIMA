/*
 * @Author: JorD
 * @LastEditTime: 2023-05-19 17:37:16
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
ll fpow(ll a,ll k,ll p){
    if(k <= 0) return 1;
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
void Solve(){
    int n; cin >> n;
    map<int,int> st;
    for(int i = 1;i <= n;i ++){
        int x, y; cin >> x >> y;
        st[x] ++;
        st[y] --;
    }
    ll res = 0;
    ll last = 0, per = 0;
    ll k = 0;
    for(auto [x, y] : st){
        res += (fpow(2, k, mod)-1)*(x-last)%mod*fpow(2, n - k, mod);
        res += mod;
        res %= mod;
        k+=y;
        last = x;
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