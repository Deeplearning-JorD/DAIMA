/*
 * @Author: JorD
 * @LastEditTime: 2022-08-31 00:38:30
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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> f(n + 2, vector<char> (m + 2, '.'));
    vector<vector<bool>> st(n + 2, vector<bool> (m + 2));
    vector<vector<int>> vis(n + 2, vector<int> (m + 2));
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    int idx = 0;
    map<int,int> qq;
    function<void(int,int)> dfs = [&](int x,int y){
        if(x < 1||x > n||y < 1 || y > m|| st[x][y]) return;
        if(f[x][y] == '.') return;
        st[x][y] = true;
        vis[x][y] = idx;
        qq[idx] ++;
        dfs(x + 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
        dfs(x - 1, y);
    };
    rep(i, 1, n){
        rep(j, 1, m){
            if(f[i][j] == '*'&&!st[i][j]){
                idx ++;
                dfs(i, j);
                if(qq[idx] != 3){
                    cout << "NO" << endl;
                    return;
                }
            }
            if(f[i][j] == '*'){
                if(f[i-1][j]==f[i+1][j]&&f[i-1][j]=='*'){
                    cout << "NO" << endl;
                    return;
                }
                if(f[i][j-1]==f[i][j+1]&&f[i][j+1]=='*'){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    rep(i, 1, n){
        rep(j, 1, m){
            if(f[i][j] == '*'){
                rep(ii, i - 1, i + 1){
                    rep(jj , j - 1, j + 1){
                        if(vis[ii][jj] != vis[i][j] && f[i][j] == f[ii][jj]){
                            cout << "NO" << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
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