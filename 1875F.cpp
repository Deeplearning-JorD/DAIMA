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
const int N = 5010;
double p[N][N];
void Solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> son(n + 1);
    for(int i = 1;i <= m;i ++){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
    }
    vector<double> dp(n + 1);
    dp[n] = 1.0;
    for(int i = n;i >= 1;i --){
        sort(son[i].begin(), son[i].end(), [&](int a, int b){
            return dp[a] > dp[b];
        });
        for(int j = 0;j < son[i].size();j ++){
            dp[i] += dp[son[i][j]] * p[son[i].size()][j + 1];
        }
    }
    cout << SPO(12) << dp[1] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // 现在有i条路，选择了第j条路的成功概率
    p[1][1] = 1;
    for(int i = 2;i < N;i ++){
        p[i][1] = 1.0 / i;
        for(int j = 2;j <= i;j ++){
            p[i][j] = p[i - 2][j - 1] * (1. * (i - j) / i) + p[i - 2][j - 2] * (1. * (j - 2) / i);           
        }
    }
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}