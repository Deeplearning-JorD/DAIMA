/*
 * @Author: JorD
 * @LastEditTime: 2022-10-09 19:33:25
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
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<vector<int>> jiji(m + 1);
    rep(i, 1, n){
        if(a[i] >= n) continue;
        int l;
        if(a[i] >= 0) l = 1;
        else l = (- a[i]) / i;
        if(a[i] + i * l < 0) l ++;
        for(int j = l;j <= m;j ++){
            if(a[i] + i * j > n) break;
            jiji[j].push_back(a[i] + i * j);  
        }
    }
    rep(i, 1, m){
        set<int> beibei;
        for(auto x:jiji[i]){
            beibei.insert(x);
        }
        rep(j, 0, n + 1){
            if(beibei.count(j)) continue;
            cout << j << endl;
            break;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}