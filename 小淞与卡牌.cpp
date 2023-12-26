/*
 * @Author: JorD
 * @LastEditTime: 2022-12-06 12:37:30
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
    int n, p, k;
    cin >> n >> p >> k;
    ll res = 0, sum = 0;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    sort(all(v));
    reverse(all(v));
    rep(i, 0, k - 1) sum += v[i];
    vector<vector<int>> f(n + 1, vector<int> (p + 1));
    // f[i][j] 表示前i个人已经确定了j的状态
    总攻击力 = 攻击攻击力 + 防御攻击力 p个防御位 
    
    vector<bool> ues(n + 1);
    rep(i, 1, n) rep(j, 1, p) cin >> f[i][j];
    function<void(int,ll)> dfs = [&](int d, ll now){
        if(d == p + 1){
            res = max(res, sum + now);
            return;
        }
        rep(i, 1, n){
            if(ues[i]) continue;
            ues[i] = true;
            dfs(d + 1, now + f[i][d]);
            ues[i] = false;
        }
    };
    dfs(1,0);
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    return 0;
}