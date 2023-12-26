#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define double long double
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
    vector<vector<pair<int, double>>> son(n + 1);
    rep(i, 1, m){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        double w = 1.0 * x - log2(y);
        son[u].push_back({v, w});
    }
    vector<bool> st(n + 1);
    vector<double> dist(n + 1, 1e9);
    priority_queue<pair<double, int>> q;
    q.push({0, 1});
    dist[1] = 0;
    while(q.size()){
        auto [t, now] = q.top(); q.pop();
        t = -t;
        if(st[now]) continue;
        st[now] = true;
        for(auto [x, w]:son[now])if(t + w < dist[x]){
            dist[x] = t + w;
            q.push({-(t + w), x});
        }
    }
    double mb = dist[n];
    cout << pow(2, mb) << endl;
    double l = 0, r = 1e9;
    rep(i, 1, 60){
        double mid = (l + r) / 2;
        if(log2(mid) < mb) l = mid;
        else r = mid;
    }
    cout << SPO(12) << l;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}