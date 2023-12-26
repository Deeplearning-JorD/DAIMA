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
int a[N], num[N];
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n){
        cin >> a[i];
        num[a[i]] = i;
    }
    cout << 2 * n - 2 << endl;
    rep(i, 1, n - 1){
        cout << i << ' ' << num[i] << endl;
        int l = i + 1, r = num[i] - 1;
        if(l > r) cout << 1 << ' ' << 1 << endl;
        else cout << l << ' ' << r << endl;
        int j = num[i];
        num[a[j]] = i;
        num[a[i]] = j; 
        swap(a[i], a[j]);
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