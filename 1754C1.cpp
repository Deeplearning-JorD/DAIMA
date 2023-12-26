/*
 * @Author: JorD
 * @LastEditTime: 2022-10-23 16:29:40
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
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    if(n & 1){
        cout << -1 << endl;
        return;
    }
    vector<pair<int,int>> res;
    for(int i = 1;i <= n;i += 2){  
        if(a[i] == a[i + 1]){
            res.push_back({i, i + 1});
        }else{
            res.push_back({i,i});
            res.push_back({i+1,i+1});
        }
    }
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