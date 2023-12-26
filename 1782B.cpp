/*
 * @Author: JorD
 * @LastEditTime: 2023-01-15 20:25:47
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
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int res = 1;
    rep(i, 1, n) cin >> a[i];
    sort(all1(a));
    int now = 0;
    for(int i = 1;i <= n;i ++){
        if(now >= a[i]) now ++;
        else{
            res ++;
            int j = i;
            while(j <= n && now < a[j]){
                now ++;
                j ++;
            }
            i = j - 1;
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}