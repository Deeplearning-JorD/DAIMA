/*
 * @Author: JorD
 * @LastEditTime: 2023-05-06 17:17:44
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const char df[]="oiiai";
ll ans,dpl[100010][4],dpr[100010][4];
char sum[100010];
vector<int>num[100010];
void dfs(int x,int fa){
    for(auto i:num[x])if(i!=fa){
        dfs(i,x);
        for(int j=0;j<4;j++)
        dpl[x][j]=(dpl[x][j]+dpl[i][j])%mod,
        dpr[x][j]=(dpr[x][j]+dpr[i][j])%mod;
    }ll res=0;
    for(auto i:num[x])if(i!=fa){
        for(int j=0;j<4;j++)
        dpl[x][j]=(dpl[x][j]-dpl[i][j]+mod)%mod,
        dpr[x][j]=(dpr[x][j]-dpr[i][j]+mod)%mod;
        for(int j=0;j<4;j++){
            ans+=dpl[x][j]*dpr[i][3-j]%mod;
        }
        for(int j=0;j<3;j++){
            if(sum[x]==df[j+1])
            ans+=dpl[x][j]*dpr[i][2-j]%mod;
        }
        for(int j=0;j<4;j++)
        dpl[x][j]=(dpl[x][j]+dpl[i][j])%mod,
        dpr[x][j]=(dpr[x][j]+dpr[i][j])%mod;
        ans%=mod;
    }
    if(sum[x]=='o'){
        ans=(ans+dpr[x][3])%mod;
        dpl[x][0]++;
    }
    if(sum[x]=='i'){
        ans=(ans+dpl[x][3])%mod;
        dpl[x][2]=(dpl[x][2]+dpl[x][1])%mod;
        dpl[x][1]=(dpl[x][1]+dpl[x][0])%mod;
        dpr[x][0]++;
        dpr[x][3]=(dpr[x][3]+dpr[x][2])%mod;
        dpr[x][2]=(dpr[x][2]+dpr[x][1])%mod;
    }
    if(sum[x]=='a'){
        dpl[x][3]=(dpl[x][3]+dpl[x][2])%mod;
        dpr[x][1]=(dpr[x][1]+dpr[x][0])%mod;
    }
}
int main(){
    int n;scanf("%d",&n);
    scanf("%s",sum+1);
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        num[x].push_back(y);
        num[y].push_back(x);
    }dfs(1,0);
    printf("%lld",ans%mod);
}