/*
 * @Author: JorD
 * @LastEditTime: 2023-07-27 01:43:54
 * how to Get
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
    cin >> n >> m;
    map<pair<ll,ll>, vector<ll>> son;
    map<pair<ll,ll>, vector<ll>> zson;
    while(n --){
        ll a, b; cin >> a >> b;
        while(a && b){
            if(a < b){
                son[{a, b % a}].push_back(b);
                b %= a;
            }else{
                zson[{b, a % b}].push_back(a);
                a %= b;
            }
        }
    }
    for(auto &[x, y]:son) sort(y.begin(), y.end());
    for(auto &[x, y]:zson) sort(y.begin(), y.end());
    while(m --){
        ll a, b; cin >> a >> b;
        ll res = 0;
        auto L = lower_bound(son[{a, b % a}].begin(), son[{a, b % a}].end(), b) - son[{a, b % a}].begin();
        auto R = lower_bound(zson[{b, a % b}].begin(), zson[{b, a % b}].end(), a) - zson[{b, a % b}].begin();
        if(a < b)
        res += son[{a, b % a}].size() - L;
        else if(b < a)
        res += zson[{b, a % b}].size() - R;
        else{
            res += son[{a, b % a}].size() - L;
            res += zson[{b, a % b}].size() - R;
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