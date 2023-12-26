/*
 * @Author: JorD
 * @LastEditTime: 2023-05-21 15:58:20
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
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
int inv = fpow(2, mod - 2, mod);
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        a[x] ++, a[y] ++;
    }
    sort(a.begin() + 1, a.end());
    int i=0;
    for(int j=0;j<=n;j++){
        if(a[i]!=a[j]){
            a[++i]=a[j];
        }
        b[i]++;
    }
    n=i;
    ll res = 0;
    for(i = 1;i <= n;i ++){
        for(int j = i + 1;j <= n;j ++){
            ll x = a[i], y = a[j];
            res += (x & y) * (x | y) * (x ^ y) * b[i] * b[j]; 
            res %= mod;
        }
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