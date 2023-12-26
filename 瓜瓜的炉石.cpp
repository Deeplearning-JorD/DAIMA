/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 13:59:55
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
ll f[51][51][3010];
ll res;
void Solve(){
    int n, A;
    cin >> n >> A;
    vector<int> a(n + 1);
    rep(i, 1, n)  cin >> a[i];
    for(int i = 1;i <= n;i ++){
        f[i][1][a[i]] = 1;
        for(int j = 1;j < i;j ++){
            for(int k = 1;k <= i;k ++){
                for(int sum = a[i];sum <= A * n;sum ++){
                    f[i][k][sum] += f[j][k - 1][sum - a[i]];
                }
            }
        }
        for(int j = 1;j <= n;j ++){
            res += f[i][j][j * A];
        }
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}