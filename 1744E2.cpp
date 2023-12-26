/*
 * @Author: JorD
 * @LastEditTime: 2022-10-18 22:23:51
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
    ll a, b, c, d, resx = -1, resy = -1;
    cin >> a >>b >> c >> d;
    map<ll, int> q;
    auto jiji = [&](ll x){
        for(ll i = 2;i <= x / i;i ++){
            if(x % i == 0){
                int cnt = 0;
                while(x % i == 0){
                    cnt ++;
                    x /= i;
                }
                q[i] += cnt;
            }
        }
        if(x > 1) q[x] ++;
    };
    jiji(a),jiji(b);
    vector<pair<ll,int>> son;
    for(auto [x, y]:q){
        son.push_back({x, y});
    }
    auto check = [&](ll u){
        ll x = u, y = a * b / u;
        x = (a / x + 1) * x;
        y = (b / y + 1) * y;
        if(x > a && x <= c && y > b && y <= d){
            resx = x, resy = y;
        }
    };
    int size = siz(son);
    function<void(ll,int)> dfs = [&](ll now,int fa){
        if(fa == size){
            check(now);
            return;
        }
        if(resx != -1) return;
        dfs(now, fa + 1);
        ll sum = now;
        for(int i = 1;i <= son[fa].second;i ++){
            sum *= son[fa].first;
            dfs(sum, fa + 1);
            if(resx != -1) return;
        }
    };
    dfs(1, 0);
    cout << resx << ' ' <<resy <<endl;
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