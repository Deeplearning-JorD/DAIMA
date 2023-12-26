#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> l(n), r(n), dp(n, n);
    for(int i = 0;i < n;i ++){
        cin >> l[i] >> r[i];
        l[i] = max(0, l[i] - 1);
        r[i] = max(0, r[i] - 1);
    }
    function<void(int)> dfs = [&](int now){
        if(!l[now]&&!r[now]){
            dp[now] = 0;
            return;
        }
        if(l[now]) dfs(l[now]);
        if(r[now]) dfs(r[now]);
        if(s[now] == 'L' && l[now]){
            dp[now] = min(dp[now], dp[l[now]]);
        }else if(l[now]) dp[now] = min(dp[now], dp[l[now]] + 1);
        if(s[now] == 'R' && r[now]){
            dp[now] = min(dp[now], dp[r[now]]);
        }else if(r[now]) dp[now] = min(dp[now], dp[r[now]] + 1);
        return;
    };
    dfs(0);
    cout << dp[0] << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}