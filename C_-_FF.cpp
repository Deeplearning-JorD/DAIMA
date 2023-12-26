/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 20:16:50
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
map<pair<int,int>, bool> st;
void Solve(){
    int n, m;
    cin >> n >> m;
    while(m --){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            st[{x, y}] = 1;
        }else if(op == 2){
            st[{x, y}] = 0;
        }else{
            if(st[{x, y}]&&st[{y, x}]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}