/*
 * @Author: JorD
 * @LastEditTime: 2022-11-21 14:41:07
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
    vector<vector<char>> f(n + 1, vector<char> (n + 1));
    rep(i, 1, n) rep(j, 1, n) cin >> f[i][j];
    vector<vector<int>> son(n + 1);
    vector<set<int>> res(n + 1);
    vector<int> in(n + 1);
    rep(i, 1, n) rep(j, 1, n){
        if(f[i][j] == '1'){
            son[i].push_back(j);
            in[j] ++;
        }
    }
    queue<int> q;
    int idx = 0;
    rep(i, 1, n){
        if(!in[i]){
            q.push(i);
        }
    }
    while(q.size()){
        auto t = q.front(); q.pop();
        idx ++;
        res[t].insert(idx);
        for(auto x:son[t]){
            if(!in[x]) continue;
            for(auto j:res[t]){
                res[x].insert(j);
            }
            in[x] --;
            if(!in[x]) q.push(x);
        }
    }
    for(int i = 1;i <= n;i ++){
        cout << (res[i].size()) << ' '; 
        for(auto x:res[i]) cout << x << ' ';
        cout << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t -- )
    Solve();
    return 0;
}