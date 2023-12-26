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
int a[510], b[510];
void Solve(){
    int n, q;
    cin >> n >> q;
    cout << n << ' ' << n - 1 << endl;
    cout << n - 1 << ' ' << 1 << endl;
    for(int i = 2;i < n - 1;i ++){
        cout << i - 1 << ' ' << i << endl;
    }
    int l = 0, r = 0, last = -1;
    a[0] = n - 1, b[0] = n - 1;
    for(int i = 1;i < n - 1;i ++) a[++ l] = i;
    while(q --){
        int x; cin >> x;
        if(x == last || x - 1 == l){
            cout << "-1 -1 -1\n";
            last = x;
            continue;
        }
        if(x - 1 > l){
            int c = x - 1 - l;
            cout << b[r - c + 1] << ' ' << b[r - c] << ' ' << a[l] << endl;
            for(int i = r - c + 1;i <= r;i ++){
                a[++ l] = b[i];
            }
            r -= c;
        }else{
            cout << a[x] << ' ' << a[x - 1] << ' ' << b[r] << endl;
            for(int i = x;i <= l;i ++){
                b[++ r] = a[i];
            }
            l -= l - x + 1;
        }
        last = x;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}