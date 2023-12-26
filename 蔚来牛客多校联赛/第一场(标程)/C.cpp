#include <bits/stdc++.h>
using namespace std;

#define N 300110
const long long INF=0x3f3f3f3f3f3f3f3f;

struct Frac{
	long long a,b;
	bool operator <(const Frac &_)const{
		return a*_.b<b*_.a;
	}
};

int n,m,k,q;
int poi[N],Y[N],X[N];
long long h[N];

void solve(){
	fill(h+1,h+m+1,n);
	fill(poi+1,poi+m+1,n+1);
	int i;
	for (i=1;i<=k;i++){
		poi[X[i]]=min(poi[X[i]],Y[i]);
	}

	Frac L={INF,1LL};
	for (i=2;i<=m;i++){
		if (L.a!=INF){
			long long y=L.a,x=L.b;
			h[i]=min(h[i],(y*(i-1)-1)/x);
		}
		L=min(L,(Frac){poi[i],i-1});
	}

	Frac R={INF,1LL};
	for (i=m-1;i>=1;i--){
		if (R.a!=INF) {
			long long y=R.a,x=R.b;
			h[i]=min(h[i],(y*(m-i)-1)/x);
		}
		R=min(R,(Frac){poi[i],m-i});
	}

	long long ans=0;
	for (i=1;i<=m;i++){
		h[i]=min(h[i],poi[i]-1LL);
		ans+=h[i];
	}
	printf("%lld\n",ans);
}
int main() {
	int i;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for (i=1;i<=k;i++){
		scanf("%d%d",&Y[i],&X[i]);
	}
	for (i=1;i<=q;i++){
		int p,x,y;
		scanf("%d%d%d",&p,&x,&y);
		Y[p]=x,X[p]=y;
		solve();
	}
	return 0;
}
