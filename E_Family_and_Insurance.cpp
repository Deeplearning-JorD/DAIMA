/*
 * @Author: JorD
 * @LastEditTime: 2023-07-08 20:52:34
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> son(n + 1);
    rep(i, 2, n){
        int fa; cin >> fa;
        son[fa].push_back(i);
        son[i].push_back(fa);
    }
    vector<int> d(n + 1);
    while(m --){
        int x, y;
        cin >> x >> y;
        d[x] = max(d[x], y);
    }
    vector<bool> st(n + 1);
    function<void(int,int,int)> dfs = [&](int now, int fa, int c){
        if(c || d[now]) st[now] = 1;
        for(auto x:son[now])if(x != fa){
            dfs(x, now, max(c - 1, d[now]));
        }
    };
    dfs(1, 0, 0);
    int res = 0;
    rep(i, 1, n) res += st[i];
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