/*
 * @Author: JorD
 * @LastEditTime: 2023-05-07 14:11:07
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
const int N = 210, D = 100;
int f[N][N];
void Solve(){
    int n;
    cin >> n;
    int l = 1e9, r = -1e9, up = -1e9, down = 1e9;
    rep(i, 1, n){
        int x, y;
        cin >> x >> y;
        l = min(l, x);
        r = max(r, x);
        up = max(up, y);
        down = min(down, y);    
        f[D + x][D + y] = 1;
    }
    if(l > 0 || r < 0 || up < 0 || down > 0){
        cout << "-1" << endl;
        return;
    }
    int need = (r - l + 1) * (up - down + 1);
    rep(i, l + D, r + D) rep(j, down + D, up + D)
    need -= f[i][j];
    if(need) cout << -1 << endl;
    else cout << up - down + r - l << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}