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
const int N = 3e6 + 50;
int n;
ll in[N], inv[N];
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
int calc(int i){
    return in[n] * inv[i] % mod * inv[n - i] % mod;
}
ll cc(){
    return in[n] * in[n] % mod * inv[2 * n + 1] % mod;
}
void Solve(){   
    // ll res = calc(0) * fpow(n + 1, mod - 2, mod) % mod;
    // for(int i = 1;i <= n;i ++){
    //     int c = calc(i);
    //     int k;
    //     if(i & 1) k = -1;
    //     else k = 1;
    //     int y = n - i + 2 * i;
    //     ll now = c * k % mod;
    //     now *= fpow(y + 1, mod - 2, mod);
    //     now %= mod;
    //     res = ((res + now) % mod + mod) % mod;
    // }
    cout << cc() << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    in[0] = inv[0] = 1;
    for(int i = 1;i <= N - 10;i ++){
        in[i] = in[i - 1] * i % mod;
        inv[i] = inv[i - 1] * fpow(i, mod - 2, mod) % mod;
    }
    while(cin >> n)
    Solve();
    return 0;
}