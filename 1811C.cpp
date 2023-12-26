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
    vector<int> a(n + 1);
    rep(i, 2, n) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int> (2, 0));
    //dp[i][0/1]表示在这一位的贡献由i-1/i提供的合法状态
    dp[2][0] = 1;
    dp[2][1] = 1;
    for(int i = 3;i <= n;i ++){
        if(a[i] >= a[i - 1]){
            dp[i][1] |= dp[i - 1][1];
            dp[i][1] |= dp[i - 1][0];
            if(a[i] == a[i - 1]) dp[i][0] |= dp[i - 1][1];
        }else{
            dp[i][1] |= dp[i - 1][0];
            dp[i][0] |= dp[i - 1][0];
        }
    }
    vector<int> res(n + 1);
    int now = n, w = 0;
    if(!dp[now][w]) w = 1;
    for(int i = 2;i <= n;i ++, now --){
        if(w) res[now] = a[now];
        else res[now - 1] = a[now];
        if(a[now] >= a[now - 1]){
            if(w && dp[now - 1][1]){w = 1;continue;}
            if(w && dp[now - 1][0]){w = 0;continue;}
            if(a[now] == a[now - 1]){
                if(!w && dp[now - 1][1]){w = 1;continue;}
            }
        }else{
            if(w && dp[now - 1][0]){w = 0;continue;}
            if(!w && dp[now - 1][0]){w = 0;continue;}
        }
    }
    rep(i, 1, n) cout << res[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}