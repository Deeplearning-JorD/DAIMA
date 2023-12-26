/*
 * @Author: JorD
 * @LastEditTime: 2023-07-28 20:28:38
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> row(n + 1), col(m + 1);
    vector<tuple<string,int,string>> T(q);
    for(auto &[a, b, c] : T) cin >> a >> b >> c;
    reverse(T.begin(), T.end());
    int r = 0, c = 0;
    ll res = 0;
    for(auto [A, i, C] : T){
        if(A == "row"){
            if(row[i]) continue;
            row[i] = 1;
            r ++;
            if(C == "on")
                res += m - c;
        }else{
            if(col[i]) continue;
            col[i] = 1;
            c ++;
            if(C == "on")
                res += n - r;
        }
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