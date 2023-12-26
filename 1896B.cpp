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
    int n; cin >> n;
    string s; cin >> s;
    int z = -1, y = -1;
    for(int i = 0;i < n;i ++)if(s[i] == 'A'){
        z = i;
        break;
    }
    for(int i = n - 1;i >= 0;i --)if(s[i] == 'B'){
        y = i;
        break;
    }
    int res = 0;
    if(z != -1 && y != -1) res = max(res, y - z);
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}