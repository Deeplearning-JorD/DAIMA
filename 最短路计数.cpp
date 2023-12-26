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
const int mod = 100003;
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> son(n + 1);
    rep(i, 1, m){
        int a, b;   
        cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    vector<int> dist(n + 1, 1e9), res(n + 1);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    dist[1] = 0;
    res[1] = 1;
    q.push({0, 1});
    while(!q.empty()){
        auto [o, now] = q.top(); q.pop();
        for(auto x:son[now]){
            if(dist[x] > dist[now] + 1){
                dist[x] = dist[now] + 1;
                res[x] = res[now];
                q.push({dist[x], x});
            }else if(dist[x] == dist[now] + 1)
                res[x] = (res[x] + res[now]) % mod;
        }
    }
    rep(i, 1, n) cout << res[i] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}