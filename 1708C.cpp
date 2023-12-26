/*
 * @Author: JorD
 * @LastEditTime: 2022-08-11 18:38:00
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    rep(i, 1, n) cin >> a[i];
    int cnt = 0;
    //如果cnt保持不变那么肯定不会满足cnt<a[i]
    //如果cnt要变那么cnt+1<a[i]，cnt<a[i]肯定满足
    //因为是反着来的，所以如果可以提高自己的智商他一定会提高，
    //这样更有可能让自己通过更多的关卡。
    per(i , n, 1){
        if(cnt < a[i]){
            a[i] = 0;
            if(cnt == q) continue;
            cnt ++;
        }
        a[i] = 1;
    }
    rep(i, 1, n) cout << a[i];
    cout<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}