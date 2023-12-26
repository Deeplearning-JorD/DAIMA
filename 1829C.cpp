/*
 * @Author: JorD
 * @LastEditTime: 2023-05-06 22:54:23
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
    int n;
    cin >> n;
    vector<int> a, b, c;
    rep(i, 1, n){
        int x; cin >> x;
        string s; cin >> s;
        if(s == "00") continue;
        if(s == "01"){
            a.push_back(x);
            continue;
        }
        if(s == "10"){
            b.push_back(x);
            continue;
        }
        if(s == "11"){
            c.push_back(x);
            continue;
        }
    }
    int res = 1e9;
    sort(all(a));
    sort(all(b));
    sort(all(c));
    if(a.size() && b.size()) res = min(res, a[0] + b[0]);
    if(c.size()) res = min(res, c[0]);
    if(res == 1e9) res = -1;
    cout << res << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}