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
    double w, h;
    cin >> w >> h;
    double lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    double nw, nh;
    cin >> nw >> nh;
    double ow = rx - lx, oh = ry - ly;
    if(nw + ow > w&&nh + oh > h){
        cout << "-1\n";
        return;
    }
    if(nw + ow > w){
        cout << min(max(nh - (h - ry), 0.0),max(nh - ly, 0.0)) << endl;
        return;
    }
    if(nh + oh > h){
        cout << min(max(nw - (w - rx), 0.0),max(nw - lx, 0.0)) << endl;
        return;
    }
    cout << min(min(max(nh - (h - ry), 0.0),max(nh - ly, 0.0)),min(max(nw - (w - rx), 0.0),max(nw - lx, 0.0))) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << SPO(9);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}