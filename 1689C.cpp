/*
 * @Author: JorD
 * @LastEditTime: 2022-08-16 08:55:44
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
    vector<vector<int>> son(n+1);
    rep(i, 2, n){
        int a, b;
        cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    } 
    vector<int> f(n+1), num(n+1);
    // f[i]表示i被感染了之后剩下最多有多少个节点没被感染
    function<void(int,int)> dfs = [&](int now,int fa){
        int sum = 0;
        for(auto x:son[now]){
            if(x == fa) continue;
            dfs(x, now);
            num[now] += num[x];
            sum += f[x];
        }
        for(auto x:son[now]){
            if(x == fa) continue;
            f[now] = max(f[now], sum - f[x] + num[x] - 1);
        }
        num[now] ++;
    };
    dfs(1, 0);
    cout << f[1] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}