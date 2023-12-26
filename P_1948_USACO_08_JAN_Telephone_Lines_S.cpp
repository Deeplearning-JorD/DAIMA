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
typedef pair<int,int> pii;
void Solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> son(n + 1);
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        son[x].push_back({y, z});
        son[y].push_back({x, z});
    }
    vector<vector<bool>> st(n + 1, vector<bool> (k + 1));
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, 1e9));
    // dp[i][j]表示从1到i经过了j条不花钱的边的最小代价
    dp[1][0] = 0;
    queue<pair<int,int>> q;
    q.push({1, 0});
    st[1][0] = 1;
    while(q.size()){
        auto [i, j] = q.front(); q.pop();
        st[i][j] = 0;
        for(auto [x, w]:son[i]){
            if(j < k){
                if(dp[x][j + 1] > dp[i][j]){
                    dp[x][j + 1] = dp[i][j];
                    
                }
            }
            if(dp[x][j] > max(dp[i][j], w)){
                dp[x][j] = max(dp[i][j], w);
                if(!st[x][j]){
                    q.push({x, j});
                }
            }
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}