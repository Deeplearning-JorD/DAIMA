/*
 * @Author: JorD
 * @LastEditTime: 2022-10-20 18:05:00
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
const int N = 2e6 + 10;
int f[N], st[N];
vector<pair<ll,ll>> son[N];
map<pair<int,int>, int> CO;
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
int idx, id;
vector<int> idd;
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
ll dist[N], res1;
void dfs(int now, int fa){
    for(auto [x, w]:son[now]){
        if(x == fa||st[x] > 1) continue;
        dfs(x, now);
        res1 = max(res1, dist[now] + dist[x] + w);
        dist[now] = max(dist[now], dist[x] + w);    
    }
}
int idi[N], idb[N];
void Solve(){
    ll n;
    scanf("%lld", &n);
    rep(i, 0, n) f[i] = i;
    int need = 0;
    rep(i, 1, n){
        ll b, c;
        scanf("%lld%lld", &b, &c);
        if(CO[{i, b}]){
            auto &l = son[i][CO[{i, b}] - 1], &r = son[b][CO[{b, i}] - 1];
            ll w = max(l.second, c);
            l = {b, w};
            r = {i, w};
            continue;
        }
        son[i].push_back({b, c});
        son[b].push_back({i, c});
        CO[{i, b}] = ++ idi[i];
        CO[{b, i}] = ++ idi[b];
        f[find(i)] = find(b);
    }
    auto solve = [&](int u) -> ll{
        idx = 0;
        res1 = -1e18;
        id = -1;
        find_H(u, 0);
        if(!idx){
            dfs(u, 0);
            return res1;
        }
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
        per(i, idx, 1){
            y[i] = max(y[i + 1], dist[cir[i]] + v[idx] - v[i]);
            R[i] = max(R[i + 1], dist[cir[i]] - v[i] + last);
            last = max(last, dist[cir[i]] + v[i]);
            res1 = max(res1, max(max(L[i - 1], R[i]), z[i - 1] + y[i]));
        }
        return res1;
    };
    ll res = 0;
    vector<int> q(n + 1);
    rep(i, 1, n){
        if(!q[find(i)]){
            res += solve(i);
            q[find(i)] ++;
        }
    }
    printf("%lld", res);
    return;
}
int main(){
    freopen("344.in","r",stdin);
	freopen("344.out","w",stdout);
    Solve();
    fclose(stdin);
	fclose(stdout);
    return 0;
}