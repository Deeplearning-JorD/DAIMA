/*
 * @Author: JorD
 * @LastEditTime: 2023-08-07 23:43:00
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
void Solve(){
    int n; cin >> n;
    vector<ll> a(n + 1);
    map<int,ll> cnt;
    set<int> s;
    rep(i, 1, n){
        int x; cin >> x;
        a[i] = x;
        cnt[x] ++;
        s.insert(x);
    }
    vector<ll> b;
    b.push_back(1);
    for(auto x:s) b.push_back(x);
    int m = b.size();
    m --;
    ll sum = 0, last = 0, j = 1e9;
    map<ll,ll> st;
    vector<ll> pp(m + 1), bb(m + 1);
    for(int i = m;i >= 1;i --){
        sum += (j - b[i]) * last + cnt[b[i]];
        pp[i] = sum;
        last += cnt[b[i]];
        j = b[i];
    }
    last = 0;
    sum = 0;
    j = 1;
    for(int i = 1;i <= m;i ++){
        sum += (b[i] - j) * last + cnt[b[i]];
        last += cnt[b[i]];
        j = b[i];
        st[b[i]] = sum + pp[i] - cnt[b[i]];  
    }
    rep(i, 1, n) cout << st[a[i]] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}