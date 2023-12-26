/*
 * @Author: JorD
 * @LastEditTime: 2022-09-24 20:14:50
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
    ll x, y , z;
    cin >> x >> y >> z;
    if(x * y > 0){
        if(abs(x) < abs(y)) cout << abs(x) << endl;
        else if(z * y > 0){
            if(abs(z) < abs(y)){
                cout << abs(z) + abs(z - x);
            }else cout << -1 << endl;
        }else{
            cout << abs(z) * 2 + abs(x);
        }
    }else cout << abs(x) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}