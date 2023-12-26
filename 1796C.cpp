/*
 * @Author: JorD
 * @LastEditTime: 2023-03-01 00:24:01
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
const int N = 110;
ll f[N][N];
void Solve(){
    int l, r;
    cin >> l >> r;
    int idx = 0;
    ll now = l, ls = 1;
    while(now <= r){
        idx ++;
        now *= 2;
        if(idx != 1)
        ls *= 2;
    }
    ll res = 0;
    for(int i = 0;i < idx;i ++){
        if(i){
            ls /= 2;
            ls *= 3;
        }
        if(ls * l > r) break;
        ll L = l, R = r;
        while(L < R){
            ll mid = L + R + 1 >> 1;
            if(mid * ls <= r) L = mid;
            else R = mid - 1;
        }
        res = (res + (L - l + 1) * f[idx - 1][i] % mod) % mod;
    }
    cout << idx << ' ' << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i=0;i<=80;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j) f[i][j]=1;
            else f[i][j]=(f[i-1][j-1]+f[i-1][j])%mod;
        }
    }
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}