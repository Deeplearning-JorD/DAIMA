/*
 * @Author: JorD
 * @LastEditTime: 2022-08-12 19:27:00
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
const int N=1e6+10;
ll pre[N];
void Solve(){
    int n,m;
    cin >> n >> m;
    ll sum = 0;
    rep(i, 1, n){
        int l, r, c;
        cin >> l >> r >> c;
        pre[l]+=c;
        pre[r+1]-=c;
        sum += c;
    }
    rep(i, 1, m) pre[i]+=pre[i-1];
    ll res = 0;
    rep(i, 1, m){
        res = max(res, sum - pre[i]);
    }cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}