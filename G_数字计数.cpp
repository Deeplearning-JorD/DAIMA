/*
 * @Author: JorD
 * @LastEditTime: 2023-04-18 22:30:34
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
const int N = 25;
int dp[N][N];
ll DP[N];
// dp[i][j]表示考虑后面i位j出现的总次数
int d[N], idx;
ll ans[N];
bool st[N];
ll dfs(int now, bool up, bool zero){
    if(!zero && !up){
        if(st[now])return DP[now];
        else{
            st[now]=1;
            DP[now]=dfs(now-1,up,zero);
        }
        for(int j = 0;j <= 9;j ++) ans[j] += dp[now][j];
        
        return ;
    }
    for(int j = 0;j <= 9;j ++){
        if(up && j > d[now]) continue;
        ans[j] ++;
        dfs(now - 1, up && (d[now] == j), zero && (j == 0));
    }
}
void cc(int x){
    idx = 0;
    while(x){
        d[idx ++] = x % 10;
        x /= 10;
    }
    dfs(idx, 1, 1, 1);
}
void Solve(){
    int l, r;
    cin >> l >> r;
    cc(r);
    for(int i = 0;i <= 9;i ++) cout << ans[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}