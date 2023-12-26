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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
struct node{
    ll x, y;
    int i;
};
void Solve(){
    int n;
    cin >> n;
    vector<node> a(n + 1);
    rep(i, 1, n){
        ll x, y; cin >> x >> y;
        ll gcd = __gcd(x, y);
        x /= gcd;
        y /= gcd;
        a[i] = {x, x + y, i};
    }
    sort(a.begin() + 1, a.end(), [](node a, node b){
        if(a.x == b.x && b.y == a.y) return a.i < b.i;
        return a.x * b.y > a.y * b.x;
    });
    rep(i, 1, n) cout << a[i].i << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}