/*
 * @Author: JorD
 * @LastEditTime: 2023-04-05 17:46:05
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
const int N = 2e5 + 10;
int p[N], d[N];
ll dp[N], mp[N], id[N];
set<int> s;
void Solve(){
    int n, num;
    scanf("%d%d",&n,&num);
    rep(i, 1, n) scanf("%d",p+i);
    rep(i, 1, n) scanf("%d",d+i);
    for(int i = 1;i <= num;i ++){
        s.insert(num/i);
    }
    int idx = 0;
    for(auto x:s){
        id[++ idx] = x;
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j <= idx;j ++){
            dp[id[j]/d[i]] = max(dp[id[j]/d[i]], id[j] * p[i] + dp[id[j]]);
        }
    }
    ll res = 0;
    for(int i = 0;i <= idx;i ++){
        res = max(res, dp[id[i]]);
    }
    printf("%lld",res);
    return;     
}
int main(){
    // //int t; cin>>t; while(t --)
    Solve();
    return 0;
}