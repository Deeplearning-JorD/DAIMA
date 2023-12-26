/*
 * @Author: JorD
 * @LastEditTime: 2023-04-03 20:11:44
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
    vector<int> w(n + 1);
    rep(i, 1, n){
        cin >> w[i];
    }
    vector<vector<int>> son(n + 1);
    rep(i, 1, m){
        int x, y;
        cin >> x >> y; 
        son[x].push_back(y);
        son[y].push_back(x);
    }
    vector<bool> vis(n + 1);
    auto bfs = [&](int star){
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.push({0, star});
        int tot = 0;
        vector<bool> st(n + 1);
        st[star] = 1;
        while(q.size()){
            auto [need, now] = q.top(); q.pop();
            if(need > tot) break;
            vis[now] = 1;
            tot ++;
            for(auto x:son[now])if(!st[x]){
                st[x] = 1;
                q.push({w[x], x});
            }
        }
        return tot >= n;
    };
    rep(i, 1, n)if(!w[i] && !vis[i]){
        if(bfs(i)){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}