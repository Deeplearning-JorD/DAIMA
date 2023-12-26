/*
 * @Author: JorD
 * @LastEditTime: 2022-12-24 23:39:28
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
struct node{
    ll x, id, t;
    bool operator <(const node &ji) const{
        return x > ji.x;
    }
};
void Solve(){
    ll n, m, T;
    cin >> n >> m >> T;
    vector<ll> f(n + 1);
    vector<vector<pair<ll,ll>>> son(n + 1);
    rep(i, 1, n) cin >> f[i];
    rep(i, 1, m){
        ll a, b, c;
        cin >> a >> b >> c;
        son[a].push_back({b, c});
        son[b].push_back({a, c});
    }
    auto check = [&](ll mid){
        priority_queue<PII, vector<PII>, greater<PII>> q;
        vector<ll> dist(n + 1, 1e18);
        if(f[1] > mid) return false;
        q.push({0, 1});
        dist[1] = 0;
        while(q.size()){
            auto [o, now] = q.top(); q.pop();
            for(auto [x, w]:son[now]){
                if(f[x] > mid) continue;
                if(dist[x] > o + w){
                    dist[x] = o + w;
                    q.push({dist[x], x});
                } 
            }
        }
        return dist[n] <= T; 
    };
    ll l = 0, r = 2e9;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(l > 1e9) cout << "AFK" << endl;
    else
    cout << l << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}