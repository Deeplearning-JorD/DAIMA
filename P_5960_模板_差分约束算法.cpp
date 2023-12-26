/*
 * @Author: JorD
 * @LastEditTime: 2023-07-11 04:55:17
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
    vector<int> d(n + 1);
    rep(i, 1, m){
        int x, y, c;
        cin >> x >> y >> c;
        son[y].push_back({x, c});
    }
    vector<int> dp(n + 1, 1e9);
    vector<bool> st(n + 1);
    queue<int> q;
    rep(i, 1, n) son[0].push_back({i, 0});
    dp[0] = 0;
    q.push(0);
    while(q.size()){
        auto t = q.front(); q.pop();
        st[t] = false;
        for(auto [x, y] : son[t]){
            if(dp[x] > dp[t] + y){
                dp[x] = dp[t] + y;
                d[x] ++;
                if(!st[x]){
                    st[x] = true;
                    q.push(x);
                }
                if(d[t] > n){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    int c = *min_element(dp.begin() + 1, dp.end());
    rep(i, 1, n) cout << dp[i] - c << ' ';
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}