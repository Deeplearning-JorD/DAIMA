/*
 * @Author: JorD
 * @LastEditTime: 2023-08-16 04:13:40
 * how to Get
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
    int n; cin >> n;
    vector<int> res;
    set<int> s;
    rep(i, 2, n) s.insert(i);
    int now = 1;
    // res.push_back(1);
    cout << 1 << ' ';
    for(int i = 1;i < n;i ++){
        if(s.count(now * 2)){
            cout << now * 2 << ' ';
            // res.push_back(now * 2);
            s.erase(now * 2);
            now *= 2;
        }else{
            auto p = s.begin();
            cout << (*p) << ' ';
            s.erase(*p);
            now = *p;
        }
    }
    // for(auto x:res) cout << x << ' ';
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