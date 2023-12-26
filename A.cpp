/*
 * @Author: JorD
 * @LastEditTime: 2022-10-17 19:35:23
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
    vector<int> b(n + 1);
    rep(i, 2, n) cin >> b[i];
    vector<vector<int>> f(n + 1, vector<int> (4, -1e9));
    f[0][0] = 0;
    // f[i][j]表示考虑前i个点时 选择了j次补给站的最大剩余糖数
    rep(i, 1, n){
        rep(j, 1, 3){
            if(f[i - 1][j] - b[i] >= 0) f[i][j] = max(f[i][j], f[i - 1][j] - b[i]);
            if(f[i - 1][j - 1] - b[i] >= 0) f[i][j] = max(f[i][j], f[i - 1][j - 1] - b[i] + a[i]); 
        }
        f[i][0] = max(f[i][0], f[i - 1][0] - b[i]);
    }
    cout << max({-1, f[n][0], f[n][1], f[n][2], f[n][3]});
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}