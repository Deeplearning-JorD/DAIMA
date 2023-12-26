/*
 * @Author: JorD
 * @LastEditTime: 2022-11-23 20:42:43
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
    int n, m;
    cin >> n;
    vector<vector<int>> a(n + 1);
    rep(i, 1, n){
        cin >> m;
        a[i].resize(m);
        for(auto &x:a[i])scanf("%d", &x);
    }
    vector<int> last(n + 2);
    per(i, n, 1) last[i] = last[i + 1] + a[i].back();
    scanf("%d", &m);
    unordered_map<string,bool> qq;
    while(m --){
        string now = "";
        rep(i, 1, n){
            int x;  scanf("%d", &x);
            now += to_string(x - 1) + "$";
        }
        qq[now] = 1;
    }   
    vector<int> res, ls;
    ll mx = 0;
    function<void(int,int,string)> dfs = [&](int i,int all, string s){
        if(i == n + 1){
            if(qq[s]) return;
            if(mx < all){
                mx = all;
                res = ls;
            }
            return;
        }
        per(j, siz(a[i]) - 1, 0){
            if(all + a[i][j] + last[i + 1] < mx) return;
            ls.push_back(j);
            dfs(i + 1, all + a[i][j], s + to_string(j) + "$");
            ls.pop_back();
        }
    };
    dfs(1, 0, "");
    for(auto x:res) printf("%d ",x + 1);
    return;
}
int main(){
    Solve();
    return 0;
}