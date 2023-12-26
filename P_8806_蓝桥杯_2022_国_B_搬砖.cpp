/*
 * @Author: JorD
 * @LastEditTime: 2023-06-06 22:22:51
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nord{
	int w,v;
}a[1234567];
int f[1234567];
bool cmp(nord x,nord y){
    if(x.v == y.v) return x.w < y.w;
    return x.v < y.v;
}
main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i].w>>a[i].v;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
		for (int j=min(a[i].w+a[i].v,(int)40000);j>=a[i].w;j--)//这里要注意，不能超过重量+价值的和。
			f[j]=max(f[j],f[j-a[i].w]+a[i].v);
	int ans=0;
	for (int i=0;i<=40000;i++) ans=max(ans,f[i]);
	cout <<ans;	
    return 0;
}