/*
 * @Author: JorD
 * @LastEditTime: 2023-01-30 15:34:33
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
void Solve(){
    ll n, mod;
    cin >> n >> mod;
    vector<ll> c(n + 1);
    rep(i, 1, n) cin >> c[i];
    vector<ll> a(n + 1), b(n + 1);
    for(int i = 1, j = n;i <= j;i ++, j --){
        if(mod == 2 && (c[i] + c[j]) % 2){
            cout << "No\n";
            return;
        }
        ll div = (c[i] + c[j]) % mod;
        div *= fpow(2, mod - 2, mod);
        div %= mod;
        div += mod;
        div %= mod;
        ll res = c[i] - div;
        res %= mod;
        res += mod;
        res %= mod;
        a[i] = a[j] = div;
        b[i] = res;
        b[j] = - res;
        b[j] %= mod;
        b[j] += mod;
        b[j] %= mod;
        if(i == j && b[i] != b[j]){
            cout << "No\n";
            return;
        } 
    }
    cout << "Yes\n";
    rep(i, 1, n) cout << a[i] << ' ';
    cout << endl;
    rep(i, 1, n) cout << b[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}