/*
 * @Author: JorD
 * @LastEditTime: 2022-08-21 20:31:42
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
    vector<vector<char>> g(n + 1, vector<char> (m + 1));
    rep(i, 1, n)
    rep(j, 1, m) cin >> g[i][j];
    pair<int,int> t = {1, 1};
    vector<vector<bool>> st(n + 1, vector<bool> (m + 1));
    rep(k, 1, n * m){
        int i = t.first, j = t.second;
        st[i][j] = true;
        int x = 0, y = 0;
        if(g[i][j] == 'U') x --;
        if(g[i][j] == 'D') x ++;
        if(g[i][j] == 'L') y --;
        if(g[i][j] == 'R') y ++;
        x += i; y +=j;
        if(x < 1||y < 1||x > n||y > m){
            cout << i << ' ' << j <<endl;
            return;
        }
        if(st[x][y]){
            cout << -1 << endl;
            return;
        }
        t = {x, y};
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}