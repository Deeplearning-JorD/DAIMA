/*
 * @Author: JorD
 * @LastEditTime: 2022-09-30 22:50:56
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
    vector<ll> a, b;
    vector<int> id(n + 1);
    rep(i, 1, n) cin >> id[i];
    rep(i, 1, n){
        ll x;
        cin >> x;
        if(id[i]) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int L = a.size() - 1, R = b.size() - 1;
    int l = 0, r = 0;
    ll sum = 0;
    if(a.empty()||b.empty()){
        if(b.empty()){
            sum = accumulate(a.begin(), a.end(), 0ll);
        }else sum = accumulate(b.begin(), b.end(), 0ll);
        cout << sum << endl;
        return;
    }
    int last = 1;
    sum = a[l++];
    rep(i, 2, n){
        if(last == 1){
            if(R >= r){
                sum += 2*b[R--];
                last = 0;
            }else{
                sum += a[L--];
                last = 1;
            }
        }else{
            if(L >= l){
                sum += 2*a[L--];
                last = 1;
            }else{
                sum += b[R--];
                last = 0;
            }
        }
    }
    ll res = sum;
    L = a.size() - 1, R = b.size() - 1;
    l = 0, r = 0;
    sum = b[r++];
    last = 0;
    rep(i, 2, n){
        if(last == 1){
            if(R >= r){
                sum += 2*b[R--];
                last = 0;
            }else{
                sum += a[L--];
                last = 1;
            }
        }else{
            if(L >= l){
                sum += 2*a[L--];
                last = 1;
            }else{
                sum += b[R--];
                last = 0;
            }
        }
    }
    cout << max(res, sum) << endl;
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