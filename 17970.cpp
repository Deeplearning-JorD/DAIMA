/*
 * @Author: JorD
 * @LastEditTime: 2023-04-08 22:09:52
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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
void Solve(){
    int n, m; cin >> n >> m;
    int x, y;
    cin >> x >> y;
    auto calc = [&](int x, int y){
        int res = 0;
        for(int i = 0;i < 4;i ++){
            int sx = x + dx[i], sy = y + dy[i];
            if(sx >= 1 && sx <= n && sy >= 1 && sy <= m) res ++;
        }
        return res;
    };    
    int res = calc(x, y);
    cin >> x >> y;
    res = min(res, calc(x, y));
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