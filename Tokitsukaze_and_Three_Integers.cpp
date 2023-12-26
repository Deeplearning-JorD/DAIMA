/*
 * @Author: JorD
 * @LastEditTime: 2023-01-18 15:38:31
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
int a[N];
void Solve(){
    int n, p;
    cin >> n >> p;
    vector<int> last(p), pre(p), rc(p), sum(p);
    rep(i, 1, n){
        cin >> a[i];
        last[a[i] % p] ++;
    }
    rep(i, 1, n){
        rep(j, 1, n)if(i != j){
            int pp = a[i] * a[j];
            pre[pp % p] ++;
            rc[(pp + a[i]) % p] ++;
            rc[(pp + a[j]) % p] ++;
        }
    }
    rep(i, 0, p - 1) rep(j, 0, p - 1)
    sum[(i + j) % p] += pre[i] * last[j];
    rep(i, 0, p - 1){
        sum[i] -= rc[i];
    }
    rep(i, 0, p - 1) cout << sum[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    
    Solve();
    return 0;
}