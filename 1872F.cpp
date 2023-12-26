/*
 * @Author: JorD
 * @LastEditTime: 2023-09-08 22:36:39
 * how to Get
 */
#pragma GCC optimize(2)
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
    int n; cin >> n;
    vector<int> ne(n + 1), c(n + 1), d(n + 1), a(n + 1), f(n + 1);
    vector<vector<pair<int,int>>> son(n + 1);
    rep(i, 1, n){
        int x; cin >> x;
        d[x] ++; 
        son[x].push_back({i, i});
        son[i].push_back({x, i});
        ne[i] = x;
    }
    rep(i, 1, n) cin >> c[i];
    c[0] = 2e9;
    int idx = 0;
    function<void(int,int)> dfs = [&](int i, int e){
        if(f[i]){
            if(f[i] == -1) return;
            int id = 0;
            for(int j = f[i];j <= idx;j ++){
                if(c[id] > c[a[j]]) id = a[j];
            }
            d[ne[id]] --;
            return;
        }
        a[++ idx] = i;
        f[i] = idx;
        for(auto [x, y]:son[i])if(y != e){
            dfs(x, y);
        }
        idx --;
        f[i] = -1;
    };
    rep(i, 1, n) if(!f[i])dfs(i, 0);
    queue<int> q;
    rep(i, 1, n) if(!d[i]) q.push(i);
    while(q.size()){
        auto t = q.front(); q.pop();
        cout << t << ' ';
        if(-- d[ne[t]] == 0) q.push(ne[t]);
    }
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