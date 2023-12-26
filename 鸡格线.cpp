/*
 * @Author: JorD
 * @LastEditTime: 2023-01-16 15:56:52
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
const int N = 1e5 + 10;
int get(int x){
    return round(10 * sqrt(x));
}
int a[N];
ll sum;
int ji[N];
void Solve(){
    int n, m;
    cin >> n >> m;
    set<int> s;
    rep(i, 1, n){
        cin >> a[i];
        sum += a[i];
        s.insert(i);
    }
    s.insert(n + 1);
    while(m --){
        int op;
        cin >> op;
        if(op == 1){
            int l, r, k;
            cin >> l >> r >> k;
            auto be = s.lower_bound(l);
            vector<int> ls;
            for(;;be ++){
                if(*be > r) break;
                rep(j, 1, k){
                    int i = *be;
                    if(ji[i]) break;
                    int last = a[i];
                    sum -= last;
                    a[i] = get(last);
                    if(a[i] == last){
                        ji[i] = 1;
                        ls.push_back(i);
                    }
                    sum += a[i];
                }
            }
            for(auto x:ls){
                s.erase(s.find(x));
            }
        }else{
            cout << sum << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}