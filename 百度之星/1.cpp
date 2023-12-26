/*
 * @Author: JorD
 * @LastEditTime: 2023-08-10 16:28:42
 * how to Get
 */
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define pii pair<int,int>
const int N = 4e4 + 10;
vector<int> son[N], zson[N];
int dist[N], dt[N], df[N];
int te, fe, s;
int t, f, n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(dist, 0x3f, sizeof dist);
    memset(dt, 0x3f, sizeof dt);
    memset(df, 0x3f, sizeof df);
    cin >> te >> fe >> s >> t >> f >> n >> m;
    while(m --){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dist[n] = 0; 
    queue<int> q;
    q.push(n);
    while(q.size()){
        auto now = q.front(); q.pop();
        for(auto x:son[now]){
            if(dist[x] > dist[now] + 1){
                zson[now].push_back(x);
                dist[x] = dist[now] + 1;
                q.push(x);
            }
        }
    }
    if(dist[t] == 0x3f3f3f3f || dist[f] == 0x3f3f3f3f){
        cout << -1 << endl;
        return 0;
    }
    dt[t] = 0;
    q.push(t);
    while(q.size()){
        auto now = q.front(); q.pop();
        for(auto x:son[now]){
            if(dt[x] > dt[now] + 1){
                dt[x] = dt[now] + 1;
                q.push(x);
            }
        }
    }
    df[f] = 0;
    q.push(f);
    while(q.size()){
        auto now = q.front(); q.pop();
        for(auto x:son[now]){
            if(df[x] > df[now] + 1){
                df[x] = df[now] + 1;
                q.push(x);
            }
        }
    }
    ll res = 1e18;
    for(int i = 1;i <= n;i ++){
        ll tot = 1ll * (te + fe - s) * dist[i];
        tot += 1ll * dt[i] * te;
        tot += 1ll * df[i] * fe;
        res = min(res, tot); 
    }
    cout << res << endl;
    return 0;
}