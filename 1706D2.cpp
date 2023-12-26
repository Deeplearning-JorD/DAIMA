/*
 * @Author: JorD
 * @LastEditTime: 2022-08-11 15:03:38
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (int(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N=2e5+10;
int M[N],a[N];
void Solve(){
    int n,m;
    cin >> n >> m;
    memset(M,0,sizeof M);
    rep(i,1,n){
        cin >> a[i];
        int last=2e9;
        int mm=sqrt(a[i]);
        for(int j=1;j<=min(m,mm);j  ++ ){
            int now = a[i]/j;
            // idx 表示当前的v为最小值时最贪心的最大值。
            // last是上一个块的最大值，是一定>now的
            M[now+1]=max(M[now+1],last);
            last = now;
        }
        //最小的值认为是给v为0了。
        M[0] = max(M[0],last);
    }   
    int res=2e9,maxn=0;
    for(int i=0;i<=a[1];i++){
        maxn = max(maxn, M[i]);
        res=min(res,maxn-i);
    }
    cout << res << endl;
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