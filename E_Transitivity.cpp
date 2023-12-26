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
const int N = 2e3 + 10;
vector<int> son[N];
int res = 0;
int vis[N];
set<int> s;
void dfs(int now){
    res ++;
    vis[now] = 1;
    for(auto x:son[now])if(!vis[x]){
        dfs(x);
    }
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
    }
    rep(i, 1, n){
        memset(vis, 0, sizeof vis);
        vis[i] = 1;
        for(auto x:son[i])
            vis[x] = 1; 
        for(auto x:son[i])
        for(auto j:son[x])if(!vis[j]){
            dfs(j);
        }
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}