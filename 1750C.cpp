/*
 * @Author: JorD
 * @LastEditTime: 2022-11-17 00:31:44
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
    string s, t;
    cin >> s >> t;
    set<int> q;
    vector<int> L(n + 2), R(n + 2);
    vector<pair<int,int>> res;
    int idx = 0;
    rep(i, 0, n - 1){
        idx += s[i] != t[i];
    }
    if(idx != n && idx != 0){
        cout << "NO\n";
        return;
    }
    idx = 0;
    if(s[1] != t[1]){
        res.push_back({1,n});
        s = t;
    }
    int id;
    for(int i = 0;i < n;i ++){
        if(s[i] == '1'){
            if(!i){
                res.push_back({1, n});
                res.push_back({2, n});
            }else{
                res.push_back({i + 1,i + 1});
                idx ++;
                id = i + 1;
            }
        }
    }
    if(idx & 1){
        res.pop_back();
        res.push_back({1, id});
        res.push_back({1, id - 1});
    }
    cout << "YES\n";
    cout << res.size() << endl;
    for(auto [x, y]:res){
        cout << x << ' ' << y << endl;
    }
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