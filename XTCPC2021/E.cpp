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
const int mod = 1e9 + 7;
int n;
vector<char> v;
ll tot;
void dfs(int now){
    if(now == 0){
        int res = 0;
        vector<bool> st(n + 1);
        for(int i = 3;i < n;i ++){
            if(v[i - 3] == 'C' && v[i - 2] == 'C' && v[i - 1] == 'P' && v[i] == 'C'){
                if(!st[i - 3]&&!st[i - 2]&&!st[i - 1]&&!st[i]){
                    st[i - 3] = st[i - 2] = st[i - 1] = st[i] = 1;
                    res ++;
                }
            }
        }
        tot += res;
        // for(auto x:v) cout << x;
        // cout << endl;
        return;
    }
    v.push_back('C');
    dfs(now - 1);
    v.pop_back();
    v.push_back('P');
    dfs(now - 1);
    v.pop_back();
}
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
// ll get(ll x){
//     // return  ((x * 4 - 1) * 8 + 1) * 2;
//     return (x << 6) - 14;
//     (x * 64 - 14) * 64 - 14
//     x << 12 - 14 * 64 - 14;
//     f(3) = 14 * (64 ^ 2) + 14 * (64 ^ 1) + 14 * (64 ^ 0)
//     f(4) = 14 * (64 ^ 3) + 
//     x * (2 ^ (6 * (n / 6 - 1))) +
//     14 * ()
// }
void Solve(){
    cin >> n;
    ll ans14 = (fpow(64, n, mod) - 1) * (fpow(63, mod - 2, mod)) % mod * 14 % mod;
    ll ans = 2 * fpow(2, 6 * (n / 6), mod) % mod;
    ans += ans14;
    ans %= mod;
    cout << ans << endl;
    // cout << get(2) << endl;
    // cout << get(4) << endl;
    // return;
    // // cout<<8*4-1<<endl;
    // ll last = 0, pre = 0;
    // for(;n <= 16;n ++){
    // tot = 0;
    // cin >> n;
    // dfs(n);
    // pre += tot;
    // cout << n <<  ' ' << tot - last * 2 << ' ' << tot << endl;
    
    // last = tot;
    // }
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}