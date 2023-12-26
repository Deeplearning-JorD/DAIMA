#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, n){
        rep(j, 1, m){
            bool st = false;
            for(int k = 0; k < 8; k ++){
                int x = dx[k] + i, y = dy[k] + j;
                if(x <= n && y <= m&&x >= 1&&y >= 1) st=true; 
            }
            if(!st){
                cout << i << ' ' << j << endl;
                return;
            }
        }
    }
    cout << n << ' ' << m << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}