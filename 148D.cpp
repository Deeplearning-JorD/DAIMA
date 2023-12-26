#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int N = 1010;
double dp[2][N][N];
double dfs(int i, int j, int op){
    if(op == 1){
        if(i <= 0) return 0;
        if(j <= 0) return 1;
    }else{
        if(i <= 0) return 0;
        if(j <= 0) return 0;
    }
    if(dp[op][i][j] != -1) return dp[op][i][j];
    if(op == 1){
        dp[op][i][j] = dfs(i, j - 1, op ^ 1) * (1. * j / (i + j)) + (1. * i / (i + j));
    }else{
        dp[op][i][j] = (1. * j / (i + j)) * ((1. * (j - 1) / (i + j - 1)) * dfs(i, j - 2, op ^ 1) + (1. * i / (i + j - 1)) * dfs(i - 1, j - 1, op ^ 1));
    }
    return dp[op][i][j];
}
void Solve(){
    // dp[w][b] 表示 还现在还剩下w个白色和b个黑子公主赢的概率
    // 公主回合：
    // dp[i][j] = dp[i][j - 1] * (j / (i + j)) + (i / (i + j));
    // 龙回合：
    // dp[i][j] = j / (i + j) * (((j - 1) / (i + j - 1)) * dp[i][j - 2] + ((i) / (i + j - 1)) * dp[i - 1][i - 1]);
    int w, b; cin >> w >> b;
    cout << SPO(10) << dfs(w, b, 1);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    rep(i, 0, 1000)rep(j, 0, 1000) dp[0][i][j] = dp[1][i][j] = -1;
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}