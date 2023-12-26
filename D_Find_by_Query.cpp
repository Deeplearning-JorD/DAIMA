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
    int n;
    cin >> n;
    int l = 1, r = n;
    int m = 20;
    while(m --){
        if(l + 1 == r){
            cout << "! " << l << endl;
            return;
        }
        int L = l, R = r;
        int mid = L +  R >> 1;
        cout << "? " << mid << endl;
        int x; cin >> x;
        if(x == 1){
            r = mid;
        }else l = mid;
    }
    cout << "! " << l << endl;
    return;
}
int main(){
    Solve();
    return 0;
}