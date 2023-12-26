/*
 * @Author: JorD
 * @LastEditTime: 2023-01-21 09:33:17
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
const int N = 2e5 + 10, mod = 1e9 + 7;
int qmi(int a,int k, int p){
    ll res=1%p;
    while(k){
        //如果当前k的二进制位末为1则计入
        if(k&1) res=res*a%p;
        a=a*(ll)a%p;
        //朴实的右移
        k>>=1;
    }
    return res;
}
ll a[N], c[N];
Eule
void Solve(){
    int n;
    cin >> n;
    ll sum = 0, cnt = 0;
    rep(i, 1, n){
        cin >> a[i];
        c[1] ++;
        c[a[i] + 1] --;
    }
    rep(i, 1, n) c[i] += c[i - 1];
    ll res = 0, ji = 1;
    rep(i, 1, n){
        ll now = (i + 1) * qmi(i, mod - 2, mod) % mod;
        ji *= now;
        ji %= mod;
        res += ji * (((1 - qmi(now, c[i], mod))%mod + mod)%mod)%mod
        * qmi(((1 - now)%mod+mod)%mod, mod - 2, mod) % mod;
        res %= mod;
        res += mod;
        res %= mod;
        ji *= (qmi(now, mod - 2, mod)%mod + mod)%mod;
        ji *= (qmi(now, c[i], mod)%mod + mod)%mod;
        ji %= mod;
        ji += mod;
        ji %= mod;
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