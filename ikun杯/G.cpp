#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
char s[N], s1[2], s2[2];
int v[N], idx;
int main(){
	int n; scanf("%d", &n);
	scanf("%s%s%s", s + 1, s1 + 1, s2 + 1);
	char c1 = s1[1], c2 = s2[1];
	int m = strlen(s + 1);
	long long res = 0;
	for(int i = 1;i <= m;i ++){
		if(s[i] == c2){
			int l = 0, r = idx;
			while(l < r){
				int mid = (l + r + 1) >> 1;
				if(i - v[mid] + 1 >= n) l = mid;
				else r = mid - 1;
			} 
			if(i - v[l] + 1 >= n) res += l;
		}
		if(s[i] == c1) v[++ idx] = i; 
	}
	printf("%lld", res); 
	return 0;
}