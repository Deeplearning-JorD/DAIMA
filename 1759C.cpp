/*
 * @Author: JorD
 * @LastEditTime: 2022-11-18 23:02:47
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
    ll l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return;
    }
    if(abs(a - b) >= x){
        cout << 1 << endl;  
        return;
    }
    if(abs(a - l) >= x){
        if(abs(l - b) >= x){
            cout << 2 << endl;
            return;
        }
    }
    if(abs(a - r) >= x){
        if(abs(r - b) >= x){
            cout << 2 << endl;
            return;
        }
    }
    if(abs(a - l) >= x){
        if(abs(r - b) >= x){
            cout << 3 << endl;
            return;
        }
    }
    if(abs(a - r) >= x){
        if(abs(l - b) >= x){
            cout << 3 << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}