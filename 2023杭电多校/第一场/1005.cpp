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
ull h[N], p[N];
ll h1[N], pp[N];
ull find(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}
ll ffind(int l, int r){
    return (h1[r] - h1[l - 1] * pp[r - l + 1]%mod+mod)%mod;
}
void Solve(){
    int n, m, len;
    cin >> n >> len;
    vector<set<pair<ull,ll>>> st(n + 1);
    vector<pair<ull,ll>> a(n + 1);
    rep(T, 1, n){
        string s; cin >> s;
        s = ' ' + s + s;
        for(int i = 1;i < s.size();i ++){
            h[i] = h[i - 1] * P + s[i] - 'a';
            h1[i] = h1[i - 1] * P + s[i] - 'a';
            h1[i] %= mod;
        }
        for(int i = 1, j = len;i <= len;i ++, j ++){
            st[T].insert({find(i,j),ffind(i,j)});
        }
        a[T] = {find(1,len),ffind(1,len)};
    }
    cin >> m;
    while(m --){
        int i, j;
        cin >> i >> j;
        if(st[i].count(a[j])) cout << "Yes\n";
        else cout << "No\n";
    }
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