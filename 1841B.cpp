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
    int a, b, st = 0;
    rep(i, 1, n){
        int x; cin >> x;
        if(i == 1){
            cout << 1;
            a = x;
            b = x;
            continue;
        }
        if(st){
            if(x >= b && x <= a){
                cout << 1;
                b = x;
            }else{
                cout << 0;
            }
        }else{
            if(x >= b){
                cout << 1;
                b = x;
            }else{
                if(x <= a){
                    st = 1;
                    cout << 1;
                    b = x;
                }else cout << 0;
            }
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