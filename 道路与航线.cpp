/*
 * @Author: JorD
 * @LastEditTime: 2022-12-22 14:37:14
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<int, int>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 3e4 + 10;
vector<PII> son[N];
int n, r, p, s;
int kid[N];
int dist[N], D[N];
bool st[N];
map<int,vector<int>> v;
void dfs(int now, int fa, int col){
    kid[now] = col;
    v[col].push_back(now);
    for(auto [x, y]:son[now]){
        if(x == fa||kid[x]) continue;
        dfs(x, now, col);
    }
} 
void Solve(){
    cin >> n >> r >> p >> s;
    rep(i, 1, r){
        int a, b, c;
        cin >> a >> b >> c;
        son[a].push_back({b, c});
        son[b].push_back({a, c});
    }
    int col = 0;
    vector<int> D(n + 1);
    rep(i, 1, n){
        if(kid[i]) continue;
        dfs(i, 0, ++ col);
    }
    rep(i, 1, p){
        int a, b, c;
        cin >> a >> b >> c;
        D[kid[b]] ++;
        son[a].push_back({b, c});
    }
    vector<int> dist(n + 1, 2e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    queue<int> qq;
    rep(i, 1, col){
        if(!D[i]) qq.push(i);
    }
    dist[s] = 0;
    while(qq.size()){
        auto t = qq.front(); qq.pop();
        for(auto x:v[t]){
            q.push({dist[x], x});
        }
        while(q.size()){
            auto [o, now] = q.top(); q.pop();
            if(st[now]) continue;
            st[now] = true;
            for(auto [x, w]:son[now]){
                if(kid[now] == kid[x]){
                    if(dist[x] > o + w){
                        dist[x] = o + w;
                        q.push({dist[x], x});
                    }
                }else{
                    D[kid[x]] --;
                    dist[x] = min(dist[x], o + w);
                    if(!D[kid[x]]) qq.push(kid[x]);
                }
            }
        }
    }
    rep(i, 1, n){
        if(dist[i] >= 1e9){
            cout << "NO PATH\n";
        }else cout << dist[i] << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    
    Solve();
    return 0;
}