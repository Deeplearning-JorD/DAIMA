/*
 * @Author: JorD
 * @Date: 2023-12-05 22:49:58
 * @LastEditTime: 2023-12-05 23:00:16
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
    string s; cin >> s;
    vector<int> v1, v2;
    int i = 0;
    for(auto x:s){
        if(x == 'b'){
            if(v1.size()) v1.pop_back();
        }else if(x == 'B'){
            if(v2.size()) v2.pop_back();
        }else if(x >= 'a' && x <= 'z'){
            v1.push_back(i);
        }else if(x >= 'A' && x <= 'Z')
            v2.push_back(i);
        i ++;
    }
    for(auto x:v1) v2.push_back(x);
    sort(v2.begin(), v2.end());
    for(auto x:v2) cout << s[x];
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