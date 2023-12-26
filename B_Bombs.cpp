/*
 * @Author: JorD
 * @LastEditTime: 2023-03-25 20:08:31
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
    rep(i, 1, n) rep(j, 1, m) cin >> f[i][j];
    auto kun = [&](int x, int y, int k){
        rep(i, 1, n) rep(j, 1, m){
            if(abs(x - i) + abs(y - j) <= k){
                if(f[i][j] == '#') f[i][j] = '.';
            }
        }
    };
    rep(i, 1, n) rep(j, 1, m){
        if(f[i][j] <= '9' && f[i][j] >= '1'){
            kun(i, j, f[i][j] - '0');
            f[i][j] = '.';
        }
    }
    rep(i, 1, n) rep(j, 1, m){
        cout << f[i][j];
        if(j == m) cout << endl;
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