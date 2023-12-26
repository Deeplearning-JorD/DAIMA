/*
 * @Author: JorD
 * @LastEditTime: 2023-05-03 19:40:01
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
typedef pair<int,int> pii;
void Solve(){
    int T, R, P, S;
    cin >> T >> R >> P >> S;
    vector<vector<pair<int,int>>> son(T + 1); 
    vector<vector<pair<int,int>>> zson(T + 1);
    vector<int> f(T + 1);
    rep(i, 1, T) f[i] = i;
    function<int(int)> find = [&](int x){
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    };
    rep(i, 1, R){
        int x, y, w;
        cin >> x >> y >> w;
        son[x].push_back({y, w});
        son[y].push_back({x, w});
        f[find(x)] = find(y);
    }
    vector<int> in(T + 1);
    rep(i, 1, P){
        int x, y, w;
        cin >> x >> y >> w;
        int fx = find(x), fy = find(y);
        zson[x].push_back({y, w});
        in[fy] ++;
    }
    vector<vector<int>> kid(T + 1);
    rep(i, 1, T)kid[find(i)].push_back(i); 
    vector<int> dist(T + 1, 2e9);
    vector<int> st(T + 1);
    queue<int> Q;
    rep(i, 1, T)if(!st[find(i)]&&!in[find(i)]){
        Q.push(find(i));
        st[find(i)] = 1;
    }
    st.clear();
    st.resize(T + 1);
    dist[S] = 0;
    while(Q.size()){
        auto t = Q.front(); Q.pop();
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for(auto x:kid[t]){
            q.push({dist[x], x});
        }
        while(q.size()){
            auto [i, now] = q.top(); q.pop();
            if(st[now]) continue;
            st[now] = 1;
            for(auto [x, w]:son[now]){
                if(dist[x] > dist[now] + w){
                    dist[x] = dist[now] + w;
                    q.push({dist[x], x});
                }
            }
        }
        for(auto x:kid[t]){
            for(auto [u, w]:zson[x]){
                dist[u] = min(dist[u], dist[x] + w);
                if(-- in[find(u)] == 0){
                    Q.push(find(u));
                }
            }
        }
    }
    rep(i, 1, T){
        if(dist[i] > 1e9) cout << "NO PATH\n";
        else cout << dist[i] << endl;
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