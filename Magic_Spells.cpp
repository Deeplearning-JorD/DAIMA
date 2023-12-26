/*
 * @Author: JorD
 * @LastEditTime: 2022-08-16 11:02:33
 */
#include<bits/stdc++.h>
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
typedef unsigned long long ULL;
const int N = 6e5+10,P=131,PP=13331;
const ULL MOD = 1e9+7;
ULL h[N],pp[N];
ULL hh[N],ppp[N];
inline ULL find(int l, int r){
    return (h[r]-h[l-1]*pp[r-l+1]%MOD+MOD)%MOD;
}
ll res;
map<ULL,int> q;
char a[N];
char b[N];
int t;
int n;
int p[N];
set<ULL> s;
set<pair<int,int>> qq;
inline void manacher(){
    int mr=0,mid;
    memset(p,0,sizeof p);
    for(int i=1;i<n;i++){//首尾是$^
        if(i<mr)p[i]=min(p[mid*2-i],mr-i);//p[mid*2-i]就是j
        else p[i]=1;
        int l = i - p[i] + 1, r = i + p[i] - 1;
        if(b[l]=='#'&&p[i]>=2){
            qq.insert({l,r});
        }
        while(b[i-p[i]]==b[i+p[i]]){
            p[i]++;
            if(p[i]<2) continue;
            int l = i - p[i] + 1, r = i + p[i] - 1;
            if(b[l]!='#') continue;
            qq.insert({l,r});
        }
        if(i+p[i]>mr){
            mr=i+p[i];
            mid=i;
        }
    }
}
inline void init(){
    int k=0;
    b[k++]='$';b[k++]='#';
    for(int i=0;i<n;i++)b[k++]=a[i],b[k++]='#';
    b[k++]='^';
    n=k;
    s.clear();qq.clear();
}
signed main(){
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%s",a);
        n=strlen(a);
        init();
        manacher();
        pp[0]=1;ppp[0]=1;
        for(int i=1;i<n-1;i++){
            h[i]=(h[i-1]*P+b[i]-'#')%MOD;
            pp[i]=(pp[i-1]*P)%MOD;
        }
        for(auto x:qq){
            int l = x.first, r = x.second;
            auto get = find(l ,r);
            s.insert(get);
            // rep(i,l,r) cout<<b[i];
            // cout<<endl;
            // cout<<get<<endl;
        }
        for(auto x:s){
            q[x]++;
            if(tt == t&&q[x] == t) res++; 
        }
        rep(i,0,n+10) a[i]='\0';
        rep(i,0,n+10) b[i]='\0';
    }
    cout<<res;
    return 0;
}
