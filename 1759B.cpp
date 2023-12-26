/*
 * @Author: JorD
 * @LastEditTime: 2022-11-18 22:54:15
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
    int n, m;
    cin >> n >> m;
    ll sum = 0;
    set<int> s;
    vector<int> a(n + 1);
    int mx = 0;
    rep(i, 1, n){
        cin >> a[i];
        s.insert(a[i]);
        mx = max(mx, a[i]);
    }
    if(siz(s) != n){
        cout << "NO\n";
        return;
    }
    s.clear();
    rep(i, 1, 100)  s.insert(i);
    rep(i, 1, n){
        s.erase(a[i]);
    }
    vector<int> b;
    for(auto x:s){
        if(x > mx) break;
        b.push_back(x);
    }
    for(int i = 0;i < siz(b);i ++){
        sum += b[i];
    }
    if(sum == m){
        cout << "YES\n";
        return;
    }
    for(int i = mx + 1;;i ++){
        sum += i;
        if(sum == m){
            cout << "YES\n";
            return;
        }
        if(sum > m) break;
    }
    cout << "NO\n";
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