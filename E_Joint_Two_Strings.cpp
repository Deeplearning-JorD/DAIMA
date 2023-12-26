/*
 * @Author: JorD
 * @LastEditTime: 2023-10-14 20:52:11
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
    int n1, n; cin >> n1;
    string t; cin >> t;
    n = t.size();
    vector<int> pre(n1 + 1), suf(n1 + 1);
    vector<int> a;
    rep(j, 1, n1){
        string s; cin >> s;
        int m = s.size();
        int idx = 0;
        for(int i = 0;i < m;i ++)if(idx < n){
            if(s[i] == t[idx]) idx ++;
        }
        pre[j] = idx;
        int k = n - 1;
        idx = 0;
        for(int i = m - 1;i >= 0;i --)if(k >= 0){
            if(s[i] == t[k]){
                idx ++;
                k --;
            }
        }
        suf[j] = idx;
        a.push_back(idx);
    }
    sort(a.begin(), a.end());
    ll res = 0;
    rep(i, 1, n1){
        int now = n - pre[i];
        int p = lower_bound(a.begin(), a.end(), now) - a.begin();
        res += n1 - p;
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}