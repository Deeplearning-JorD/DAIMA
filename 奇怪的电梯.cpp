/*
 * @Author: JorD
 * @LastEditTime: 2022-09-16 19:31:05
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
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    if(a == b){
        cout << "YES\n";
        return;
    }
    if(abs(a - b) > k){
        cout << "YES\n";
        return;
    }
    if(a - k > 1||a + k < n){
        if(abs(b - 1) > k||abs(b - n) > k){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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