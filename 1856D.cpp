/*
 * @Author: JorD
 * @LastEditTime: 2023-08-06 00:05:10
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
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
    int n; cin >> n;
    ll last = 0;
    vector<int> id(n + 1);
    id[1] = 1;
    int idx = 1;
    for(int i = 2;i <= n;i ++, idx ++){
        cout << "? 1 " << i << endl;
        ll x; cin >> x;
        ll y = x; 
        x = x - last;
        for(int j = idx + 1, k = 1;k <= x;k ++, j --){
            id[j] = id[j - 1];
        }
        id[idx - x + 1] = i;
        last = y;
    }
    cout << "! " << id[n] << endl;
    return;
}
int main(){
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}