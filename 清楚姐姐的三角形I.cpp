/*
 * @Author: JorD
 * @LastEditTime: 2023-01-30 13:19:52
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
    ll va, vb, vc;
    cin >> va >> vb >> vc;
    ll a = vc + vb - va;
    a /= 2;
    ll c = vb - a;
    ll b = va - c;
    if(a + b > c && a + c > b && b + c > a&&c + b == va && a + c == vb && a + b == vc){
        cout << "Yes\n";
        cout << a << ' ' << b << ' ' << c << endl;
    }else cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}