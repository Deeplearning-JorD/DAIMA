/*
 * @Author: JorD
 * @LastEditTime: 2022-09-24 21:46:46
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
const int N = 1e4 + 10;
int f[110][N][2];
void Solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k + 1);
    rep(i, 1, k) cin >> a[i];
    //   f[i][j][1]表示 枚举到第j个时还剩下i个石头时高桥军取到的石头数量
    per(i, k, 1){
        for(int j = n; j >= 0; j --){
            if(j + a[i] <= n){
            f[i][j][1] = max({f[i][j + a[i]][0] + a[i], f[i + 1][j + a[i]][0] + a[i], f[i + 1][j][1]});
            f[i][j][0] = min({f[i][j + a[i]][1] + a[i], f[i + 1][j + a[i]][1] + a[i], f[i + 1][j][0]});            
            }
            else{
                f[i][j][1] = f[i + 1][j][1];
                f[i][j][0] = f[i + 1][j][0];           
            }
        }
    }
    int res = 0;
    rep(i, 1, k){
        res = max(f[i][0][1], res);
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}