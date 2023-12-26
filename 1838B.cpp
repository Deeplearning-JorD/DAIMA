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
    vector<int> a(n + 1);
    int id1, id2, mid;
    rep(i, 1, n){
        cin >> a[i];
        if(a[i] == 1) id1 = i;
        else if(a[i] == 2) id2 = i;
        else if(a[i] == n) mid = i;
    }
    if(id1 > id2) swap(id1, id2);
    if(abs(id1 - id2) != 1){
        cout << id1 + 1 << ' ' << mid << endl;
        return;
    }
    if(mid <= id1){
        cout << mid << ' ' << id1 << endl;
    }else cout << id2 << ' ' << mid << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}