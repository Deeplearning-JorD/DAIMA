/*
 * @Author: JorD
 * @LastEditTime: 2023-05-24 19:06:28
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
const int N = 5e5 + 10;
int w[N];
int n, m;
void Solve(){
    cin >> n >> m;
    rep(i, 2, n){
        int x, y, z; cin >> x >> y >> z;
        w[x] ^= z;
        w[y] ^= z;
    }
    while(m --){
        int op; cin >> op;
        if(op == 1){
            int x, y, z; cin >> x >> y >> z;
            w[x] ^= z;
            w[y] ^= z;
        }else{
            int pos; cin >> pos; cout << w[pos] << endl;
        }
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