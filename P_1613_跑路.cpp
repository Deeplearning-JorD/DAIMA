/*
 * @Author: JorD
 * @LastEditTime: 2022-08-12 11:02:05
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
const int N = 100;
int f[N][N][N];
int dist[N][N];
void Solve(){
    int n, m;
    cin >> n >> m;
    memset(dist, 0x3f, sizeof dist);
    rep(i, 1, m){
        int a, b;
        cin >> a >> b;
        f[a][b][0] = 1;
        dist[a][b] = 1;
    }
    rep(ji,1,64)
    rep(k,1,n)
    rep(i,1,n)
    rep(j,1,n)
    if(f[i][k][ji-1]&f[k][j][ji-1])
    dist[i][j]=f[i][j][ji]=1;
    rep(k,1,n)
    rep(i,1,n)
    rep(j,1,n)
    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    cout<<dist[1][n]<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    Solve();
    return 0;
}