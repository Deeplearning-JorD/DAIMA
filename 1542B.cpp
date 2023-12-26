/*
 * @Author: JorD
 * @Date: 2023-09-07 19:43:43
 * @LastEditTime: 2023-11-28 15:30:52
 * how to Get
 */
#pragma GCC optimize(2)
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
    int n, a, b; cin >> n >> a >> b;
    if(a == 1){
        if(0 == (n - 1) % b) cout << "Yes\n";
        else cout << "No\n";
    }else{
        ll x = 1;
        while(x <= n){
            if(x % b == n % b){
                cout << "Yes\n";
                return;
            }
            x *= a;
        }
        cout << "No\n";
    }
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}