/*
 * @Author: JorD
 * @LastEditTime: 2022-11-25 19:54:39
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
    vector<vector<char>> f(n + 1, vector<char> (m + 1));
    vector<vector<char>> g(n + 1, vector<char> (m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
    vector<int> res(m + 1);
    vector<int> st(m + 1);
    vector<string> d(m + 1), d1(m + 1), dd(m + 1); 
    rep(i, 1, m){
        string now = "", now1 = "", noww = "";
        rep(j, 1, n){
            now += g[j][i];
            now1 += g[j][i] ^ 1;
            noww += f[j][i];
        }
        d[i] = now;
        d1[i] = now1;
        dd[i] = noww;
    }
    vector<bool> vis(m + 1);
    rep(i, 1, m){
        rep(j, 1, m){
            if(vis[j]) continue;
            if(d[i] == dd[j]){
                res[i] = j;
                st[i] = 0;
                vis[j] = true;
                break;
            }
            if(d1[i] == dd[j]){
                res[i] = j;
                st[i] = 1;
                vis[j] = true;
                break;
            }
        }
    }
    rep(i, 1, m) cout << res[i] << " \n"[i == m];
    rep(i, 1, m) cout << st[i] << " \n"[i == m];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}