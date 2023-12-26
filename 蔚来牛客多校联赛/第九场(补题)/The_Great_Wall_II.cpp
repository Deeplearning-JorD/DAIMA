/*
 * @Author: JorD
 * @LastEditTime: 2022-08-16 20:56:51
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
const int N = 8e3+10;
const ll MAX = 1e18;
int f[N][20], lg[N];
int a[N];
int dp[N][N];
int n;
void work(){
    lg[1] = 0, lg[2] = 1;
    for(int i = 3;i <= n;i++){
        lg[i] = lg[i/2] + 1;
    }
    for(int j = 1;j <= 18;j ++){
        for(int i = 1;i + (1<<j) - 1<= n;i ++){
            f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]); 
        }
    }
}
int find(int l,int r){
    int len = lg[r-l+1];
    return max(f[l][len], f[r-(1<<len)+1][len]);
}
void Solve(){
    cin >> n;
    rep(i, 1, n){
        cin >> a[i];
        f[i][0] = a[i];
    }
    work();
    // dp[i][j]表示[1,j]区间内分成i段的最小代价
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    rep(i, 1, n){
        stack<pair<ll,ll>> stk;
        stack<ll> mn;
        rep(j, 1, n){
            //其实枚举的就是最后一个区间所在的位置
            pair<ll,ll> x = {dp[i-1][j-1],a[j]};
            while(!stk.empty()&&stk.top().first>=x.first) stk.pop(),mn.pop();
            while(!stk.empty()&&stk.top().second<=x.second){
                x.first = stk.top().first;
                stk.pop(),mn.pop();
            } 
            stk.emplace(x);
            mn.emplace(min(mn.empty()?MAX:mn.top(),x.first+x.second));
            dp[i][j] = mn.top();
        }
    }
    rep(i, 1, n) cout << dp[i][n] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}