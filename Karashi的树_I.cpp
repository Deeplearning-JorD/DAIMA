/*
 * @Author: JorD
 * @LastEditTime: 2022-12-30 19:59:48
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
const int N = 3e5 + 10;
vector<int> son[N];
int f[N];
int siz[N];
void dfs(int now){
    siz[now] = 1;
    for(auto x:son[now]){
        dfs(x);
        siz[now] += siz[x];
    }
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n) cin >> f[i];
    vector<vector<int>> a(k + 1, vector<int> (m + 1));
    rep(i, 2, n){
        int fa; cin >> fa;
        son[fa].push_back(i);
    }
    dfs(1);
    sort(f + 1, f + 1 + n);
    sort(siz + 1, siz + 1 + n);
    ll res = 0;
    per(i, n, 1){
        res += 1ll * f[i] * siz[i];
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}