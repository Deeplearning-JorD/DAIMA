/*
 * @Author: JorD
 * @LastEditTime: 2022-12-07 14:51:09
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
    int n, p, c;
    cin >> n >> p >> c;
    vector<int> num(p + 1);
    rep(i, 1, n){
        int x; cin >> x;
        num[x] ++;
    }
    vector<vector<pair<int,int>>> son(p + 1);
    rep(i, 1, c){
        int a, b, c;
        cin >> a >> b >> c;
        son[a].emplace_back(b, c);
        son[b].emplace_back(a, c);
    }
    auto work = [&](int s){
        // dist[i]表示第i个牧场中如果只有一个的奶牛走到s所需要的最短路程。
        vector<int> dist(p + 1, 1e9);    
        priority_queue<PII, vector<PII>, greater<PII>> q;
        dist[s] = 0;
        q.emplace(0, s);
        while(!q.empty()){
            auto [o, now] = q.top(); q.pop();
            for(auto [x, w]:son[now]){
                if(dist[x] > dist[now] + w){
                    dist[x] = dist[now] + w;
                    q.emplace(dist[x], x); 
                }
            }
        }
        ll all = 0;
        for(int i = 1;i <= p;i ++){
            all += dist[i] * num[i];
        }
        return all;
    }; 
    ll res = 1e18;
    rep(i, 1, p) res = min(res, work(i));
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}