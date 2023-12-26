/*
 * @Author: JorD
 * @LastEditTime: 2023-04-20 20:28:24
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
    vector<int> in(n + 1), cnt(n + 1);
    rep(i, 1, m){
        int x, y, z;
        cin >> x >> y >> z;
        son[y].push_back({x, z});
        in[x] ++;
        cnt[x] ++;
    }
    vector<double> dp(n + 1);
    queue<int> q;
    rep(i, 1, n)if(!in[i])q.push(i);
    while(q.size()){
        auto t = q.front(); q.pop();
        for(auto [x, w]:son[t]){
            if(-- in[x] == 0){
                q.push(x);
            }
            dp[x] += (dp[t] + w) / cnt[x];
        }
    }
    cout << SPO(2) << dp[1] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}