/*
 * @Author: JorD
 * @LastEditTime: 2023-03-09 18:01:10
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
    int n;
    cin >> n;
    int odd = 0, even = 0;
    int now = 0, last = 0, ls = 0, gs = 0;
    int res = 0;
    rep(i, 1, n){
        int x; cin >> x;
        if(x == 2){
            gs += now;
            if(gs)
            last = gs / 2 + 1;
            now = 0;
        }else{
            now ++;
        }
        res = max(res, last + now);
    }
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