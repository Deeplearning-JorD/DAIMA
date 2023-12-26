/*
 * @Author: JorD
 * @LastEditTime: 2022-09-04 20:22:18
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
    int n;
    cin >> n;
    priq<int> q;
    int minn = 1e9;
    rep(i, 1, n){
        int x; cin >> x;
        q.push(x);
        minn = min(minn, x);
    }
    int res = 0;
    while(q.size()){
        auto t = q.top(); q.pop();
        t %= minn;
        res ++;
        if(t == 0){
            continue;
        }
        minn = min(minn, t);
        q.push(t);
    }
    cout << res - 1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}