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
void Solve(){
    int n;
    cin>>n;
    rep(i,1,n){
        string s;
        cin>>s;
        int now = siz(s);
        if(s.size()>=2){
            if(s[now-1]=='o'&&s[now-2]=='p'){
                cout<<"FILIPINO"<<endl;
                continue;
            }
        }
        if(s.size()>=4){
            if(s[now-1]=='u'&&s[now-2]=='s'){
                if(s[now-3]=='a'&&s[now-4]=='m'){
                    cout<<"JAPANESE"<<endl;continue;
                }else if(s[now-3]=='e'&&s[now-4]=='d'){
                    cout<<"JAPANESE"<<endl;
                    continue;
                }
            }
        }
        cout<<"KOREAN"<<endl;
    }

    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}