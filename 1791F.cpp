/*
 * @Author: JorD
 * @LastEditTime: 2023-02-04 01:02:55
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
const int N = 5e5 + 10;
ll get(ll x){
    int res = 0;
    while(x){
        res += x % 10;
        x /= 10;
    }
    return res;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    set<int> s;
    vector<int> ji(n + 1);
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        s.insert(i);
    }
    s.insert(n + 1);
    while(m --){
        int op;
        cin >> op;
        if(op == 1){
            int l, r;
            cin >> l >> r;
            auto be = s.lower_bound(l);
            vector<int> ls;
            for(;;be ++){
                if(*be > r) break;
                int i = *be;
                if(ji[i]) continue;
                int last = a[i];
                a[i] = get(last);
                if(a[i] == last){
                    ji[i] = 1;
                    ls.push_back(i);
                }
            }
            for(auto x:ls){
                s.erase(s.find(x));
            }
        }else{
            int i; cin >> i;
            cout << a[i] << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}