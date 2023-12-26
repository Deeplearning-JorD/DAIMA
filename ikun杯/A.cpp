#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], st[10];
int ji[N][N];
void dfs(int now, int len){
	if(len == 4){
//		int year = st[0] * 1000 + st[1] * 100 + st[2] * 10 + st[3];
		int month = st[4] * 10 + st[5];
		int day = st[6] * 10 + st[7];
			if(month == 2){
				if(day <= 28)
					ji[month][day] = 1;
				return;
			}
			if(month <= 7){
				if(day <= 31 && month % 2 == 1)
					ji[month][day] = 1;
				else if(month % 2 == 0 && day <= 30)
					ji[month][day] = 1;
			}else if(month > 7){
				if(day <= 31 && month % 2 == 0)
					ji[month][day] = 1; 
				else if(day <= 30 && month % 2 == 0)
					ji[month][day] = 1;
			}
			return;
	}
	if(now > 100) return;
	st[len] = a[now];
	dfs(now + 1, len + 1);
	dfs(now + 1, len);
}
int main(){
	int res = 0;
	for(int i = 1;i <= 100;i ++) cin >> a[i];
	dfs(1,4);
	for(int i = 1;i <= 31;i ++)for(int j = 1;j <= 31;j ++) res += ji[i][j];
	cout << res << endl; 
	return 0;
} 
