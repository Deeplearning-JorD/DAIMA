/*
 * @Author: JorD
 * @LastEditTime: 2023-01-20 10:57:47
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
const ll D = 2e5+10;
map<pair<int,int>,int> st;
void Solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> zson(n + 1);
    vector<vector<int>> son(n + 1);
    vector<int> d(n + 1);
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        d[x] ++;
        d[y] ++;
        zson[x].push_back(y);
    }
    rep(i, 1, n){
        for(auto x:zson[i]){
            if(d[x] < d[i]) son[x].push_back(i);
            else son[i].push_back(x);
        }
    }    
    vector<int> js(n + 1);
    while(q --){
        int k;
        cin >> k;
        int res = 0;
        vector<int> now(k + 1);
        rep(i, 1, k){
            cin >> now[i];
            js[now[i]] = 1;
        }
        rep(i, 1, k){
            for(auto x:son[now[i]]){
                res += js[x];
            }
        }
        rep(i, 1, k) js[now[i]] = 0;
        cout << res << endl;
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