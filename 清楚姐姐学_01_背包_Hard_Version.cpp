/*
 * @Author: JorD
 * @LastEditTime: 2023-01-30 17:02:51
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
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> w(n + 1), v(n + 1);
    rep(i, 1, n) cin >> v[i] >> w[i];
    vector<vector<ll>> pre(n + 1, vector<ll> (m + 1));
    vector<vector<ll>> last(n + 2, vector<ll> (m + 2));
    // 考虑前i个物品 体积为 j 时的最大贡献
    // 考虑后i个物品 体积为 j 时的最大贡献
    rep(i, 1, n){
        for(int j = 0;j <= m;j ++){
            pre[i][j] = pre[i - 1][j];
            if(v[i] <= j) 
            pre[i][j] = max(pre[i][j], pre[i - 1][j - v[i]] + w[i]);
        }
    }
    per(i, n, 1){
        for(int j = 0;j <= m;j ++){
            last[i][j] = last[i + 1][j];
            if(v[i] <= j)
            last[i][j] = max(last[i][j], last[i + 1][j - v[i]] + w[i]);
        }
    }
    vector<ll> use(n + 1);
    vector<ll> unuse(n + 1);
    rep(i, 1, n){
        for(int j = 0;j <= m;j ++){
            unuse[i] = max(unuse[i], pre[i - 1][j] + last[i + 1][m - j]);
        }
    }
    rep(i, 1, n){
        for(int j = 0;j <= m - v[i];j ++){
            use[i] = max(use[i], pre[i - 1][j] + last[i + 1][m - j - v[i]] + w[i]);
        }
    }
    rep(i, 1, n){
        cout << max(0ll, unuse[i] + 1 - use[i]) << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}