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
const int N = 2e6 + 10;
int col[N], row[N], dx[N], dy[N];
void Solve(){
    int n, m;
    cin >> n >> m;
    while(m -- ){
        int x, y;
        cin >> x >> y;
        if(col[x] || row[y] || dx[x + y] || dy[n + x - y]){
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        col[x] = 1;
        row[y] = 1;
        dx[x + y] = 1;
        dy[n + x - y] = 1;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}