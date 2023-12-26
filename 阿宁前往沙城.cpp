/*
 * @Author: JorD
 * @LastEditTime: 2023-02-03 16:28:22
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
vector<pair<int,int>> son[N];
int n, m;
bool st[N];
int dist[N];
int F = 1e9;
void Solve(){
    cin >> n >> m;
    rep(i, 1, m){
        int x, y, z;
        cin >> x >> y >> z;
        son[x].push_back({y, z});
        son[y].push_back({x, z});
        if(x == 1||y == 1) F = min(F, z);
    }
    int need = 0;
    memset(dist, 0x3f, sizeof dist);
    queue<pair<int,int>> q;
    q.push({0, 1});
    st[1] = true;
    dist[1] = 0;
    while(!q.empty()){
        auto [o, now] = q.front(); q.pop();
        for(auto [x, w]:son[now])if(!st[x]){
            st[x] = true;
            dist[x] = o + 1;
            q.push({dist[x], x});
        }
    }
    need = dist[n];
    if(need == m) cout << need - 1 + F << endl;
    else cout << need << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}