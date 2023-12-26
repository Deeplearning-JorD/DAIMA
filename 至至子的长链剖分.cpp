/*
 * @Author: JorD
 * @LastEditTime: 2022-08-19 19:55:17
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n; cin >> n;
    int maxn = 0;
    vector<vector<int>> last(n+1), son(n+1);
    vector<int> a(n+1);
    rep(i, 1, n){
        int x;
        cin >> x;
        last[x].push_back(i); 
        maxn = max(maxn, x);
    }
    vector<vector<int>> u(n+1);
    vector<bool> ji(n+1);
    vector<pair<int,int>> res;
    rep(i,0,n) u[i]=last[i];
    bool st = false;
    rep(i, 0, maxn - 1){
        if(st) break;
        for(auto x:u[i]){
            if(!last[i+1].size()){
                st = true;
                break;
            }
            int now = last[i + 1].back();
            son[now].push_back(x);
            son[x].push_back(now);
            res.push_back({now,x});
            // cout << now << "->" << x << endl; 
            if(last[i+1].size() > 1) last[i + 1].pop_back();
            else{ji[i+1] = 1; 
            // cout << "ji = " << i + 1<< endl;
             }
        }
    }
    rep(i, 1, maxn){
        if(!ji[i]){
            cout << -1 << endl;
            return;
        }
    }
    vector<bool> vis(n+1);
    function<void(int,int)> dfs = [&](int now,int fa){
        vis[now] = true;
        for(auto x:son[now]){
            if(vis[x] || x == fa) continue;
            dfs(x, now);
        }
    };
    dfs(1, 0);
    rep(i, 1, n){
        if(!vis[i]) st = true;
    }
    if(st){
        cout << -1 << endl;
        return;
    }
    cout << last[maxn].back() << endl;
    for(auto x:res) cout << x.first << ' ' << x.second << endl;
    
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}