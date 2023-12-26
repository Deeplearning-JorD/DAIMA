/*
 * @Author: JorD
 * @LastEditTime: 2022-09-13 00:19:23
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
    string s;
    cin >> s;
    vector<vector<int>> ne(26);
    int idx = 0, r = 0, l = -1;
    for(auto x:s){
        idx ++;
        if(l == -1) l = x - 'a';
        ne[x - 'a'].push_back(idx);
        r = x - 'a';
    }
    int last = l;
    int w = 0;
    vector<int> res;
    if(l < r){
    rep(i, l, r){
        if(ne[i].empty()) continue;
        w += abs(i - last);
        for(auto x:ne[i]){
            res.push_back(x);
            last = i;
        }
    }
    }else{
        per(i, l, r){
            if(ne[i].empty()) continue;
            w += abs(i - last);
            for(auto x:ne[i]){
                res.push_back(x);
                last = i;
            }
        }
    }
    cout << w << ' ' << res.size() << endl;
    for(auto x:res) cout << x << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}