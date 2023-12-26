/*
 * @Author: JorD
 * @LastEditTime: 2022-12-15 23:50:06
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
const int N = 2e5 + 10, mod = 998244353;
ll fact[N],infact[N];
ll qmi(int a,int k,int p){
    int res=1;
    while(k){
        if(k&1) res=(ll)res*a%p;
        a=(ll)a*a%p;
        k>>=1;
    }
    return res;
}
void Solve(){
    int n;
    cin >> n; 
    string s;
    cin >> s;
    s = ' ' + s;
    ll idx = 0;
    ll res = 0;
    rep(i, 1, n){
        if(s[i] == s[i - 1]){
            idx ++;
        }else{
            res = ((res + qmi(2, idx, mod) - 1) % mod + mod) % mod;
            idx = 1;
        }
    }
    res = ((res + qmi(2, idx, mod) - 1) % mod + mod) % mod;
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}