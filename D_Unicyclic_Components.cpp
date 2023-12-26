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
const int N = 2e5 + 10;
int f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
int cnt[N], idx[N];
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) f[i] = i;
    while(m --){
        int x, y;
        cin >> x >> y;
        x = find(x), y = find(y);
        if(x != y){
            cnt[y] += 1 + cnt[x];
            f[x] = y;
            cnt[x] = 0;
        }else{
            cnt[y] ++;
        }
    }
    rep(i, 1, n){
        idx[find(i)] ++;
    }
    rep(i, 1, n){
        if(idx[find(i)] != cnt[find(i)]){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}