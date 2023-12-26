/*
 * @Author: JorD
 * @LastEditTime: 2022-08-14 13:07:03
 */
#include <bits/stdc++.h>
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
map<char,pair<int,int>> q;
void Solve(){
    string s;
    cin>>s;
    for(auto x:s){
        if(x>='A'&&x<='Z'){
            x=(char)((int)x+32);
            cout<<"3 1 ";
        }
        cout<<q[x].first<<' '<<q[x].second<<endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    string s=" qwertyuiop asdfghjkl zxcvbnm";
    int xx=0,y=0;
    for(auto x:s){
        if(x==' '){
            xx++;y=0;
            if(xx==3) y=1;
        }else{
            y++;
            q[x]={xx,y};
        }
    }
    while(t--)
    Solve();
    return 0;
}