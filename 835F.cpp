/*
 * @Author: JorD
 * @LastEditTime: 2023-03-18 22:56:59
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 2e5 + 10;
int st[N];
vector<pair<ll,ll>> son[N];
int id = -1, idx;
ll v[N], cir[N];
int find_H(int now, int fa){
    st[now] = 1;
    for(auto [ne, w]:son[now]){
        if(ne == fa) continue;
        if(st[ne]){
            id = ne;
            cir[++ idx] = now; 
            v[idx] = w;
            st[now] = 2;
            return 1;
        }
        if(find_H(ne, now)){ 
            cir[++ idx] = now;
            v[idx] = w;
            st[now] = 2;
            return now != id;
        }
    }
    return 0;
}
ll dist[N], res1, res2;
void dfs(int now, int fa){
    for(auto [x, w]:son[now]){
        if(x == fa||st[x] > 1) continue;
        dfs(x, now);
        res1 = max(res1, dist[now] + dist[x] + w);
        dist[now] = max(dist[now], dist[x] + w);    
    }
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n){
        ll a, b, c;
        cin >> a >> b >> c;
        son[a].push_back({b, c});
        son[b].push_back({a, c});
    }
    find_H(1, 0); 
    rep(i, 1, idx){
        dfs(cir[i], 0);
        v[i] += v[i - 1];
    }
    ll last = -1e18;
    vector<ll> L(idx + 2), R(idx + 2), z(idx + 2), y(idx + 2);
    L[0] = z[0] = -1e18;
    R[idx + 1] = L[idx + 1] = -1e18;
    rep(i, 1, idx){
        z[i] = max(z[i - 1], dist[cir[i]] + v[i]);
        L[i] = max(L[i - 1], dist[cir[i]] + v[i] + last);
        last = max(last, dist[cir[i]] - v[i]);
    }
    last = -1e18;
    per(i, idx, 0){
        y[i] = max(y[i + 1], dist[cir[i]] + v[idx] - v[i]);
        R[i] = max(R[i + 1], dist[cir[i]] - v[i] + last);
        last = max(last, dist[cir[i]] + v[i]);
    }
    res2 = 1e18;
    rep(i, 1, idx){
        res2 = min(res2, max(max(L[i - 1], R[i]), z[i - 1] + y[i]));
    }
    cout << max(res1, res2) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    Solve();
    return 0;
}