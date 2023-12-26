/*
 * @Author: JorD
 * @LastEditTime: 2023-07-26 18:46:42
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
ll exgcd(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> son(n + 1);
    rep(i, 2, n){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    vector<int> pre(n + 1);
    while(m --){
        int sa, ta, sb, tb;
        cin >> sa >> ta >> sb >> tb;
        ll res = -1, js = 1e18;
        queue<int> q;
        vector<int> d(n + 1, 1e9), d1(n + 1, 1e9);
        vector<int> v1, v2;
        q.push(sa);
        pre[sa] = -1;
        d[sa] = 0;
        while(q.size()){
            auto t = q.front(); q.pop();
            if(t == ta){while(q.size()) q.pop();break;}
            for(auto x:son[t])if(d[x] > d[t] + 1){
                pre[x] = t;
                d[x] = d[t] + 1;
                q.push(x);
            }
        }
        int now = ta;
        while(now != -1){
            v1.push_back(now);
            now = pre[now];       
        }
        auto ls = v1;
        reverse(v1.begin(), v1.end());
        for(int i = 1;i < siz(ls) - 1;i ++) v1.push_back(ls[i]);
        q.push(sb);
        pre[sb] = -1;
        d1[sb] = 0;
        while(q.size()){
            auto t = q.front(); q.pop();
            if(t == tb){while(q.size()) q.pop();break;}
            for(auto x:son[t])if(d1[x] > d1[t] + 1){
                pre[x] = t;
                d1[x] = d1[t] + 1;
                q.push(x);
            }
        }
        now = tb;
        while(now != -1){
            v2.push_back(now);
            now = pre[now];
        }
        ls = v2;
        reverse(v2.begin(), v2.end());
        for(int i = 1;i < siz(ls) - 1;i ++) v2.push_back(ls[i]);
        int n1 = v1.size(), n2 = v2.size();
        for(int i = 0;i < n1;i ++){
            for(int j = 0;j < n2;j ++){
                if(v1[i] == v2[j]){
                    // x = v1[i] (mod n1)
                    // x = v2[j] (mod n2)
                    ll a = i, b = j, x, y;
                    // x = a + n1 * k1;
                    // x = b + n2 * k2;
                    // a - b = n2 * k2 - n1 * k1;
                    // n2 * k2 + n1 * (- k1) = a - b;  
                    ll d = exgcd(n2, n1, x, y);
                    if((a - b) % d) continue;
                    x = (x % (n1 / d) + (n1 / d)) % (n1 / d);
                    ll mod = n1 / d * n2;
                    x *= (a - b) / d;
                    x = ((b + n2 * x % mod) % mod + mod) % mod;
                    if(x < js){
                        res = v1[i];
                        js = x;
                    }
                }
            }
        }
        cout << res << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}