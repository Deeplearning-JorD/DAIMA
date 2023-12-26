/*
 * @Author: JorD
 * @LastEditTime: 2023-05-04 20:58:18
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
const int mod = 998244353, N = 1e5 + 10;
ll inv[N], in[N];
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
ll C(int n, int m){
    if(n < m) return 0;
    return in[n] * inv[m] % mod * inv[n - m] % mod;
}
ll Cv(int n, int m){
    if(n < m) return 0;
    return fpow(C(n, m), mod - 2, mod)%mod;
    // return inv[n] * in[m] % mod * in[n - m] % mod;
}
ll res = 0;
int n;
int use[10], st[N], num[10];
void dfs(int depth,int be){
    int mex = 0;
    for(int i=0;i<depth;i++){
        if(use[i] == mex)
            mex ++;
    }
    ll now = mex, del = 0;
    rep(i, 0, mex-1){
        del += st[i];
        now=now*C(st[i],num[i])%mod;
    }
    if(depth>=3){
        res=(res+now)%mod;
        return;
    }else{
        del += st[mex];
        now=now*C(n-del,3-depth)%mod;
        res=(res+now)%mod;
    }
    for(int i = be;i <= min(3,be+1);i ++)if(num[i] < st[i]){   
        use[depth] = i;
        num[i] ++;
        dfs(depth + 1, i);
        num[i] --;
    }
}
void Solve(){
    cin >> n;
    rep(i, 1, n){
        int x; cin >> x;
        st[x] ++;
    }
    dfs(0, 0);
    res=(res*Cv(n,3)%mod+mod)%mod;
    cout<<res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    in[0] = inv[0] = 1;
    rep(i, 1, N - 4){
        in[i] = in[i - 1] * i % mod;
        inv[i] = inv[i - 1] * fpow(i, mod - 2, mod) % mod;
    }
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}