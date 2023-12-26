/*
 * @Author: JorD
 * @LastEditTime: 2023-01-05 23:35:46
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
    int n;
    cin >> n;
    vector<int> a(n + 1), mp(n + 1);
    vector<bool> st(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        mp[a[i]] = i;
    }
    int res = 0;
    bool flag = false;
    rep(i, 1, n){
        if(st[i]) continue;
        vector<int> v;
        int now = i, js = 0;
        for(;;){
            if(st[now]) break;
            st[now] = true;
            v.push_back(now);
            now = a[now];
        }
        res += siz(v) - 1;
        sort(v.begin(), v.end());
        int last = -1;
        for(auto &x:v){
            if(x == last + 1) flag = true;
            last = x;
        }
    }
    // cout << res << ' ' << flag << endl;
    if(flag) cout << res - 1 << endl;
    else cout << res + 1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}