/*
 * @Author: JorD
 * @LastEditTime: 2023-05-06 23:28:43
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
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    vector<int> l(n + 1), r(n + 1), up(n + 1);
    function<void(int,int)> dfs = [&](int now, int fa){
        for(auto x:son[now])if(x != fa){
            dfs(x, now);
            if(r[x] + 1 >= r[now]){
                l[now] = r[now];
                r[now] = r[x] + 1;
            }else if(r[x] + 1 > l[now]) l[now] = r[x] + 1;
        }
    };
    dfs(1, 0);
    int id = 1;
    auto dp = [&](auto self, int now, int fa){
        if(up[now] == r[now]){
            id = now;
            return;
        }
        for(auto x:son[now])if(x != fa){
            if(r[x] + 1 == r[now]){
                up[x] = max(up[now] + 1, l[now] + 1);
            }else up[x] = max(up[now] + 1, r[now] + 1);
            self(self, x, now);
        }
        return;
    };
    dp(dp, 1, 0);
    cout << son[id].size() << ' ' << siz(son[son[id][0]]) - 1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}