/*
 * @Author: JorD
 * @LastEditTime: 2023-07-27 23:07:05
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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> f(n + 2), ff(n + 2);
    rep(i, 0, n + 1) f[i] = ff[i] = i;
    function<int(int)> findr = [&](int x){
        if(f[x] != x) f[x] = findr(f[x]);
        return f[x];
    };
    function<int(int)> findl = [&](int x){
        if(ff[x] != x) ff[x] = findl(ff[x]);
        return ff[x];
    };
    s = ' ' + s + ' ';
    set<pair<int,int>> q;
    rep(i, 1, n){
        if(s[i] == '0' && s[i + 1] == '0'){
            f[findr(i)] = findr(i + 1);
        }
    }
    per(i, n, 1){
        if(s[i] == '1' && s[i - 1] == '1'){
            ff[findl(i)] = findl(i - 1);
        }
    }
    int w = 0;
    while(m --){
        int l, r;
        cin >> l >> r;
        int L = l, R = r;
        l = findr(l);
        r = findl(r);
        if(s[l] == '0') l ++;
        if(s[r] == '1') r --;
        if(l >= r){
            w = 1;
            continue;
        }
        q.insert({l, r});
    }
    cout << w + siz(q) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}