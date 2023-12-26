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
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    rep(i, 1, n) cin >> a[i];
    string s; cin >> s;
    s = ' ' + s;
    for(int i = 1;i <= n;i ++){
        b[i] = b[i - 1];
        c[i] = c[i - 1];
        if(s[i] == '0') b[i] ^= a[i];
        else c[i] ^= a[i];
    }
    int L = b[n], R = c[n];
    int m; cin >> m;
    while(m --){
        int op, l, r; cin >> op;
        if(op == 1){
            cin >> l >> r;
            L ^= c[r] ^ c[l - 1] ^ b[r] ^ b[l - 1];
            R ^= c[r] ^ c[l - 1] ^ b[r] ^ b[l - 1];
        }else{
            cin >> op; 
            if(op == 0) cout << L << ' ';
            else cout << R << ' ';
        }
    }
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