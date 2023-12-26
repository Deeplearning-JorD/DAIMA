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
    vector<vector<int>> son(n + 1);
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
    }
    vector<int> dp(n + 1, -1);
    vector<int> st(n + 1);
    bool res = true;
    function<void(int,int)> dfs = [&](int now, int fa){
        st[now] = 1;
        for(auto x:son[now]){
            if(st[x]) continue;
            if(dp[x] == -1){
                dp[x] = dp[now] + 1;
                dfs(x, now);
            }else{
                if(dp[x] != dp[now] + 1){
                    res = false;
                    return;
                }
                dfs(x, now);
            }
        }
        st[now] = 0;
    };
    dp[1] = 0;
    dfs(1, 0);
    if(res) cout << "Yes\n";
    else cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}