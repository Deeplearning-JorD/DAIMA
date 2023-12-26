/*
 * @Author: JorD
 * @LastEditTime: 2023-01-08 18:19:55
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
const int N = 1e5 + 10;
ll q[N];
void Solve(){
    int n;
    cin >> n;
    ll sum = 0;
    rep(i, 1, n){
        int x; cin >> x;
        q[x] ++;
        sum += x;
    }
    cin >> n;
    while(n --){
        int x, y;
        cin >> x >> y;
        sum -= x * q[x];
        sum += q[x] * y;
        q[y] += q[x];
        q[x] = 0;
        cout << sum << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}