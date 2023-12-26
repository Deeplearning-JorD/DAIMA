/*
 * @Author: JorD
 * @LastEditTime: 2022-11-26 20:04:32
 */
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
    string s, t;
    cin >> s >> t;
    if(t.size() > s.size()){
        cout << "No\n";
        return;
    }
    for(int i = 0;i + siz(t) - 1 < siz(s);i ++){
        if(s.substr(i, siz(t)) == t){
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
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}