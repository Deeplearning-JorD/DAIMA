/*
 * @Author: JorD
 * @LastEditTime: 2022-12-03 12:50:06
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
ll a[10], b[10];
ll n;
ll res;
bool st[10];
void dfs(int dep){
    if(dep == 7){
        res = max(res, (b[1] + n * n * (b[2] + b[3] + b[4] * b[5])) / b[6]);
        return;
    }
    rep(i, 1, 6){
        if(!st[i]){
            st[i] = true;
            b[dep] = a[i];
            dfs(dep + 1);
            st[i] = false;
        }
    }
}
void Solve(){
    rep(i, 1, 6) st[i] = false;
    rep(i, 1, 6) cin >> a[i];
    cin >> n;
    res = 0;
    dfs(1);
    cout << res << endl; 
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}