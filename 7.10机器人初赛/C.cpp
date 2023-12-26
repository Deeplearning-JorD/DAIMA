#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,int> q;
signed main(){
    string s;
	cin>>s;
	vector<pair<int,int>> a;
	vector<char> op;
	vector<bool> st(s.size()+1,false);
	int sum1=0,sum2=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='d'){
			st[i]=true;
			int l=i-1,r=i+1;
			int pre=0,last=0;
			while(r<s.size()&&s[r]>='0'&&s[r]<='9'){
				st[r]=true;
				last=last*10+s[r]-'0';
				r++;
			}
			int p=1;
			while(l>=0&&s[l]>='0'&&s[l]<='9'){
				st[l]=true;
				pre=pre+(s[l]-'0')*p;
				p*=10;
				l--;
			}
			// cout<<l<<endl;
			if(pre==0) pre++;
			if(l>=0){
				st[l]=true;
				if(s[l]=='+'){
					sum1+=pre*last;
					sum2+=pre;
				}else{
					sum1-=pre;
					sum2-=pre*last;
				}
			}else{
				sum1+=pre*last;
				sum2+=pre;
			}
			// a.push_back({pre,last});
			// cout<<pre<<' '<<last<<' '<<i<<endl;
			q[last]+=pre;
		}
	}
	for(int i=0;i<s.size();i++){
		if(st[i]||s[i]=='+'||s[i]=='-') continue;
		int j=i;
		int now=0;
		while(j<s.size()&&s[j]>='0'&&s[j]<='9'&&!st[j]){
			st[j]=true;
			now=now*10+s[j]-'0';
			j++;
		}//cout<<now<<endl;
		if(i>0){
			if(s[i-1]=='+'){
				sum1+=now;
				sum2+=now;
			}else if(s[i-1]=='-'){
				sum1-=now;
				sum2-=now;
			}
		}else{
			sum1+=now;
			sum2+=now;
		}
		
	}
	for(auto x:q){
		cout<<x.first<<' '<<x.second<<endl;
	}cout<<sum2<<' '<<sum1;
}