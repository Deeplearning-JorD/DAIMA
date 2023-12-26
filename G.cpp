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
const int N = 4e5 + 10, inf = 1e9;
int n, m, k;
int idx;
map<int,int> mp;
vector<pair<int,int>> son[N]; 
vector<int> id[N], zson[N];
pair<int,int> w[N];
int cnt_id;
int iv[N];
bool vis[N];
void dfs(int now, int fa){
    if(vis[now]){
        cout << "NO\n";
        exit(0);
    }
    vis[now] = true;
    for(auto x:zson[now])if(x != fa){
        dfs(x, now);
    }
}
void Solve(){
    cin >> n >> m >> k;
    int cnt = 0;
    int col = 0;
    mp[0] = ++ cnt;
    mp[m + 1] = ++ cnt;
    for(int i = 0;i < k;i ++){
        int fa, x, y; cin >> x >> y >> fa;
        if(!mp[fa]) mp[fa] = ++ cnt;
        son[mp[fa]].push_back({x, y});
    }
    if(n == 1){
        cout << "YES\n";
        return;
    }
    int prey = 0, vv = 0;
    vector<int> ls;
    for(auto [u, v] : mp){
        if(u - prey > 2){
            cout << "NO\n";
            return;
        }else if(u - prey == 2){
            id[++ cnt].push_back(++ cnt_id);
            w[cnt_id] = {1, n};
            ls.push_back(cnt);
        }
        sort(son[v].begin(), son[v].end());
        int lasty = 0;
        for(auto [x, y] : son[v]){
            if(x - lasty > 1){
                id[v].push_back(++ cnt_id);
                w[cnt_id] = {lasty + 1, x - 1};
            }
            lasty = max(lasty, y);
        }
        if(n - lasty >= 1 && u >= 1 && u <= m){
            id[v].push_back(++ cnt_id);
            w[cnt_id] = {lasty + 1, n};
        }
        if(lasty) ls.push_back(v);
        prey = u;
    }
    auto check = [&](pair<int,int> a, pair<int,int> b){
        auto [x, y] = a;
        auto [sx, sy] = b;
        return min(y, sy) - max(x, sx);
    };
    for(int op = 1;op < ls.size();op ++){
        int l = ls[op - 1], r = ls[op];
        auto &d1 = id[l];
        auto &d2 = id[r];
        int i = 0, j = 0;
        while(i < d1.size() && j < d2.size()){
            int now = check(w[d1[i]], w[d2[j]]);
            if(now >= 1){
                cout << "NO\n";
                return;
            }else if(!now){
                zson[d1[i]].push_back(d2[j]);
                zson[d2[j]].push_back(d1[i]);
            }
            if(w[d1[i]].second >= w[d2[j]].second) j ++;
            else i ++;
        }
    }
    dfs(cnt_id, -1);
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    
    Solve();
    return 0;
}