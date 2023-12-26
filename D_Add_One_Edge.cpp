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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 4e5 + 10;
int f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
void Solve(){
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector<vector<int>> son(n1 + n2 + 1);
    rep(i, 1, n1 + n2) f[i] = i;
    rep(i, 1, m){
        int x, y; cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
        f[find(x)] = find(y);
    }
    vector<int> dist(n1 + n2 + 1, 1e9);
    vector<bool> st(n1 + n2 + 1);
    dist[1] = dist[n1 + n2] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, 1});
    q.push({0, n1 + n2});
    while(q.size()){
        auto [w, t] = q.top(); q.pop();
        if(st[t]) continue;
        st[t] = true;
        for(auto x:son[t])if(dist[x] > dist[t] + 1){
            dist[x] = dist[t] + 1;
            q.push({dist[x], x});
        }
    }
    int l = 0, r = 0;
    rep(i, 1, n1 + n2){
        if(find(i) == find(1)){
            if(dist[i] != 1e9) l = max(dist[i], l);
        }else{
            if(dist[i] != 1e9) r = max(dist[i], r);
        }
    }
    cout << l + r + 1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}