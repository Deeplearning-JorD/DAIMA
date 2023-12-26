/*
 * @Author: JorD
 * @LastEditTime: 2022-08-10 16:30:33
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
const int N = 3e5+10;
int a[N];
struct node{
    ll mx,sum,pr,la;
    void update(const node &l,const node &r){
        //最大字段和
        mx = max({l.mx,r.mx,l.la+r.pr});
        sum = l.sum + r.sum;
        pr = max(l.sum + r.pr, l.pr);
        la = max(l.la + r.sum, r.la);
    }
};
//考虑DP ， 用状态st来表示当前状态下的最大值
//越高位的1表示swap的k越大
vector<node> build(int l, int r){
    if(l == r){
        return {node{max(a[l],0),a[l],a[l],a[l]}};
    }
    //n表示当前要交换的状态,即表示当前能交换的最高位的1
    int mid = l+r>>1,n = r - mid;
    vector<node> d1=build(l,mid),d2=build(mid+1,r);
    vector<node> res(r-l+1);
    for(int i=0;i<d1.size();i++){
        auto L = d1[i], R = d2[i];
        //不交换，当前最高位为0
        res[i].update(L, R);
        //交换，当前最高位为1
        res[i + n].update(R, L);
    }
    return res;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, 1<<n) cin >> a[i];
    vector<node> res = build(1, 1<<n);
    int t; cin >> t;
    int idx = 0;
    while(t --){
        int x;
        cin >> x;
        idx ^= 1 << x;
        cout << res[idx].mx << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}