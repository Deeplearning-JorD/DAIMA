/*
 * @Author: JorD
 * @LastEditTime: 2023-09-11 01:53:58
 * 别jb测div3了
 * how to Get
 */
#pragma GCC optimize(2)
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
ll lowbit(ll x){return x & -x;}
void Solve(){
    ll n; cin >> n;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    if(sum % n){
        cout << "No\n";
        return;
    }
    sum /= n;
    ll js = 0;
    map<ll,ll> st;
    ll mx = 0;
    rep(i, 1, n){
        ll c = sum - a[i];
        int b = abs(c);
        if(c < 0){
            c = - c;
            int l = lowbit(c);
            st[lowbit(c)] ++;
            int last = 0;
            while(c){
                last = c;
                c -= lowbit(c);
            }
            last <<= 1;
            st[last] --;
            if(last - l != b){
                cout << "No\n";
                return;
            }
        }else{
            int l = lowbit(c);
            st[lowbit(c)] --;
            int last = 0;
            while(c){
                last = c;
                c -= lowbit(c);
            }
            last <<= 1;
            st[last] ++;
            if(last - l != b){
                cout << "No\n";
                return;
            }
        }
    }
    for(auto [x, y] : st)if(x && y){
        cout << "No\n";
        return;
    }
    cout << "Yes\n"; 
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}