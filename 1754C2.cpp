/*
 * @Author: JorD
 * @LastEditTime: 2022-10-24 12:51:31
 */
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<pair<int,int>> res;
    int kd = 0;
    int cnt1 = 0;
    rep(i, 1, n){
        kd += a[i] == 0;
        cnt1 += a[i];
    }
    if((n - kd) & 1){
        cout << - 1 << endl;
        return;
    }
    vector<bool> st(n + 1);
    for(int i = 1;i < n;i ++){
        if(cnt1 == 0) break;
        if(st[i]) continue;
        if(a[i] == 0){
            if(a[i + 1] == 1){
                if(cnt1 > 0){
                    cnt1 -= 2;
                    res.push_back({i, i + 1});
                    st[i] = st[i + 1] = true;
                }
            }
            if(a[i + 1] == -1){
                if(cnt1 < 0){
                    cnt1 += 2;
                    res.push_back({i ,i + 1});
                    st[i] = st[i + 1] = true;
                }
            }
        }
        if(a[i] == 1&&a[i + 1] == 1){
            if(cnt1 > 0){
                cnt1 -= 2;
                res.push_back({i, i + 1});
                st[i] = st[i + 1] = true;
            }
        }
        if(a[i] == -1&&a[i + 1] == -1){
            if(cnt1 < 0){
                cnt1 += 2;
                res.push_back({i, i + 1});
                st[i] = st[i + 1] = true;
            }
        }
    }
    for(int i = 1;i <= n;i ++){
        if(st[i]) continue;
        res.push_back({i, i});
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(auto [x, y]:res){
        cout << x << ' ' << y << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}