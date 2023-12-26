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
int num[N][2], a[N];
int cnt[2];
void Solve(){
    int n, k;
    cin >> n >> k;
    int l = k + 1 >> 1, r = l + 1;
    rep(i, 1, n) cin >> a[i];
    ll res = 0;
    auto add = [&](int x){
        cnt[x&1]++;
        num[a[x]][x&1] ++;
    };
    auto del = [&](int x){
        cnt[x&1] --;
        num[a[x]][x&1] --;
    };
    l--;
    r--;
    int dl = -1, dr = 1;
    if(l == 0){l = 1, dl = 1;}
    if(r == n - k / 2 + 1){r = n - k / 2, dr = -1;}
    rep(i, k + 1 >> 1, n){ 
        res += cnt[i&1] - num[a[i]][i&1];
        if(dl == 1) del(l);
        else add(l);
        if(dr == -1) del(r);
        else add(r);
        l += dl, r += dr;
        if(l == 0){l = 1, dl = 1;}
        if(r == n - k / 2 + 1){r = n - k / 2, dr = -1;}
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}