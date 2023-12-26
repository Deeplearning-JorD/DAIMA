/*
 * @Author: JorD
 * @Date: 2023-10-28 22:35:14
 * @LastEditTime: 2023-10-28 22:38:48
 * how to Get
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    int n; cin >> n;
    map<int,int> s;
    rep(i, 1, n){
        int x; cin >> x;
        s[x] ++;
    }
    if(s.size() == 1){
        cout << "Yes\n";
        return;
    }else if(s.size() == 2){
        int l = -1, r = -1;
        for(auto [x, y] : s){
            if(l == -1) l = y;
            else r = y;
        }
        if(abs(r - l) <= 1){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}