/*
 * @Author: JorD
 * @LastEditTime: 2023-03-28 13:20:48
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
const int N = 510;
ll a[N][N], pre[N][N];
ll get(int x, int y, int sx, int sy){
    return pre[sx][sy] + pre[x - 1][y - 1] - pre[x - 1][sy] - pre[sx][y - 1];
}
void Solve(){
    int n, m, d;
    scanf("%d%d%d",&n,&m,&d);
    rep(i, 1, n){
        rep(j, 1, m){
            scanf("%lld", &a[i][j]);
        }
    }
    rep(i, 1, n){
        rep(j, 1, m){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    ll res = 0;
    rep(i, 1, n){
        rep(j, i, n){
            int l = 1, r = 1;
            for(;r <= m;r ++){
                while(l <= r && get(i, l, j, r) > d) l ++;
                if(r >= l) res += max(0, r - l + 1);
            }
        }
    }
    printf("%lld",res);
    return;
}
int main(){
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}