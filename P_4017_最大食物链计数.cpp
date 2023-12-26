/*
 * @Author: JorD
 * @LastEditTime: 2023-05-02 18:39:02
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
const int mod = 80112002;
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> son(n + 1);
    vector<int> in(n + 1), out(n + 1);
    while(m --){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        in[y] ++;
        out[x] ++;
    }
    vector<int> dp(n + 1);
    queue<int> q;
    rep(i, 1, n)if(!in[i]){
        dp[i] = 1;
        q.push(i);
    }
    while(q.size()){
        auto now = q.front(); q.pop();
        for(auto x:son[now]){
            dp[x] = (dp[now] + dp[x]) % mod;
            if(-- in[x] == 0){
                q.push(x);
            }
        }
    }
    int res = 0;
    rep(i, 1, n)if(!out[i]){
        res = (res + dp[i]) % mod;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}