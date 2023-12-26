#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int mod = 998244353;
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
void Solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    function<ll(vector<int>,int)> solve = [&](vector<int> v, int round){
        if(v.empty()) return 0ll;
        vector<vector<int>> son(32);
        for(auto x:v){
            //二进制上要整体往前面移一位，把0空出来
            int w = -1;
            for(int i = 0;i <= 30;i ++)if(x >> i & 1) w = i;
            son[w + 1].push_back(x);
        }
        ll res = 0, m = v.size();
        for(int i = 0;i <= 30;i ++){
            res += 1ll * son[i].size() * (m - son[i].size()) % mod * (2 * round + 1) % mod;
            res %= mod;
            if(i){
                for(auto &x:son[i]){
                    x -= 1 << (i - 1);
                }
                res += solve(son[i], round + 1);
                res %= mod;
            }else{  
                res += 1ll * son[i].size() * son[i].size() % mod * round % mod;
                res %= mod;
            }
            m -= son[i].size(); 
        }
        return res % mod; 
    };
    cout << solve(a, 1) * fpow(n, mod - 2, mod) % mod * fpow(n, mod - 2, mod) % mod << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}