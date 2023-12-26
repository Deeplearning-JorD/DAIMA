/*
 * @Author: JorD
 * @LastEditTime: 2022-12-07 22:54:16
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
    int m, n;
    cin >> m >> n;
    vector<set<int>> son(n + 1);
    rep(i, 0, m){
        string s;
        getline(cin, s);
        if(!i) continue;
        vector<int> v;
        int now = 0;
        for(auto x:s){
            if(x == ' '){
                v.push_back(now);
                now = 0;
                continue;
            }
            now = now * 10 + x - '0';
        }
        v.push_back(now);
        for(int j = 0;j < siz(v);j ++){
            for(int k = j + 1;k < siz(v);k ++){
                son[v[j]].insert(v[k]);
            }
        }
    }
    priority_queue<PII, vector<PII>, greater<PII>> qq;
    vector<int> dist(n + 1, 2e9);
    dist[1] = 0;
    qq.push({0, 1});
    while(!qq.empty()){
        auto [o, now] = qq.top(); qq.pop();
        for(auto x:son[now]){
            if(dist[x] > dist[now] + 1){
                dist[x] = dist[now] + 1;
                qq.push({dist[x], x});
            }
        }
    }
    int res = 1e9;
    res = min(res, dist[n]);
    if(res == 1e9) cout << "NO\n";
    else    cout << max(res - 1, 0) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}