/*
 * @Author: JorD
 * @LastEditTime: 2023-03-15 19:19:16
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
const int N = 45, mod = 998244353;
int dp[N][N][N][10];
void Solve(){
    memset(dp, - 1, sizeof dp);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(auto &x:s) cin >> x;
    function<int(int,int,int,int)> dfs = [&](int l, int r, int k, int f){
        if(k == m){
            return (int)(l == r);
        }
        if(f >= 10) return 0;
        if(dp[l][r][k][f] != - 1) return dp[l][r][k][f];
        int val = dfs(l, r, k, f + 1);
        for(int i = l;i <= r;i ++){
            if(s[i][k] != '?' && s[i][k] != '0' + f){
                break;
            }
            if(i != r)
            val += 1ll * dfs(l, i, k + 1, 0) * dfs(i + 1, r, k, f + 1) % mod;
            else val += dfs(l, i, k + 1, 0);
            val %= mod;
        }
        return dp[l][r][k][f] = val;
    };
    cout << dfs(0, n - 1, 0, 0) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}