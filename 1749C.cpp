/*
 * @Author: JorD
 * @LastEditTime: 2022-10-20 23:28:51
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
    sort(a.begin() + 1, a.end());
    per(k, n, 0){
        int l = 1, r = n;
        bool st = true;
        per(i, k, 1){
            int last = r;
            while(r >= l&&a[r] > i) r --;
            if(r < l){
                st = false;
                break;
            }
            r --;
            l ++;
        }
        if(st){
            cout << k << endl;
            return;
        }
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