/*
 * @Author: JorD
 * @LastEditTime: 2023-07-23 20:09:34
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
const int N = 1e6 + 10, mod = 1e9 + 7, P = 131;
ll h[N], p[N], hh[N];
map<char,char> st;
ll find(int l, int r){
    return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
}
ll find1(int l, int r){
    return (hh[l] - hh[r + 1] * p[r - l + 1] % mod + mod) % mod;
}
void Solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    for(int i = 1;i <= n;i ++){
        h[i] = h[i - 1] * P + (s[i] - 'a');
        h[i] %= mod;
    }
    hh[n + 1] = 0;
    for(int i = n;i >= 1;i --){
        hh[i] = hh[i + 1] * P + (st[s[i]] - 'a');
        hh[i] %= mod;
    }
    int j = 1;
    for(int i = 1;i <= n;i ++){
        if(find(j, i) == find1(j, i)){
            j = i + 1;
        }
    }
    if(j != n + 1) cout << "No\n";
    else cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    p[0] = 1;
    for(int i = 1;i <= N - 5;i ++){
        p[i] = p[i - 1] * P % mod;
    }
    st['b'] = 'q';
    st['q'] = 'b';
    st['d'] = 'p';
    st['p'] = 'd';
    st['n'] = 'u';
    st['u'] = 'n';
    st['s'] = 's';
    st['o'] = 'o';
    st['x'] = 'x';
    st['z'] = 'z';
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}