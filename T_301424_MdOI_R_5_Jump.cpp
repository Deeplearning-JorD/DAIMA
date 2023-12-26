/*
 * @Author: JorD
 * @LastEditTime: 2022-12-31 16:57:10
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
    int n;
    cin >> n;
    ll sum = 0;
    if(n == 0){
        cout << 0 << endl;
    }
    for(ll i = 1, j = 1;j <= 30;j ++, i <<= 1){
        if(sum + i > n){
            if(n & 1){
                cout << j << endl;
                return;
            }
            sum -= i;
        }else{
            sum += i;
            if(sum == n){
                cout << j << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}