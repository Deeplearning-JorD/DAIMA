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
    int n;
    cin >> n;
    vector<int> w(n + 1);
    vector<int> in(n + 1);
    vector<vector<int>> son(n + 1);
    rep(i, 1, n) cin >> w[i];
    rep(i, 1, n - 1){
        rep(j, 1, n - i){
            int x; cin >> x;
            if(!x) continue;
            son[i].push_back(i + j);
            in[i + j] ++;
        }
    }
    vector<int> dp(n + 1), last(n + 1, -1);
    // dp[i]表示i这个点能获得的最大价值 
    queue<int> q;
    rep(i, 1, n)if(!in[i]){
        dp[i] = w[i];
        q.push(i);
    }
    while(q.size()){
        auto now = q.front(); q.pop();
        for(auto x:son[now]){
            if(dp[now] + w[x] > dp[x]){
                dp[x] = dp[now] + w[x];
                last[x] = now;
            }
            if(-- in[x] == 0){
                q.push(x);
            }
        }
    }
    int res = 0;
    rep(i, 1, n) res = max(res, dp[i]);
    rep(i, 1, n)if(res == dp[i]){
        vector<int> v;
        int now = i;
        while(last[now] != -1){
            v.push_back(now);
            now = last[now];
        }
        v.push_back(now);
        reverse(v.begin(), v.end());
        for(auto x:v) cout << x << ' ';
        cout << endl;
        cout << res << endl;
        return;
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