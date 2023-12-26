/*
 * @Author: JorD
 * @LastEditTime: 2023-07-28 23:21:56
 * 理清对应关系
 */
#pragma GCC optimize(2)
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
ll exgcd(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
ll mul(ll a, ll k, ll mod){
    ll res = 0;
    while(k){
        if(k & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        k >>= 1;
    }
    return res;
}
pair<ll, ll> merge(ll A, ll B, ll a, ll b){
    // x = A + B * k1
    // x = a + b * k2
    // b * k2 - B * k1 = A - a
    // b * k2 + B * (- k1) = A - a
    ll r1, r2;
    ll d = exgcd(b, B, r1, r2);
    if((A - a) % d){
        return {-1,-1};
    }
    r1 = (r1 % (B / d) + (B / d)) % (B / d);
    r1 *= (A - a) / d;
    B = b / d * B;
    r1 = ((a + mul(b, r1, B) % B) % B + B) % B; 
    return {r1, B};
}
void Solve(){
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    vector<int> fa(n + 1), fb(n + 1), fc(n + 1);
    vector<int> ida(n + 1, -1), idb(n + 1, -1), idc(n + 1, -1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, n){
        fa[a[i]] = i;
        fb[b[i]] = i;
        fc[c[i]] = i;
    }
    vector<int> sa, sb, sc;
    sa.push_back(1);
    sb.push_back(1);
    sc.push_back(1);
    set<int> s;
    s.insert(1);
    rep(i, 1, n){
        int x = a[b[c[sa.back()]]];
        if(s.count(x)){s.clear(); break;}
        sa.push_back(x);
    }
    s.insert(1);
    rep(i, 1, n){
        int x = b[c[a[sb.back()]]];
        if(s.count(x)){s.clear(); break;}
        sb.push_back(x);
    }
    s.insert(1);
    rep(i, 1, n){
        int x = c[a[b[sc.back()]]];
        if(s.count(x)){s.clear(); break;}
        sc.push_back(x);
    }
    int n1 = sa.size(), n2 = sb.size(), n3 = sc.size();
    rep(i, 0, n1 - 1) ida[sa[i]] = i;
    rep(i, 0, n2 - 1) idb[sb[i]] = i;
    rep(i, 0, n3 - 1) idc[sc[i]] = i;
    auto check = [&](int x, int y, int z){
        ll res = 1e18;
        x = ida[x];
        y = idb[y];
        z = idc[z];
        if(x == -1 || y == -1 || z == -1) return res;
        auto [a, b] = merge(x, n1, y, n2);
        if(a == -1 && b == -1) return res;
        auto [c, d] = merge(a, b, z, n3);
        if(c == -1 && d == -1) return res;
        return 3 * c;
    };
    int m; cin >> m;
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        ll res = min({check(x, y, z),check(fc[z], fa[x], fb[y])+1,check(fc[fb[y]], fa[fc[z]], fb[fa[x]])+2});
        if(res >= 1e18) cout << -1 << endl;
        else cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}