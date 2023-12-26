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
    int l, r;
    cin >> l >> r;
    int res = l, mx = -1;
    for(int i = l;i <= min(r, l + 100);i ++){
        vector<int> v;
        int x = i;
        while(x){
            v.push_back(x%10);
            x/=10;
        }
        sort(v.begin(), v.end());
        if(*v.rbegin() - *v.begin() > mx){
            mx = *v.rbegin() - *v.begin();
            res = i;
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