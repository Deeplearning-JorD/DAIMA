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
    int n, m;
    cin >> n >> m;
    vector<bool> tag(n + 1);
    rep(i, 1, m){
        int x; cin >> x;
        tag[x] = 1;
    }
    vector<vector<pair<int,int>>> son(n + 1);
    rep(i, 2, n){
        int x, y; cin >> x >> y;
        son[x].push_back({y, i});
        son[y].push_back({x, i});
    }
    // if(m == 1){
    //     cout << 0 << endl;
    //     return;
    // }
    vector<int> dist(n + 1), d(n + 1), vis(n + 1);
    //dist[i]表示从下到上经过i这条边到标记点的最大距离
    //d[i]表示i到子节点中最远标记点的最大距离。
    function<void(int,int)> dfs = [&](int now, int e){
        if(tag[now]){
            vis[now] = 1;
        }
        for(auto [x, y]:son[now])if(e != y){
            dfs(x, y);
            vis[now] = max(vis[now], vis[x]);
            if(vis[x]) dist[y] = max(dist[y], d[x] + 1);
            d[now] = max(dist[y], d[now]);
        }
    };
    dfs(1, 0);
    vector<int> mx(n + 1), up(n + 1);
    function<void(int,int)> dp = [&](int now, int e){
        mx[now] = max(d[now], up[now]);
        vector<int> val;
        for(auto [x, y]:son[now])if(y != e){
            val.push_back(dist[y]);
        }
        sort(val.begin(), val.end());
        int len = val.size();
        for(auto [x, y]:son[now])if(y != e){
            if(val.back() != dist[y]){
                if(up[now]||tag[now])
                up[x] = max(up[now] + 1, up[x]);
                if(val.back()||tag[now])
                up[x] = max(up[x], val.back() + 1);
                dp(x, y);
            }else{
                if(len > 1){
                    if(up[now]||tag[now])
                    up[x] = max(up[now] + 1, up[x]);
                    if(val[len - 2]||tag[now])
                    up[x] = max(up[x], val[len - 2] + 1);
                    dp(x, y);
                }else{
                    if(up[now]||tag[now])
                    up[x] = up[now] + 1;
                    dp(x, y);
                }
            }
        }
    };
    dp(1, 0);
    cout << *min_element(mx.begin() + 1, mx.end()) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}