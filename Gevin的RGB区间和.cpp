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
    int a = 0, b = 0, c = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            int x; cin >> x;
            if(i + j <= n / 2 + 1) a += x;
            else if(i + j >= n / 2 + n + 1) c += x;
            else b += x;
        }
    }
    cout << a << ' ' << b << ' ' << c << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}