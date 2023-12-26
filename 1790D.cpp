/*
 * @Author: JorD
 * @LastEditTime: 2023-01-27 23:58:34
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
    map<int,int>q;
    rep(i, 1, n){
        int x; cin >> x;
        q[x] ++;
    }
    int res = 0;
    int now = 0, last = -1;
    for(auto [x, y]:q){
        if(x != last + 1){
            res += now;
            now = y;
            last = x;
            continue;
        }
        last = x;
        if(now > y){
            res += now - y;
            now = y;
        }else if(now < y){
            now += y - now;
        }
    }
    res += now;
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}