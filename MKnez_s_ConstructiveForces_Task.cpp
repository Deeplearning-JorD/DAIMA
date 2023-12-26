/*
 * @Author: JorD
 * @LastEditTime: 2023-01-04 03:24:17
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
    if(n == 3){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if(n % 2 == 0){
        rep(i, 1, n){
            if(i & 1) cout << 1 << ' ';
            else cout << -1 << ' ';
        }
        cout << endl;
        return;
    }
    int c = 3 - n, d = n - 1;
    rep(i, 1, n){
        if(i & 1) cout << c << ' ';
        else cout << d << ' ';
    }
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}