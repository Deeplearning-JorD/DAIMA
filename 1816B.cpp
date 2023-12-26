/*
 * @Author: JorD
 * @LastEditTime: 2023-04-10 00:32:10
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
    int idx = 2 * n;
    int r = 2 * n;
    int l = n;
    r -= 2;
    l -= 1;
    f[0][1] = 2 * n;
    f[1][1] = n;
    f[0][n] = 1;
    f[1][n] = 2 * n - 1;
    for(int i = 2;i <= n - 1; i ++){
        if(i & 1){
            f[0][i] = r --;
            f[1][i] = l --;
        }else{
            f[1][i] = r --;
            f[0][i] = l --;
        }
    }
    rep(i, 0, 1){
        rep(j, 1, n) cout << f[i][j] << ' ';
        cout << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<vector<int>> f(2, vector<int> (7));
    // rep(j, 0, 1)
    // rep(i, 1, 6){
    //     cin >> f[j][i];
    // }
    // vector<int> pre(6 + 1), last(6 + 2);
    // rep(i, 1, 6) pre[i] = pre[i - 1] + f[0][i];
    // per(i, 6, 1) last[i] = last[i + 1] + f[1][i];
    // int mi = 1e9;
    // rep(i, 1, 6) mi = min(mi, pre[i] + last[i]);
    // cout  << mi << endl;
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}