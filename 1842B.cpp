/*
 * @Author: JorD
 * @LastEditTime: 2023-06-24 22:17:21
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    int idx1 = n + 1, idx2 = n + 1, idx3 = n + 1;
    rep(i, 1, n){
        cin >> a[i];
        int now = a[i] | x;
        if(now > x && i < idx1){
            idx1 = i;
        }
    }
    rep(i, 1, n){
        cin >> b[i];
        int now = b[i] | x;
        if(now > x && i < idx2){
            idx2 = i;
        }
    }
    rep(i, 1, n){
        cin >> c[i];
        int now = c[i] | x;
        if(now > x && i < idx3){
            idx3 = i;
        }
    }
    int res = 0;
    rep(i, 1, idx1 - 1) res = res | a[i];
    rep(i, 1, idx2 - 1) res = res | b[i];
    rep(i, 1, idx3 - 1) res = res | c[i];
    if(res == x) cout << "Yes\n";
    else cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}