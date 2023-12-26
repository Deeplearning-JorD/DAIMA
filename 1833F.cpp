/*
 * @Author: JorD
 * @LastEditTime: 2023-05-20 00:57:02
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
const int N = 2e5 + 10, mod = 1e9 + 7;
ll fpow(ll a,ll k,ll p){
    ll res=1%p;
    a %= p;
    for(;k;k >>= 1,a=a*a%p) if(k&1) res = res*a%p;
    return res%p;
}
ll in[N], inv[N];
ll C(int n, int m){
    if(n < m) return 0;
    return in[n] * inv[m] % mod * inv[n - m] % mod;
}
void Solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> cnt(n + 1), last(n + 1);
    map<ll,ll> st, mul;
    rep(i, 1, n){
        cin >> a[i];
        st[a[i]] ++;
    }
    sort(all1(a));
    ll res = 0;
    vector<int> id(n + 1);
    rep(i, 1, n){
        id[a[i]] = i;
        cnt[i] = cnt[i - 1] + (a[i] != a[i - 1]);
        last[i] = last[i - 1];
        if(a[i] != a[i - 1]) last[i] = i;
    }
    ll ji = 1;
    for(auto [x, y] : st){
        mul[x] = y * ji % mod;
        ji *= y;
        ji %= mod;
    }
    for(int i = 1, j = 1;i <= n;i ++){
        while(j <= n && a[j] - a[i] < k) j ++;
        ll w = 1, ww = 1;
        if(last[j - 1] - 1 > i) w = mul[a[last[j - 1] - 1]] * fpow(mul[a[i]], mod - 2, mod) % mod;
        if(j - 1 > i && a[j - 1] != a[i]) ww = j - 1 - last[j - 1] + 1;
        res += C(cnt[j - 1] - cnt[i], k - 1) * ww % mod * w % mod;
        res += mod;
        res %= mod;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    in[0] = inv[0] = 1;
    for(int i = 1;i <= N - 5;i ++){
        in[i] = in[i - 1] * i % mod;
        inv[i] = inv[i - 1] * fpow(i, mod - 2, mod) % mod;
    }
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}