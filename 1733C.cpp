/*
 * @Author: JorD
 * @LastEditTime: 2022-09-20 00:08:14
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
    vector<ll> a(n + 1);
    rep(i, 1, n){
        int x; cin >> x;
        a[i] = x;
    }
    int idx = 0;
    vector<pair<int,int>> res;
    vector<bool> st(n + 1);
    if((a[1] + a[n])&1){
        st[1] = true;
        a[n] = a[1];
        if(1 != n)
        res.push_back({1, n});
        rep(i, 2, n - 1){
            if((a[i] + a[1])&1){
                st[i] = true;
                if(1 != i)
                res.push_back({1, i});
            }
        }
        rep(i, 2, n - 1){
            if(st[i]) continue;
            if(i != n)
            res.push_back({i, n});
        }
    }else{
        st[1] = true;
        a[1] = a[n];
        if(1 != n)
        res.push_back({1, n});
        rep(i, 2, n - 1){
            if((a[i] + a[1])&1){
                st[i] = true;
                if(1 != i)
                res.push_back({1, i});
            }
        }
        rep(i, 2, n - 1){
            if(st[i]) continue;
            if(i != n)
            res.push_back({i, n});
        }
    }

    cout << res.size() << endl;
    for(auto x:res) cout << x.first << ' ' << x.second << endl;
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