/*
 * @Author: JorD
 * @LastEditTime: 2023-01-25 11:09:25
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
    ll a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    ll A = a1, B = a1;
    if(a1 == 0){
        cout << 1 << endl;
        return;
    }
    if(a1 > 0) A += min(a2, a3) * 2;
    a4 += max(a2, a3) - min(a2, a3);
    A += min(a1 + 1, a4);
    cout << A << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}