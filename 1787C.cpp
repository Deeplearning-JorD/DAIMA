/*
 * @Author: JorD
 * @LastEditTime: 2023-01-30 00:23:53
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
const int N = 2e5 + 10;
ll dp[N][2];
void Solve(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    // memset(dp, 0, sizeof dp);
    int last = -1;
    for(int i = 0;i <= a[2];i ++){
        ll x = i, y = a[2] - i;
        if((x - s) * (y - s) < 0) continue;
        dp[i][0] = a[1] * x;
        // cout << x << ' ' << y << endl;
        if(last == -1) last = i;
        if(dp[last][0] > dp[i][0]) last = i;
    }
    cout << last << endl;
    cout << dp[last][0] << endl;
    int st = 0;
    for(int i = 2, j = 3;j < n;i ++,j ++){
        int now = -1;
        cout << "??????????????\n";
        cout << j << endl;
        for(int k = 0;k <= a[j];k ++){
            ll x = k, y = a[j] - k;
            if((x - s) * (y - s) < 0) continue;
            dp[k][(i + 1) & 1] = dp[last][i&1] + x * (a[j - 1] - last);
            if(now == -1) now = k;
            if(dp[now][(i + 1)&1]>=dp[k][(i + 1)&1])  now = k;
            cout << k << ' ' << dp[k][(i + 1)&1] << endl;
        }
        cout << now << ' ' << dp[now][(i + 1)&1] << endl;
        last = now;
        st = (i + 1) & 1;
        cout << st << endl;
    }
    cout << last << endl;
    cout << dp[last][st] + a[n] * (a[n - 1] - last) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}