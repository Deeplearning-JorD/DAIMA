/*
 * @Author: JorD
 * @LastEditTime: 2023-03-11 14:27:07
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
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> son(n + 1);
    rep(i, 1, m){
        int x, y, z;
        cin >> x >> y >> z;
        son[x].push_back({y, z});
        son[y].push_back({x, z});
    }
    vector<int> dist1(n + 1, 1e9);
    vector<int> dist2(n + 1, 1e9);
    queue<int> q;
    dist1[1] = 0;
    dist2[1] = 1;
    q.push(1);
    // dist1 距离 dist2 城市数
    while(q.size()){
        auto t = q.front(); q.pop();
        for(auto [x, y]:son[t]){
            if(dist2[x] >= dist2[t] + 1 && dist1[x] > dist1[t] + y){
                dist2[x] = dist2[t] + 1;
                dist1[x] = dist1[t] + y;
                q.push(x);
            }
        }
    }
    cout << dist2[n] << ' ' << dist1[n];
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}