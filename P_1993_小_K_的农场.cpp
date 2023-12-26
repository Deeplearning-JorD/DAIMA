/*
 * @Author: JorD
 * 使用[] >= [] + c的方法最长路，SPFA
 * @LastEditTime: 2023-07-11 06:23:51
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
    int n, h;
    cin >> n >> h;
    vector<vector<pair<int,int>>> son(n + 1);
    rep(i, 1, h){
        int op, a, b, c; cin >> op;
        if(op == 1){
            cin >> a >> b >> c;
            son[a].push_back({b, -c});
        }else if(op == 2){
            cin >> a >> b >> c;
            son[b].push_back({a, c});
        }else{
            cin >> a >> b;
            son[a].push_back({b, 0});
            son[b].push_back({a, 0});
        }
    }
    queue<int> q;
    vector<int> res(n + 1);
    vector<bool> st(n + 1);
    rep(i, 1, n) q.push(i);
    vector<int> d(n + 1);
    while(q.size()){
        auto now = q.front(); q.pop();
        st[now] = false;
        for(auto [x, y] : son[now]){
            d[x] ++;
            if(res[now] + y < res[x]){
                res[x] = res[now] + y;
                if(!st[x]){
                    st[x] = true;
                    q.push(x);
                }
            }
            if(d[x] == n){
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}