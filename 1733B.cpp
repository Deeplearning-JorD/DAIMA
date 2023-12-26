/*
 * @Author: JorD
 * @LastEditTime: 2022-09-19 23:17:00
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
    int n, x, y;
    cin >> n >> x >> y;
    if(x < y) swap(x, y);
    if(y||!x){
        cout << -1 << endl;
        return;
    }
    n --;
    if(n%x == 0){
        int idx = 1;
        rep(i, 1, n/x){
            rep(j, 1, x) cout << idx << ' ';
            idx += x;
            if(i == 1) idx ++;
        }
        cout << endl;
    }else cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}