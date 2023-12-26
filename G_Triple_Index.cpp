/*
 * @Author: JorD
 * @LastEditTime: 2023-03-13 21:43:45
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

const int N=2e5+5;
int a[N],l[N],r[N],id[N],sp[N],cnt[N];
ll ans[N];
int n,i,j,q,k;
ll as;
bool cmp(int x,int y){
    int s1=l[x]/k;
    int s2=l[y]/k;
    if(s1==s2)return r[x]<r[y];
    else return s1<s2;
}
int st,ed;
ll f(int n){
    return 1ll*n--*n--*n/6;
}
void add(int i){
    as-=f(cnt[a[i]]);
    cnt[a[i]]++;
    as+=f(cnt[a[i]]);
}
void del(int i){
    as-=f(cnt[a[i]]);
    cnt[a[i]]--;
    as+=f(cnt[a[i]]);
}
void Solve(){
    scanf("%d",&n);
    scanf("%d",&q);
    for(i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    k=sqrt(n);
    for(i=1;i<=q;i++){
        scanf("%d%d",l+i,r+i);
        id[i]=i;
    }
    sort(id+1,id+q+1,cmp);
    as=0;
    st=1;
    ed=0;
    for(j=1;j<=q;j++){
        i=id[j];
        while(st<l[i])del(st++);
        while(ed<r[i])add(++ed);
        while(st>l[i])add(--st);
        while(ed>r[i])del(ed--);
        ans[i]=as;
    }
    for(i=1;i<=q;i++){
        printf("%lld\n",ans[i]);
    }
    return;
}
int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}