/*
 * @Author: JorD
 * @LastEditTime: 2023-09-06 00:34:49
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
    int n, k; cin >> n >> k;
    set<int> s;
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        s.insert(a[i]);
    }
    if(s.size() > k){
        cout << -1 << endl;
        return;
    }
    vector<int> id(n + 1), ls, res;
    rep(i, 1, n){
        if(!id[a[i]]){
            ls.push_back(a[i]);
            id[a[i]] = ls.size();
        }
    }
    rep(i, 1, n){
        if(ls.size() == k) break;
        if(!id[i]){
            ls.push_back(i);
            id[i] = ls.size();
        }
    }
    int m = ls.size(), idx = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < m;j ++, idx ++){
            idx %= m;
            res.push_back(ls[idx]);
            if(ls[idx] == a[i]){
                idx ++;
                break;
            }
        }
    }
    cout << res.size() << endl;
    for(auto x:res) cout << x << ' ';
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