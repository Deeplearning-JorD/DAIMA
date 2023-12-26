/*
 * @Author: JorD
 * @LastEditTime: 2022-12-18 04:04:56
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
const int N = 2e5 + 10;
int depth[N], d;
set<int> m1, m2;
vector<int> son[N];
int n;
int up[N];
void dfsdeep(int now, int fa, int dist){
    depth[dist] = now;
    if(dist <= d) up[now] = 1;
    else up[now] = depth[dist - d];
    for(auto x:son[now]){
        if(x == fa) continue;
        dfsdeep(x, now, dist + 1);
    }
}
int dp[N];
int res = 0;
bool dfs1(int now, int fa){
    dp[now] = 0;
    bool st = m1.count(now)?1:0;
    for(auto x:son[now]){
        if(x == fa) continue;
        if(dfs1(x, now)){
            dp[now] += 1 + dp[x];
            st = true;
        }   
    }
    return st; 
}
bool dfs2(int now, int fa){
    dp[now] = 0;
    bool st = m2.count(now)?1:0;
    for(auto x:son[now]){
        if(x == fa) continue;
        if(dfs2(x, now)){
            dp[now] += 1 + dp[x];
            st = true;
        }   
    }
    return st;     
}
void Solve(){
    cin >> n >> d;
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    dfsdeep(1, 0, 0);
    int m; cin >> m;
    rep(i, 1, m){
        int x; cin >> x;
        m1.insert(x);
    }
    cin >> m;
    rep(i, 1, m){
        int x; cin >> x;
        m2.insert(x);
    }
    auto ls = m2;
    for(auto x:m1){
        m2.insert(up[x]);
    }
    for(auto x:ls){
        m1.insert(up[x]);
    }
    dfs1(1, 0);
    res += dp[1];
    dfs2(1, 0);
    res += dp[1];
    cout << (res << 1) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}