/*
 * @Author: JorD
 * @Date: 2023-11-24 22:44:08
 * @LastEditTime: 2023-11-24 23:31:35
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
    int mx = 0;
    set<int> s;
    rep(i, 1, n){
        int x; cin >> x;
        s.insert(x);
    }
    vector<int> v;
    for(int op = 0;op <= 30;op ++){
        if(s.size() == 1){
            cout << op << endl;
            if(v.size() && op <= n){
                for(auto x:v) cout << x << ' ';
                cout << endl;
            }
            return;
        }
        vector<int> ls;
        auto r = *s.rbegin();
        if(r % 2 == 0){
            v.push_back(1);
            for(auto x:s){
                ls.push_back((x+1)/2);
            }
        }else{
            v.push_back(0);
            for(auto x:s){
                ls.push_back(x/2);
            }
        }
        s.clear();
        for(auto x:ls) s.insert(x);
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}