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
const int N = 500000 + 10;
const int M = 710;
ll st[M][M], a[N];
void Solve(){
    int q; cin >> q;
    while(q --){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            for(int i = 1;i <= 707;i ++) st[i][x % i] += y;
            a[x] += y;
        }else{
            if(x <= 707){
                cout << st[x][y] << endl;
            }else{
                ll res = 0;
                for(int i = y;i <= N - 10;i += x) res += a[i];
                cout << res << endl;
            }
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}