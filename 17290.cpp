/*
 * @Author: JorD
 * @LastEditTime: 2022-09-25 22:00:35
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
    ll a, b, c;
    cin >> a >> b >> c;
    ll w1 = abs(a - 1);
    ll w2;
    if(c == 1){
        w2 = abs(b - c);
        
    }else w2 = abs(b - c) + abs(c - 1);
    if(w1 < w2) cout << 1 << endl;
    else if(w1 == w2) cout << 3 << endl;
    else cout << 2 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}