/*
 * @Author: JorD
 * @LastEditTime: 2023-04-30 14:22:00
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
//从结果往前推
const int N = 2e5 + 10;
int tr[N];
int lowbit(int x){
    return x & -x;
}
int n;
void add(int i, int x){
    for(;i <= n;i += lowbit(i)) tr[i] += x;
}
int query(int i){
    int res = 0;
    for(;i;i -= lowbit(i)) res += tr[i];
    return res;
}
void Solve(){
    cin >> n;
    vector<int> num(n + 1);
    vector<int> a(n + 1), b(n + 1);
    int res = 0;
    rep(i, 1, n){cin >> a[i];num[a[i]] ++; res |= num[a[i]] > 1;}
    rep(i, 1, n){cin >> b[i];num[b[i]] --; res |= num[b[i]] > 1;}
    rep(i, 1, n)if(num[i]){
        cout << "No\n";
        return;
    }
    int l = 0, r = 0;
    rep(i, 1, n){
        add(a[i], 1);
        l += i - query(a[i]);
    }
    rep(i, 1, n) add(a[i], - 1);
    rep(i, 1, n){
        add(b[i], 1);
        r += i - query(b[i]);
    }
    if((l & 1) == (r & 1) || res) cout << "Yes\n";
    else cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}