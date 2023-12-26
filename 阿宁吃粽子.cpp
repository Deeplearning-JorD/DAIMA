/*
 * @Author: JorD
 * @LastEditTime: 2022-08-26 19:26:32
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
    vector<int> a(n+1);
    vector<vector<int>> q(10);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i, 1, n){
        q[i%10].push_back(i);
    }
    int idx = n;
    vector<int> res(n);
    per(i, 9, 0){
        for(int j = q[i].size() - 1; j >= 0; j --)
            res[q[i][j] - 1] = a[idx --];
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