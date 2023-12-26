/*
 * @Author: JorD
 * @LastEditTime: 2022-12-31 22:20:11
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
    map<int,int> q;
    rep(i, 1, n){
        int x; cin >> x;
        q[x] ++;
    }
    int cnt = 0, js = 0;
    for(auto [x, y]:q){
        if(y == 1) cnt ++;
        else if(y > 2) js ++;
    }
    if(cnt % 2 == 0){
        cout << "YES\n";
    }else if(js) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}