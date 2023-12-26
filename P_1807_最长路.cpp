/*
 * @Author: JorD
 * @LastEditTime: 2023-05-02 17:20:18
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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> son(n + 1);
    vector<int> in(n + 1);
    while(m --){
        int x, y, w;
        cin >> x >> y >> w;
        son[x].push_back({y, w});
        in[y] ++;
    }
    vector<ll> dp(n + 1, -1);
    // dp[i]表示以i结尾的最长路径
    queue<int> q;
    rep(i, 2, n)if(!in[i]){
        q.push(i);
    }
    while(q.size()){
        auto now = q.front(); q.pop();
        for(auto [x, w]:son[now]){
            if(-- in[x] == 0) q.push(x);
        }
    }
    q.push(1);
    dp[1] = 0;
    while(q.size()){
        auto now = q.front(); q.pop();
        for(auto [x, w]:son[now]){
            dp[x] = max(dp[x], dp[now] + w);
            if(-- in[x] == 0) q.push(x);
        }
    }
    cout << dp[n];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}