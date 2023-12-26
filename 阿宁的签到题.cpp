/*
 * @Author: JorD
 * @LastEditTime: 2023-02-03 13:05:43
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
    ll x; cin >> x;
    if(x <= 7) cout << "very easy";
    else if(x <= 233) cout << "easy";
    else if(x <= 10032) cout << "medium";
    else if(x <= 114514) cout << "hard";
    else if(x <= 1919810) cout << "very hard";
    else cout << "can not imagine";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)1111
    Solve();
    return 0;
}