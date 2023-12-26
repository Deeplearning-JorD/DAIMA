/*
 * @Author: JorD
 * @LastEditTime: 2022-09-09 00:48:27
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
// #define int long long
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
    int res = 0;
    priq<int> q, qq;
    rep(i, 1, n){
        int x;
        cin >> x;
        q.push(x);
    }
    rep(i, 1, n){
        int x;
        cin >> x;
        qq.push(x);
    }
    auto getlen = [&](int x){
        int len = 0;
        if(x==0) len++;
        while(x){
            len ++;
            x /= 10;
        }
        return len;
    };
    while(n){
        auto t1 = q.top(); q.pop();
        auto t2 = qq.top(); qq.pop();
        if(t1 == t2){
            n --;
            continue;
        }
        res ++;
        if(t1 > t2){
            t1 = getlen(t1);
        }else t2 = getlen(t2);
        q.push(t1);
        qq.push(t2);
    }
    cout << res << endl;
    return;
}
signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}