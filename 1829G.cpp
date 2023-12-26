/*
 * @Author: JorD
 * @LastEditTime: 2023-05-07 01:15:14
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
const int N = 3e6 + 10;
ll dp[N];
ll dfs(ll now){
    if(now < 1) return 0;
    if(dp[now]) return dp[now];
    ll w = now * now;
    int l = 1, r = 2023;
    while(l < r){
        ll mid = l + r >> 1;
        if((mid + 1) * mid / 2 >= now) r = mid;
        else l = mid + 1;
    }
    ll z = r, y = r - 1;
    r --;
    ll F = (r + 1) * r / 2;
    ll FF = r * (r - 1) / 2;
    dp[now] = w;
    r ++;
    if(F >= now - y && F >= now - z && now - y > FF && now - z > FF){
        dp[now] += - dfs(now - 2 * r + 2) + dfs(now - y) + dfs(now - z);
    }else{
        if(F >= now - z && now - z > FF) dp[now] += dfs(now - z);
        if(F >= now - y && now - y > FF) dp[now] += dfs(now - y);
    }
    return dp[now];
}
void Solve(){
    int n;
    cin >> n;
    cout << dfs(n) << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}