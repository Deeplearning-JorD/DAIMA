/*
 * @Author: JorD
 * @LastEditTime: 2023-05-19 14:55:36
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
const int N = 2e5 + 10;
int a[3][N];
void Solve(){
    int n; cin >> n;
    rep(i, 1, n) rep(j, 0, 2) cin >> a[j][i];
    ll res = 0, sum;
    int num;
    for(auto x : {-1, 1}){
        for(auto y : {-1, 1}){
            for(auto z : {-1, 1}){
                sum = 0;
                for(int i = 1;i <= n;i ++){
                    num = x * a[0][i] + y * a[1][i] + z * a[2][i];
                    if(num > 0) sum += num;
                }
                res = max(res, sum);
            }
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}