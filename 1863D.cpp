/*
 * @Author: JorD
 * @LastEditTime: 2023-08-31 00:03:13
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
    int n, m; cin >> n >> m;
    vector<int> h(n + 1), lie(m + 1);
    vector<vector<char>> f(n + 1, vector<char> (m + 1));
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++)if(f[i][j] != '.'){
            char x = f[i][j];
            if(x == 'R'){
                if(f[i][j - 1] == 'W') f[i][j] = 'B';
                else f[i][j] = 'W';
                continue;
            }
            if(x == 'D'){
                if(f[i - 1][j] == 'W') f[i][j] = 'B';
                else f[i][j] = 'W';
                continue;
            }
            if(x == 'L'){
                if(lie[j]) f[i][j] = 'B';
                else f[i][j] = 'W';
                lie[j] ^= 1; 
                continue;
            }
            if(x == 'U'){
                if(h[i]) f[i][j] = 'B';
                else f[i][j] = 'W';
                h[i] ^= 1;
                continue;
            }
        }
    }
    rep(i, 1, n)if(h[i]){
        cout << -1 << endl;
        return;
    }
    rep(j, 1, m)if(lie[j]){
        cout << -1 << endl;
        return;
    }
    rep(i, 1, n){
        rep(j, 1, m) cout << f[i][j];
        cout << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}