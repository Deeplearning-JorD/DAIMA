#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef pair<int,int> PII;
unordered_map<long long,int>mp;
const int N = 5e5+10;
const int M = 8e6+10;
int e[M];
int idx,h[M],ne[M],w[M];
int a[6];
int cnt=0;
long long d[M];
bool st[M];
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dijkstra(int st1,int ed){
    memset(d,0x3f,sizeof d);
    d[st1]=0;
    priority_queue<PII,vector<PII>,greater<PII>>heap;
    heap.push({0,st1});
    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        long long ver=t.second,distance=t.first;
        if(st[ver])continue;
        st[ver]=1;
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=e[i];
            if(d[j]>d[ver]+w[i]){
                d[j]=d[ver]+w[i];
                heap.push({d[j],j});
            }
        }
    }
    if(d[ed]==0x3f3f3f3f3f3f3f3f)printf("-1");
    else printf("%lld",d[ed]);
}
signed main(){
    int n;
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++){
            scanf("%lld",&a[j]);
        }
        for(int j=1;j<=4;j++){
            if(a[j]==0)continue;
            for(int k=1;k<=4;k++){
                if(a[k]==0)continue;
                long long first=a[j]*1e9+i;
                long long second=i*1e9+a[k];
                if(mp[first]==0){
                    mp[first]=++cnt;
                }
                if(mp[second]==0){
                    mp[second]=++cnt;
                }
                if(k==j%4+1)
                    add(mp[first],mp[second],0);
                else{
                    add(mp[first],mp[second],1);
                }
            }
        }
    }  
    int stx,sty,edx,edy;
    scanf("%lld%lld%lld%lld",&stx,&sty,&edx,&edy);
    long long stt=stx*1e9+sty;
    long long edd=edx*1e9+edy;
    dijkstra(mp[stt],mp[edd]);
    return 0;
}