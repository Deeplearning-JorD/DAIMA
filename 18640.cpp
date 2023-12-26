/*
 * @Author: JorD
 * @LastEditTime: 2023-08-26 22:37:23
 * how to Get
 */
#pragma GCC optimize(2)
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
    int x, y, n; cin >> x >> y >> n;
    if(n*(n-1)/2 > y - x){
        cout << -1 << endl;
        return;
    }
    vector<int> res(n + 1);
    res[1] = x; res[n] = y;
    for(int i = n - 1, j = 1;i > 1;i --, j ++){
        res[i] = res[i + 1] - j;
    }
    rep(i, 1, n) cout << res[i] << ' ';
    cout << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}