/*
 * @Author: JorD
 * @LastEditTime: 2023-04-20 11:55:08
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
const int N = 2e5 + 10;
vector<int> son[N];
int n, m;
int in[N];
int dp[N];
void Solve(){
    cin >> n >> m;
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        in[y] ++;
        son[x].push_back(y);
    }
    queue<int> q;
    rep(i, 1, n)if(!in[i]){
        dp[i] = 1;
        q.push(i);
    }
    while(q.size()){
        auto t = q.front(); q.pop();
        for(auto x:son[t]){
            dp[x] = max(dp[x], dp[t] + 1);
            if(-- in[x] == 0){
                q.push(x);
            }
        }
    }
    rep(i, 1, n){
        cout << dp[i] << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}