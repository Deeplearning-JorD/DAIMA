/*
 * @Author: JorD
 * @LastEditTime: 2023-10-12 23:18:48
 * how to Get
 */
#pragma GCC optimize(2)
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
    int n; cin >> n;
    vector<vector<pair<int,int>>> nex(n + 1, vector<pair<int,int>> (n + 1));
    vector<vector<char>> f(n + 1, vector<char> (n + 1));
    vector<vector<bool>> vis(n + 1, vector<bool> (n + 1));
    int res = 0;
    rep(i, 1, n){
        rep(j, 1, n){
            cin >> f[i][j];
        }
    }
    for(int j = 1;j <= n;j ++){
        for(int i = n, j1 = 1;i >= 1;i --, j1 ++){
            nex[j][j1] = {i, j};
        }
    }
    rep(i, 1, n){
        rep(j, 1, n)if(!vis[i][j]){
            vector<char> c;
            int x = i, y = j;
            rep(k, 0, 3){
                vis[x][y] = true;
                c.push_back(f[x][y]);
                auto [L, R] = nex[x][y];
                x = L, y = R;
            }
            sort(c.begin(), c.end());
            char up = *c.rbegin();
            for(auto x:c){
                res += up - x;
            }
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}