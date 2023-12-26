/*
 * @Author: JorD
 * @LastEditTime: 2023-03-20 19:17:07
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
struct node{
    ll l, r, x;
};
void Solve(){
    ll len, n, m;
    cin >> len >> n >> m;
    ll idx = 1;
    vector<node> a(n + 1), b(m + 1);
    rep(i, 1, n){
        ll l, r;
        cin >> l >> r;
        a[i] = {idx, idx + r - 1, l};
        idx += r;
    }
    idx = 1;
    rep(i, 1, m){
        ll l, r;
        cin >> l >> r;
        b[i] = {idx, idx + r - 1, l};
        idx += r;
    }
    int l = 1, r = 1;
    ll res = 0;
    rep(o, 1, n + m){
        ll L = max(a[l].l, b[r].l), R = min(a[l].r, b[r].r);
        if(a[l].x == b[r].x){
            res += max(0ll, R - L + 1);
        }
        if(l == n) r ++;
        else if(r == m) l ++;
        else if(a[l].r > b[r].r && r < m) r ++;
        else l ++;
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