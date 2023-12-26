/*
 * @Author: JorD
 * @LastEditTime: 2023-04-05 18:55:34
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
const int N = 5e5 + 10, mod = 1e9 + 7, P = 13331;
using ull = unsigned long long;
ull h[N], hh[N], p[N];
ll h1[N], hh1[N], pp[N];
ull find(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}
ull find1(int l, int r){
    return hh[l] - hh[r + 1] * p[r - l + 1];
}
ll ffind(int l, int r){
    return (h1[r] - h1[l - 1] * pp[r - l + 1]%mod+mod)%mod;
}
ll ffind1(int l, int r){
    return (hh1[l]-hh1[r+1]*pp[r - l + 1]%mod+mod)%mod;
}
void Solve(){
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    int l = 1, r = n;
    while(l < r){
        if(s[l] != s[r]) break;
        l ++, r --;
    }
    if(l >= r){
        cout << "Yes\n";
        return;
    }
    h[0] = hh[0] = 0;
    rep(i, 1, n){
        h[i] = h[i - 1] * P + s[i] - 'a';
        h1[i] = h1[i - 1] * P + s[i] - 'a';
        h1[i] %= mod; 
    }
    hh[n + 1] = hh1[n + 1] = 0;
    per(i, n, 1){
        hh[i] = hh[i + 1] * P + s[i] - 'a';
        hh1[i] = hh1[i + 1] * P + s[i] - 'a';
        hh1[i] %= mod; 
    }
    for(int i = r;i > l;i --){
        ull pre = find1(l, i - 1) * p[r - i + 1] + find(i, r);
        ull last = find1(i, r) * p[i - l] + find(l, i - 1);
        ll pre1 = ffind1(l, i - 1) * pp[r - i + 1] % mod + ffind(i, r);
        ll last1 = ffind1(i, r) * pp[i - l] % mod + ffind(l, i - 1);
        pre1 %= mod;
        last1 %= mod;
        if(pre == last && pre1 == last1){
            cout << "Yes\n";
            return;
        }
    }
    for(int i = l + 1;i < r;i ++){
        ull pre = find(l, i - 1) * p[r - i + 1] + find1(i, r);
        ull last = find(i, r) * p[i - l] + find1(l, i - 1);
        ll pre1 = ffind(l, i - 1) * pp[r - i + 1] % mod + ffind1(i, r);
        ll last1 = ffind(i, r) * pp[i - l] % mod + ffind1(l, i - 1);
        pre1 %= mod;
        last1 %= mod;
        if(pre == last && pre1 == last1){
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
    p[0] = 1;
    pp[0] = 1;
    rep(i, 1, N - 5){
        p[i]=p[i-1]*P;
        pp[i]=pp[i-1]*P;
        pp[i]%=mod;
    }
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}