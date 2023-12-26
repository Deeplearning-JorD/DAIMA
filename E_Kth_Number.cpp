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
    if(k <= 0) return 1;
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
void Solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> js(m + 1);
    int can = 0;
    rep(i, 1, n){
        int x; cin >> x;
        if(!x) can ++;
        js[x] ++;
    }
    int pre = 0;
    ll res = 0;
    auto get = [&](int l, int r, int k){
        return fpow(l * fpow(r, mod - 2, mod), k, mod);
    };
    vector<int> v;
    for(int now = 1;now <= m;now ++){
        if(pre < k){
            for(int i = max(k - pre - js[now], 0);i <= min(can, k - pre);i ++){
                //现在需要i个数随机出来的值<=now
                if(i == 0){
                    ll a = get(m - now, m, can);
                    res += a * now % mod;
                    res %= mod;
                    continue;
                }
                if(i == k - pre){
                    ll a = get(now, m, i - 1);
                    ll b = get(1, m, 1);
                    ll c = get(m - now, m, can - i);
                    res += a * b % mod * c % mod * now % mod;
                    res %= mod;
                    continue;
                }
                ll a = get(now, m, i);
                ll b = get(m - now, m, can - i);
                res += ((a * b) % mod * now) % mod;
                res %= mod;
            }
        }
        pre += js[now];
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