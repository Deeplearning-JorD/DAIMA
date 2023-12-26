/*
 * @Author: JorD
 * @LastEditTime: 2022-08-28 06:53:40
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
    vector<int> b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    int idx = 1;
    rep(i, 1, n){
        while(b[idx] < a[i]) idx ++;
        cout << b[idx] - a[i] << ' ';
    }
    cout << endl;
    vector<int> res(n + 1);
    int l = n, r = n, need = 0;
    per(i, n, 1){
        l = r;
        int now = i;
        int minn = i;
        while(b[l] >= a[now]){
            while(b[l] >= a[now]) l --;
            l ++;
            if(l >= minn) break;
            minn = l;
            now = l;
        }
        need = r - l + 1;
        int last;
        for(int j = 1, k = i;j <= need;j ++, k --){
            res[k] = b[r] - a[k];
            last = k;
        }
        r = l - 1;
        i = last;
    }
    rep(i, 1, n) cout << res[i] << ' ';
    cout << endl;
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