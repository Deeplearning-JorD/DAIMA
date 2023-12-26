/*
 * @Author: JorD
 * @LastEditTime: 2023-01-18 14:27:39
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
int c[N];
void Solve(){
    int n, m;
    cin >> n >> m;
    ll res = 0;
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        c[x] ++;
        c[y + 1] --;
        x = max(x, n - y);
        y = min(y, n - x);
        res -= max(0, y - x + 1);
    }
    rep(i, 1, 2e5) c[i] += c[i - 1];
    rep(i, 1, n){
        res += (c[i]) * (c[n - i]);
        res %= mod;
        res += mod;
        res %= mod;
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}