/*
 * @Author: JorD
 * @LastEditTime: 2022-11-24 10:13:11
 */
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
struct Point{
    int x, y;
};
ll gg(ll x){
    x --;
    return (x + 1) * x / 2;
}
void Solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> X(m + 1), Y(n + 1);
    map<int,int> qX, qY;
    rep(i, 1, n){
        cin >> Y[i];
        qY[Y[i]] = i;
    }
    rep(i, 1, m){
        cin >> X[i];
        qX[X[i]] = i;
    }
    vector<Point> H, L;
    vector<int> numH(m + 1), numL(n + 1);
    vector<int> idH(m + 1), idL(n + 1);
    vector<vector<int>> vH(m + 1), vL(n + 1);
    rep(i, 1, k){
        int x, y;
        cin >> x >> y;
        if(qX[y]&&qY[x]) continue;
        if(qX[y]) numH[qX[y]] ++, H.push_back({x, y});
        else numL[qY[x]] ++, L.push_back({x, y});
    }   
    ll res = 0;
    int nn = H.size(), mm = L.size();
    sort(H.begin(), H.end(), [](Point a, Point b){
        return a.x < b.x;
    });
    for(auto [x, y]:H){
        vH[qX[y]].push_back(x);
    }
    rep(i, 1, m) res += gg(numH[i]);
    for(auto [x, y]:H){
        auto yy = lower_bound(Y.begin() + 1, Y.end(), x);
        if(H.back().x < *yy) continue;
        int l = 0, r = nn - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(H[mid].x >= *yy) r = mid;
            else l = mid + 1;
        }
        while(idH[qX[y]] < numH[qX[y]] && vH[qX[y]][idH[qX[y]]] < *yy) idH[qX[y]] ++;
        res += nn - l - (numH[qX[y]] - idH[qX[y]]);
    }
    ll ans = gg(nn) - res;
    res = 0;
    sort(L.begin(), L.end(), [](Point a, Point b){
        return a.y < b.y;
    });
    for(auto [x, y]:L){
        vL[qY[x]].push_back(y);
    }
    rep(i, 1, n) res += gg(numL[i]);
    for(auto [x, y]:L){
        auto xx = lower_bound(X.begin() + 1, X.end(), y);
        int l = 0, r = mm - 1;
        if(L.back().y < *xx) continue;
        while(l < r){
            int mid = l + r >> 1;
            if(L[mid].y >= *xx) r = mid;
            else l = mid + 1;
        } 
        while(idL[qY[x]] < numL[qY[x]] && vL[qY[x]][idL[qY[x]]] < *xx) idL[qY[x]] ++;
        res += mm - l - (numL[qY[x]] - idL[qY[x]]);
    }
    ans += gg(mm) - res;
    cout << ans << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}