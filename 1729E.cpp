/*
 * @Author: JorD
 * @LastEditTime: 2022-09-13 00:04:30
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
void Solve(){
    rep(i, 1, 25){
        cout << "? 1 ";
        cout << i + 1 << endl;
        ll x, y; cin >> x;
        cout << "? " << i + 1 << " 1" << endl;
        cin >> y;
        if(x == -1||y == -1){
            cout << "! " << i << endl;
            exit(0);
        }
        if(x != y){
            cout << "! " << x + y << endl;
            exit(0);
        }
    }
    
    
    return;
}
int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    
    Solve();
    return 0;
}