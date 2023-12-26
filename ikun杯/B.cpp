#include<bits/stdc++.h>
using namespace std;
const int N = 3e7, M = 23333333;
double a[N];
int main(){
	double x = 11625907.5798;
	cout << -1.0/3 * log2(1.0/3)-2.0/3*log2(2.0/3)-2.0/3*log2(2.0/3)<<endl;
	for(int i = 1;i <= 23333333;i ++){
	a[i] = - i * (1.0 * i / M) * log2(1.0 * i / M) - (1.0 * M - i) * (1.0 * M - i) / M * log2((1.0 * M - i) / M); 
	if(fabs(a[i] - x) <= 0.001){
		printf("%lf %lf %d\n", a[i], x, i); 
	} 
	}
	cout << 11027421 << ' ' << M - 11027421 << ' ' << (int)(11027421 > (M - 11027421)) << endl;
	return 0;
} 
