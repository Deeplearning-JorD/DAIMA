/*
 * @Author: JorD
 * 使用[] >= [] + c的方法最长路，SPFA
 * @LastEditTime: 2023-07-11 03:47:54
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
        int x, y, c;
        cin >> x >> y >> c;
        son[x - 1].push_back({y, c});
        // y - [x - 1] >= c
        // y >= [x - 1] + c
    }
    rep(i, 1, n){
        // [i] - [i - 1] <= 1
        // [i - 1] >= [i] - 1
        // [i] - [i - 1] >= 0
        // [i] >= [i - 1]
        son[i].push_back({i - 1, - 1});
        son[i - 1].push_back({i, 0});
    }
    queue<int> q;
    vector<int> res(n + 1, - 1e9);
    vector<bool> st(n + 1);
    res[0] = 0;
    q.push(0);
    while(q.size()){
        auto now = q.front(); q.pop();
        st[now] = false;
        for(auto [x, y] : son[now]){
            if(res[now] + y > res[x]){
                res[x] = res[now] + y;
                if(!st[x]){
                    st[x] = true;
                    q.push(x);
                }
            }
        }
    }
    cout << res[n];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}