/*
 * @Author: JorD
 * @LastEditTime: 2022-12-08 18:52:10
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
    vector<int> s(6);
    rep(i, 1, 5) cin >> s[i];
    vector<vector<pair<int,int>>> son(n + 1);
    rep(i, 1, m){
        int x, y, w;
        cin >> x >> y >> w;
        son[x].emplace_back(y, w);
        son[y].emplace_back(x, w);
    }
    vector<vector<int>> dp(6, vector<int> (n + 1, 1e9));
    auto work = [&](int c){
        priority_queue<PII, vector<PII>, greater<PII>> q;
        dp[c][s[c]] = 0;
        q.push({0, s[c]});
        while(!q.empty()){
            auto [o, now] = q.top(); q.pop();
            for(auto [x, w]:son[now]){
                if(dp[c][x] > dp[c][now] + w){
                    dp[c][x] = dp[c][now] + w;
                    q.push({dp[c][x], x});
                }
            }
        }
    };
    rep(i, 1, 5) work(i);
    int res = 1e9;
    vector<int> v;
    rep(i, 0, 4) v.push_back(i + 1);
    do{
        int now = dp[v[0]][1];
        for(int i = 1;i < 5;i ++){
            now += dp[v[i]][s[v[i - 1]]];
        }
        res = min(res, now);
    }while(next_permutation(v.begin(), v.end()));
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