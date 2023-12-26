/*
 * @Author: JorD
 * @Date: 2023-11-22 13:58:41
 * @LastEditTime: 2023-11-22 15:00:32
 * how to Get
 */
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
#define int long long
const int N = 5e5 + 10;
int q[N], qq[N];
void Solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n + 2);
    for(int i = 1;i <= n;i ++) cin >> a[i];
    vector<int> dp(n + 2), suf(n + 2), ls(n + 1);
    string s; cin >> s;
    int hh = 1, tt = 0;
    q[++ tt] = 0;
    // dp[i] 表示考虑前i个，并且第i个选择的最小代价
    for(int i = 1;i <= n + 1;i ++){
        while(hh <= tt && q[hh] < i - k) hh ++;
        dp[i] = dp[q[hh]] + a[i];
        if(i <= n && s[i - 1] == '1') tt = hh - 1;
        while(hh <= tt && dp[q[tt]] >= dp[i]) tt --;
        q[++ tt] = i;
    }
    hh = 1, tt = 0;
    q[++ tt] = n + 1;
    for(int i = n;i >= 1;i --){
        while(hh <= tt && q[hh] > i + k) hh ++;
        suf[i] = suf[q[hh]] + a[i];
        if(i <= n && s[i - 1] == '1') tt = hh - 1;
        while(hh <= tt && suf[q[tt]] >= suf[i]) tt --;
        q[++ tt] = i;
    }
    for(int i = 1;i <= n;i ++) suf[i] -= a[i];
    int m; cin >> m;
    while(m --){
        int id, w, old; cin >> id >> w;
        hh = 1, tt = 0;
        for(int i = max(0ll, id - k);i < id;i ++){            
            while(hh <= tt && dp[q[tt]] >= dp[i]) tt --;
            if(i > 0 && i <= n && s[i - 1] == '1') tt = hh - 1;
            q[++ tt] = i;
            qq[tt] = dp[i];
        }
        int res = 1e18;
        old = a[id];
        a[id] = w;
        for(int i = id;i <= min(n + 1, id + k);i ++){
            while(hh <= tt && q[hh] < i - k) hh ++;
            int now = qq[hh] + a[i];
            res = min(res, now + suf[i]);
            if(i > 0 && i <= n && s[i - 1] == '1') tt = hh - 1;
            while(hh <= tt && qq[hh] >= now) tt --;
            q[++ tt] = i;
            qq[tt] = now;
        }
        a[id] = old;
        cout << res << endl;
    }
    return;
}
#undef int
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}