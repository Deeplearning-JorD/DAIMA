/*
 * @Author: JorD
 * @LastEditTime: 2023-03-03 22:01:47
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
typedef unsigned long long ULL;
const int N = 2e6 + 10;
const ULL P = 131, mod = 1e9 + 7, PP = 13331;
ULL h[N],p[N],hh[N], pp[N];
ULL find(int l, int r){
    if(l > r) return 0;
    return h[r]-h[l-1]*p[r-l+1];
}
ULL find1(int l, int r){
    if(l < 0 || r < 0) return 0;
    return (h[r] - hh[l - 1] * pp[r - l + 1] % mod + mod)%mod;
}
void Solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<ULL,ULL>, int> q;
    s = ' ' + s;
    rep(i, 1, n){
        h[i] = h[i - 1] * P + s[i] - 'a';
    }
    rep(i, 1, n){
        hh[i] = ((hh[i - 1] * P) % mod + s[i] - 'a')%mod;
    }
    ll res = 0;
    for(int i = 1, j = 2;j <= n;j ++, i ++){
        ULL L = 0, R = 0;
        ULL L1 = 0, R1 = 0;
        if(i - 1 > 0) L = find(1, i - 1);
        if(j + 1 <= n) R = find(j + 1, n);
        if(i - 1 > 0) L1 = find1(1, i - 1);
        if(j + 1 <= n) R1 = find1(j + 1, n);
        ULL now = L * p[n - j] + R;
        ULL ji = (L1 * pp[n - j] + R1)%mod;
        if(q[{now, ji}]) continue;
        q[{now, ji}] = 1;
        res ++; 
    }   
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    p[0] = 1;
    rep(i, 1, N - 5) p[i]=p[i-1]*P;
    pp[0] = 1;
    rep(i, 1, N - 5) pp[i]=(pp[i-1]*P)%mod;
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}