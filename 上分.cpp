/*
 * @Author: JorD
 * @LastEditTime: 2023-03-25 12:57:41
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
    ll s, b, c;
};
void Solve(){
    ll n, m;
    cin >> n >> m;
    vector<node> a(n + 1);
    rep(i, 1, n){
        ll w, b, c;
        cin >> w >> b >> c;
        a[i] = {w, b, c};
    }  
    ll res = 0;
    vector<bool> st(n + 1);
    auto dfs = [&](auto dfs, int i, ll t, ll score){
        if(t > m){
            return;
        }else{
            res = max(res, score);
        }
        if(i > n) return;
        for(int j = 1;j <= n;j ++)if(!st[j]){
            st[j] = true;
            ll T = t + a[j].b;
            dfs(dfs, i + 1, T, score + max(a[j].s - (a[j].s * T * 0.004 ) - 50 * a[j].c, 0.3 * a[j].s));
            st[j] = false;
        }
        dfs(dfs, i + 1, t, score);
    };
    dfs(dfs, 1, 0, 0);
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}