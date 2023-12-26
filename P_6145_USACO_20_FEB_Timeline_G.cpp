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
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> dp(n + 1);
    rep(i, 1, n) cin >> dp[i];
    vector<vector<pair<int,int>>> son(n + 1);
    vector<int> d(n + 1);
    rep(i, 1, c){
        int x, y, c;
        cin >> x >> y >> c;
        son[x].push_back({y, c});
        d[y] ++;
    }
    queue<int> q;
    rep(i, 1, n)if(!d[i])q.push(i);
    while(q.size()){
        auto t = q.front(); q.pop();
        for(auto [x, y]:son[t]){
            dp[x] = max(dp[x], dp[t] + y);
            if(-- d[x] == 0){
                q.push(x);
            }
        }
    }
    rep(i, 1, n) cout << dp[i] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}