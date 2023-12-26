/*
 * @Author: JorD
 * @LastEditTime: 2023-04-09 02:33:54
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
    int n, m;
    cin >> n >> m;
    cout << "? 1 1" << endl;
    int x; cin >> x;
    int l1, r1, l2, r2, l3, r3;
    l1 = 1 + x, r1 = 1 + x;
    if(l1 > n && r1 <= m){
        cout << "? " << 1 << ' ' << r1 << endl;
        cin >> x;
        cout << "! " << 1 + x << ' ' << r1 << endl;
        return;
    }
    if(l1 <= n && r1 > m){
        cout << "? " << l1 << ' ' << 1 << endl;
        cin >> x;
        cout << "! " << l1 << ' ' << 1 + x << endl;
        return;
    }
    cout << "? " << 1 << ' ' << r1 << endl;
    cin >> x;
    if(1 + x == l1){
        cout << "? " << l1 << ' ' << 1 << endl;
        cin >> x;
        cout << "! " << l1 << ' ' << 1 + x << endl;
    }else cout << "! " << 1 + x << ' ' << r1 << endl;
    cout << endl;
    return;
}
int main(){
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}