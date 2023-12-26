/*
 * @Author: JorD
 * @LastEditTime: 2023-10-14 20:05:24
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
    int n; cin >> n;
    string t; cin >> t;
    int len = t.size();
    vector<int> res;
    rep(id, 1, n){
        string s; cin >> s;
        int m = s.size();
        if(m == len){
            int cnt = 0;
            for(int i = 0;i < len;i ++){
                cnt += s[i] != t[i];
            }
            if(cnt <= 1) res.push_back(id);
            continue;
        }
        if(m == len + 1){
            bool can = 1;
            for(int i = 0;i < len;i ++){
                if(t[i] == s[i]) continue;
                if(s.substr(i + 1) != t.substr(i)) can = false;
                break;
            }
            if(can) res.push_back(id);
        }
        if(m == len - 1){
            bool can = 1;
            for(int i = 0;i < m;i ++){
                if(t[i] == s[i]) continue;
                if(s.substr(i) != t.substr(i + 1)) can = false;
                break;
            }
            if(can) res.push_back(id);
        }
    }
    cout << res.size() << endl;
    for(auto x:res) cout << x << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}