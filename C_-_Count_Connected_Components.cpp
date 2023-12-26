/*
 * @Author: JorD
 * @LastEditTime: 2023-01-07 20:17:43
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
    vector<vector<int>> son(n + 1);
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    } 
    int res = 0;
    vector<bool> st(n + 1); 
    function<void(int,int)> dfs = [&](int now, int fa){
        st[now] = true;
        for(auto x:son[now])if(!st[x]){
            dfs(x, now);
        }
    };
    rep(i, 1, n){
        if(st[i]) continue;
        res ++;
        dfs(i, 0);
    }
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