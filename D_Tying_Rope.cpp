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
const int N = 4e5 + 10;
int a[N];
int find(int x){
    if(x != a[x]) a[x] = find(a[x]);
    return a[x];
}
void Solve(){
    int n, m;
    cin >> n >> m;
    rep(i, 1, 2 * n) a[i] = i;
    rep(i, 1, n){
        int x = find(i + n), y = find(i);
        a[x] = y;
    }
    int res = 0;
    rep(i, 1, m){
        int A, C;
        char B, D;
        cin >> A >> B >> C >> D;
        if(B == 'R'){
            if(D == 'R'){
                int x = find(A + n), y = find(C + n);
                if(x == y) res ++;
                a[x] = y;
            }else{
                int x = find(A + n), y = find(C);
                if(x == y) res ++;
                a[x] = y;
            }
        }else{
            if(D == 'R'){
                int x = find(A), y = find(C + n);
                if(x == y) res ++;
                a[x] = y;
            }else{
                int x = find(A), y = find(C);
                if(x == y) res ++;
                a[x] = y; 
            }
        }
    }
    set<int> s;
    rep(i, 1, n){
        s.insert(find(i));
    }
    cout << res << ' ' << s.size() - res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}