/*
 * @Author: JorD
 * @LastEditTime: 2022-10-03 16:38:50
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
    vector<vector<int>> son(n + 2);
    rep(i, 1, n){
        int x;
        cin >> x;
        son[x].push_back(i);
    }
    int mid = 0;
    if(son[n + 1].size()) mid = n + 1;
    int k = 0;
    vector<int> res;
    while(1){
        int now = -1;
        for(auto x:son[mid]){
            if(son[x].size()) now = x;
            else res.push_back(x);
            if(x <= mid) k = max(k, x);
        }
        if(now == -1) break;
        res.push_back(now); mid = now;
    }
    cout << k << endl;
    for(auto x:res) cout << x << ' ';
    cout << endl;
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