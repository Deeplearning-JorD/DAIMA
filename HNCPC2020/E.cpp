/*
 * @Author: JorD
 * @LastEditTime: 2023-04-05 14:51:34
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
struct node{
    int cnt, w;
};
void Solve(){
    int n, k;
    map<int, node> q;
    cin >> n >> k;
    rep(i, 1, n){
        int a, b, c;
        cin >> a >> b >> c;
        q[a].cnt ++;
        q[a].w ^= c;
        q[b + 1].cnt --;
        q[b + 1].w ^= c;
    }
    int num = 0, res = -1, w = 0;
    for(auto [x, u]:q){
        num += u.cnt;
        w ^= u.w;
        if(num >= k) res = max(res, w);
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}