/*
 * @Author: JorD
 * @LastEditTime: 2023-01-11 23:43:17
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
    ll idx1 = 0, idx2 = 0;
    rep(i, 1, n){
        int x; cin >> x;
        if(x > 0){
            idx2 += x;
            idx1 = max(0ll, idx1 - x);
        }else{
            x = -x;
            idx1 += x;
            idx2 = max(0ll, idx2 - x);
        }
    }
    cout << idx1 + idx2 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}