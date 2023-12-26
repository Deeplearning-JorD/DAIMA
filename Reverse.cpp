#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
void Solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = '0' + s + '0';
    int res = 0;
    for(int i = 1;i <= n;i ++){
        if(s[i - 1] == '0' && s[i] == '1') res ++;
    }
    while(q --){
        int l, r; cin >> l >> r;
        if(s[l] == s[r]){
            cout << res << endl;
            continue;
        }
        int cnt = 0;
        cnt += s[l] == s[l - 1];
        cnt += s[r] == s[r + 1];
        if(cnt == 0) cout << res - 1 << endl;
        else if(cnt == 1) cout << res << endl;
        else cout << res + 1 << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --):
    Solve();
    return 0;
}