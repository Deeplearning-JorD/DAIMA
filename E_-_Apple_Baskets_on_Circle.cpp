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
void Solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1), b(n + 1);
    ll w = 0;
    rep(i, 1, n){
        cin >> a[i];
        b[i] = a[i];
        if(a[i]) w ++;
    }
    sort(a.begin(), a.end());
    vector<vector<ll>> id(n + 1);
    ll idx = 0;
    ll last = a[1];
    rep(i, 1, n){
        if(last != a[i]){
            idx ++;
        }
        last = a[i];
        id[idx].push_back(a[i]);
    }
    ll sum = 0;
    ll l;
    if(id[0][0] == 0) l = 1;
    else l = 0;
    last = 0;
    rep(i, l, idx){
        ll now = id[i][0] - last;
        if(sum + now * w >= k){
            ll l = 1, r = now;
            while(l < r){
                ll mid = l + r >> 1;
                if(sum + mid * w >= k) r = mid;
                else  l = mid + 1;
            }
            r --;
            sum += r * w;
            k -= sum;
            r += last;
            rep(i, 1, n){
                b[i] = max(0ll, b[i] - r);
                if(k){
                    if(b[i]){
                        b[i] --;
                        k --;
                    }
                }
            }
            break;
        }
        sum += now * w;
        w -= id[i].size();
        last = id[i][0];
    }
    rep(i, 1, n) cout << b[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}