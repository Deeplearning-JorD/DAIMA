/*
 * @Author: JorD
 * @LastEditTime: 2022-10-01 19:12:01
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
bool check(ll x){
    if(x<2) return false;
    for(ll i=2;i<=x/i;i++){
        if(x%i==0)
            return false;
    }
    return true;
}
void Solve(){
    ll n;
    cin >> n;
    if(n < 2||check(n)){
        cout << 1 << endl;
        return;
    }
    if(n % 2 == 0 || check(n - 2)) cout << 2 << endl;
    else cout << 3 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}