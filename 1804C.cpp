/*
 * @Author: JorD
 * @LastEditTime: 2023-03-13 12:20:42
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
    ll n, x, p;
    cin >> n >> x >> p;
    ll pre = 0;
    set<int> s;
    set<int> ss;
    for(int i = 1;i <= min(n, p);i ++){
        ll now = i % n;
        pre += now;
        pre %= n;
        s.insert(pre);
        if(i <= p % n) ss.insert(pre);
        if((pre + x) % n == 0){
            cout << "Yes\n";
            return;
        }
    }
    map<ll,ll> st;
    for(int i = 1;i <= (p / n) - 1;i ++){
        ll now = pre * 1ll * i + x;
        now %= n;
        if(st[now]) break;
        st[now] = 1;
        now = n - now;
        if(s.count(now)){
            cout << "Yes\n";
            return;
        }
    }
    if(p % n){
        ll now = pre * 1ll * (p / n) + x;
        now %= n;
        now = n - now;
        if(ss.count(now)){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}