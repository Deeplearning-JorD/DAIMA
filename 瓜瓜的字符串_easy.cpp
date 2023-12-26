/*
 * @Author: JorD
 * @LastEditTime: 2022-10-08 15:15:40
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
    vector<pair<int,int>> a(n + 1, {1e9,0 });
    vector<int> b(n + 1);
    rep(i, 1, n){
        int x; cin >> x;
        a[i] = {x, i};
        b[i] = x;
    }
    sort(a.begin(), a.end(), [&](pair<int,int> x, pair<int,int> y){
        return x.first > y.first;
    });
    int maxn = 0;
    vector<int> res;
    for(int i = 1;i <= n;i ++){
        if(a[i].second <= maxn) continue;
        for(int j = a[i].second;j > maxn; j --){
            res.push_back(b[j]);
        }
        maxn = max(maxn, a[i].second);
    }
    for(auto x:res) cout << x << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    Solve();
    return 0;
}