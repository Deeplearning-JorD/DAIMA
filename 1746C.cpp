/*
 * @Author: JorD
 * @LastEditTime: 2022-10-16 11:08:06
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int mx = 0;
    vector<vector<int>> son(n + 1);
    rep(i, 1, n){
        if(mx > a[i]){
            son[mx - a[i]].push_back(i);
            mx = a[i];
        }
        mx = max(mx, a[i]);
    }
    vector<bool> vis(n + 2);
    vector<int> ans(n + 1, 1);
    rep(i, 1, n){
        int j = i;
        for(auto x:son[i]){
            while(j <= n&&vis[j]){
                j ++;
            }
            vis[j] = true;
            ans[j] = x;
        }
    }
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}