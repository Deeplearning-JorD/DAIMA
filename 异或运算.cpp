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
ll d[100], can;
void add(ll x){
    for(int i = 62;i >= 0;i --){
        if(x >> i & 1){
            if(d[i]) x ^= d[i];
            else{
                d[i] = x;
                return;
            }
        }
    }
    can = 1;
}
vector<ll> v;
ll query(ll k){
    k -= can;
    if(k >= (1ll << siz(v)))
        return -1;
    ll sum = 0;
    for(int i = 0;i < v.size();i ++){
        if(k >> i & 1) sum ^= v[i];
    }
    return sum;
}
void Solve(){
    can = 0;
    int n; cin >> n;
    for(int i = 0;i <= 62;i ++) d[i] = 0;
    rep(i, 1, n){
        ll x; cin >> x;
        add(x);
    }
    v.clear();
    for(int i = 0;i <= 62;i ++){
        for(int j = i - 1;j >= 0;j --){
            if(d[i] >> j & 1) d[i] ^= d[j];
        }
        if(d[i]) v.push_back(d[i]);
    }
    int q; cin >> q;
    while(q --){
        ll k; cin >> k;
        cout << query(k) << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; rep(i,1,t){
    cout << "Case #" << i << ":\n";
    Solve();
    }
    return 0;
}