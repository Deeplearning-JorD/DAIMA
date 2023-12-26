/*
 * @Author: JorD
 * @LastEditTime: 2022-12-06 16:53:44
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
const int N = 1e5 + 10;
int dp[N][1 << 4][4];
void Solve(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1);
    int idx = 1;
    for(auto &x:s){        
        if(x == 'h') a[idx ++] = 0;
        else if(x == 'c') a[idx ++] = 1;
        else if(x == 'd') a[idx ++] = 2;
        else a[idx ++] = 3;
    }
    for(int i = 1;i <= n;i ++){
        for(int st = 0; st < 1 << 4;st ++){
            for(int j = 0;j < 4;j ++){
                dp[i][st][j] = 1e9;
                if(st & (1 << j)){
                    if(a[i] == j) dp[i][st][j] = dp[i - 1][st][j];
                    else dp[i][st][j] = dp[i - 1][st][j] + 1;
                    if(a[i] != j) continue;
                    int now = (1 << j) ^ st;
                    // 符合的话可以从上一层的另一个状态转移过来。
                    for(int k = 0;k < 4;k ++){
                        dp[i][st][j] = min(dp[i][st][j], dp[i - 1][now][k]); 
                    }
                }
            }
        }
    }
    int res = 1e9;
    for(int i = 0;i < 1 << 4;i ++){
        for(int j = 0;j < 4;j ++){
            res = min(res, dp[n][i][j]);
        }
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}