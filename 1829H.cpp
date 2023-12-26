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
const int mod = 1e9 + 7, N = 2e5 + 10;
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
bitset<N> mask[10];
void Solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    rep(i, 0, 6) mask[i].reset();
    int js = 0;
    rep(i, 1, n){
        cin >> a[i];
        for(int j = 0;j < 6;j ++){
            if(a[i] >> j & 1){
                mask[j][i] = 1;
            }
        }
        js += a[i] == 0;
    }
    ll res = 0;
    for(int i = 0;i < (1 << 6);i ++){
        int cnt = 0;
        vector<int> v;
        for(int j = 0;j < 6;j ++){
            cnt += i >> j & 1;
            if(i >> j & 1) v.push_back(j);
        }
        if(cnt != k) continue;
        bitset<N> sum;
        sum.set();
        for(auto x:v){
            sum &= mask[x];
        }
        cnt = 0;
        rep(i, 1, n) cnt += sum[i];
        res += (fpow(2, cnt, mod) - 1) * (fpow(2, n - cnt, mod));
        res %= mod;
        break;
    }
    cout << res << endl;
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
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}