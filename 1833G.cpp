/*
 * @Author: JorD
 * @LastEditTime: 2023-05-19 23:54:07
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
    int n; cin >> n;
    vector<vector<pair<int,int>>> son(n + 1);
    rep(i, 1, n - 1){
        int x, y;
        cin >> x >> y;
        son[x].push_back({y, i});
        son[y].push_back({x, i});
    }
    bool st = true;
    vector<int> res;
    function<int(int,int)> dfs = [&](int now, int fa){
        int need = 1;
        bool use = false;
        for(auto [x, id]:son[now])if(x != fa){
            int down = dfs(x, now);
            if(down % 3 == 0){
                res.push_back(id);
                continue;
            }
            need += down;
        }
        if(need > 3) st = false;
        return need;
    };
    if(dfs(1, 0) % 3 != 0) st = false;
    if(!st){
        cout << - 1 << endl;
        return;
    }
    cout << res.size() << endl;
    for(auto x:res) cout << x << ' ';
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