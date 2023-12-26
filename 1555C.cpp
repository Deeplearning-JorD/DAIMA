/*
 * @Author: JorD
 * @LastEditTime: 2022-11-23 22:58:28
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
    int n;
    cin >> n;
    vector<vector<int>> f(2, vector<int> (n + 1));
    vector<vector<int>> pre(2, vector<int> (n + 2));
    vector<vector<int>> last(2, vector<int> (n + 2));
    rep(i, 0, 1) rep(j, 1, n) cin >> f[i][j];
    rep(i, 0, 1){
        rep(j, 1, n){
            pre[i][j] = pre[i][j - 1] + f[i][j];
        } 
        per(j, n, 1){
            last[i][j] = last[i][j + 1] + f[i][j];
        }
    }
    int res = 2e9; 
    rep(i, 1, n){
        res = min(res, max(pre[1][i - 1], last[0][i + 1]));
    }
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