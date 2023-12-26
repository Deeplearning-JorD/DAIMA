/*
 * @Author: JorD
 * @LastEditTime: 2023-04-20 19:23:24
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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> son(n + 1);
    vector<int> in(n + 1), id(n + 1);
    for(int i = 1;i <= m1;i ++){
        int x, y;
        cin >> x >> y;
        in[y] ++;
        son[x].push_back(y);
    }
    int idx = 0;
    queue<int> q;
    rep(i, 1, n)if(!in[i]){
        q.push(i);
        id[i] = ++ idx;
    }
    while(q.size()){
        auto t = q.front(); q.pop();
        for(auto x:son[t]){
            if(-- in[x] == 0){
                q.push(x);
                id[x] = ++ idx;
            }
        }
    }
    rep(i, 1, n)if(!id[i])id[i] = ++ idx;
    rep(i, 1, m2){
        int x, y;
        cin >> x >> y;
        if(id[x] < id[y]) cout << x << ' ' << y << endl;
        else cout << y << ' ' << x << endl;
    }
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}