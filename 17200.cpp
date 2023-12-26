/*
 * @Author: JorD
 * @LastEditTime: 2022-08-19 12:39:47
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define int long long 
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
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
void Solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = 0;
    if(a == 0&& c==0){
        cout<<0<<endl;
        return;
    }
    if(a==0||c==0){
        cout<<1<<endl;
        return;
    }
    ll x = 1ll * a * d;
    ll y = 1ll * c * b;
    if(x == y) cout << 0 << endl;
    else if(x%y == 0 || y%x == 0) cout << 1 << endl;
    else cout << 2 << endl;
    return;
}
signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;

    while(t--)
    Solve();
    return 0;
}