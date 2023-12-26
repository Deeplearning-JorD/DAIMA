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
    int n, k; cin >> n >> k;
    int res = 0, w = 0;
    vector<int> a(n + 1), L(n + 1), R(n + 1);
    rep(i, 1, n){
        int now = (i + k - 1) / k;
        L[i] = now;
        R[n - i + 1] = now;
    }
    int l = 1, r = n, pre = 0, last = 0;
    rep(i, 1, n){
        pre += a[l];
        last += a[r];
        if(l < r){
            if(pre < L[l]){
                pre ++;
                a[l] = 1;
            }
            if(last < R[r]){
                last ++;
                a[r] = 1;
            }
        }else{
            if(pre < L[l]){
                if(!a[l]) a[l] = 1;
                else a[r] = 1;
                pre ++;
                last ++;
            }
        }
        r --, l ++;
    }
    cout << count(a.begin(), a.end(), 1) << endl;    
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}