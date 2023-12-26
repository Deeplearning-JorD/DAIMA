/*
 * @Author: JorD
 * @LastEditTime: 2023-05-30 13:29:35
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
const ll mod = 998244353, p = 1e9 + 7;
struct node{
    ll a, b, c;
};
void Solve(){
    ll w, h, z;
    cin >> w >> h >> z;
    int n; cin >> n;
    vector<node> q(n);
    map<ll, ll> X, Y, Z;
    X[w] = 1; Y[h] = 1, Z[z] = 1;
    for(auto &[a, b, c] : q){
        ll sx, sy, sz, ex, ey, ez; 
        cin >> sx >> sy >> sz >> ex >> ey >> ez;
        a = ex - sx;
        b = ey - sy;
        c = ez - sz;
        X[a] = 1;
        Y[b] = 1;
        Z[c] = 1;
    }
    for(int o = 1;o <= 2;o ++){
        for(auto &[i, x] : X) x = rand();
        for(auto &[i, x] : Y) x = rand();
        for(auto &[i, x] : Z) x = rand();
        ll l = X[w], m = Y[h], r = Z[z];
        ll res = w * h * z % mod * l * m * r % mod;
        ll res1 = ((((w * l % p) * m % p) * h % p) * r % p) * z % p;
        ll now = 0, now1 = 0;
        for(auto [ww, hh, zz] : q){
            ll l1 = X[ww], m1 = Y[hh], r1 = Z[zz];
            now += ww * hh * zz % mod * l1 * m1 * r1 % mod;
            now1 += ww * hh * zz % p * l1 * m1 * r1 % p;
            now %= mod;image.png
            now1 %= p;
        }
        if(res == now && res1 == now1) continue;
        cout << res << ' ' << now << endl;
        cout << res1 << ' ' << now1 << endl;
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    srand(time(NULL));
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}