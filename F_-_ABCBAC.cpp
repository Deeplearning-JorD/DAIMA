/*
 * @Author: JorD
 * @LastEditTime: 2023-01-08 00:56:02
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
const int N=2e6 +10,P=131;
const ULL mod = 1e9+7;
int n,m;
ULL h[N],p[N];
ULL hh[N], pp[N];
ULL h1[N];
ULL hh1[N];
ULL find(int l, int r){
    if(l > r) return 0;
    return h[r]-h[l-1]*p[r-l+1];
}
ULL find1(int l, int r){
    if(l > r) return 0;
    return (hh[r]-hh[l-1]*pp[r-l+1]%mod+mod)%mod;
}
ULL find2(int l, int r){
    if(l > r) return 0;
    return h1[l]-h1[r+1]*p[r - l + 1];
}
ULL find3(int l, int r){
    if(l > r) return 0;
    return (hh1[l]-hh1[r+1]*pp[r - l + 1]%mod+mod)%mod;
}
void Solve(){
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    p[0] = 1;
    pp[0] = 1;
    for(int i=1;i<=2*n;i++){
        h[i]=h[i-1]*P+s[i]-'a';
        p[i]=p[i-1]*P;
        hh[i] = (hh[i - 1]*P + s[i] - 'a') % mod;
        pp[i] = (pp[i - 1]*P)%mod;
    }
    h1[2 * n + 1] = hh1[2 * n + 1] = 0;
    for(int i = 2 * n;i >= 1;i --){
        h1[i] = h1[i + 1] * P + s[i] - 'a';
        hh1[i] = (hh1[i + 1]*P + s[i] - 'a') % mod;
    }
    rep(i, 1, n){
        ULL res1 = find(1, i) * p[n - i]+ find(i + n + 1, 2 * n) ;
        ULL res2 = (find1(1, i) * pp[n - i] + find1(i + n + 1, 2 * n) ) % mod;
        ULL ans1 = find2(i + 1, i + n);
        ULL ans2 = find3(i + 1, i + n);
        if(res1 == ans1 && res2 == ans2){
            per(j, i + n, i + 1) cout << s[j];
            cout << endl;
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}