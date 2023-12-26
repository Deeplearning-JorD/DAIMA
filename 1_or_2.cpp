/*
 * @Author: JorD
 * @LastEditTime: 2023-04-29 15:18:15
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
int n, m;
void Solve(){
    vector<int> d(n + 1);
    rep(i, 1, n) cin >> d[i];
    vector<int> in(n + 1);
    vector<bool> st(m + 1);
    vector<pair<int,int>> edge(m + 1);
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        in[x] ++;
        in[y] ++;
        edge[i] = {x, y};
    }
    for(int k = 1;k <= m;k ++){
        vector<int> now(n + 1);
        for(int i = 1;i <= m;i ++){
            auto [x, y] = edge[i];
            if(in[x] > d[x] && in[y] > d[y] && !st[i]){
                now[x] ++;
                now[y] ++;
            }
        }
        int id = 0;
        now[0] = 1e9;
        for(int i = 1;i <= n;i ++)if(in[i] > d[i] && now[i]){
            if(now[i] < now[id]){
                id = i;
            }
        }
        for(int i = 1;i <= m;i ++){
            auto [x, y] = edge[i];
            if(x == id || y == id){
                if(in[x] > d[x] && in[y] > d[y] && !st[i]){
                    in[x] --;
                    in[y] --;
                    st[i] = 1;
                    break;
                }
            }
        }
    }
    rep(i, 1, n){
        if(in[i] != d[i]){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    while(cin >> n >> m)
    Solve();
    return 0;
}