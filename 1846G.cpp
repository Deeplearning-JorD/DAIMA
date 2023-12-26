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
struct node{
    int l, f, w;
    // 治疗，增生，时间
};
void Solve(){
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    int x = 0;
    for(int i = 0;i < n;i ++){
        x |= (s[i] == '1') << i;
    }
    int mb = x;
    vector<node> use(m + 1);
    rep(i, 1, m){
        cin >> use[i].w;
        cin >> s;
        x = 0;
        for(int i = 0;i < n;i ++){
            x |= (s[i] == '0') << i;
        }
        use[i].l = x;
        x = 0;
        cin >> s;
        for(int i = 0;i < n;i ++){
            x |= (s[i] == '1') << i;
        }
        use[i].f = x;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<bool> vis(1 << n);
    vector<int> dist(1 << n, 1e9);
    dist[mb] = 0;
    q.push({0, mb});
    vis[mb] = 1;
    while(q.size()){
        auto [dd, t] = q.top(); q.pop();
        if(t == 0) break;
        for(int i = 1;i <= m;i ++){
            auto [l, f, w] = use[i];
            int now = (l & t) | f;
            if(dist[now] > dd + w){
                dist[now] = dd + w; 
                q.push({dist[now], now});
            }
        }
    }
    if(dist[0] == 1e9) cout << -1 << endl;
    else cout << dist[0] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}