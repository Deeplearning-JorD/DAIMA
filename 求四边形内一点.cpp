/*
 * @Author: JorD
 * @LastEditTime: 2022-08-14 15:37:02
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define double long double
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
double k;
double x1,x2,dy1,y2;
double getlen(double a,double b,double x,double y){
    double len = sqrt((a-x)*(a-x)+(b-y)*(b-y));
    return len;
}
double gets(double a,double b,double c){
    double p=(a+b+c)/2;
    double res=sqrt(p*(p-a)*(p-b)*(p-c));
    return res;
}
double getl(double mid){
    double y=k*mid;
    double ed=getlen(mid,y,0,dy1);
    double ea=getlen(x1,0,mid,y);
    double da=getlen(0,dy1,x1,0);
    return gets(ea,ed,da);
}
double getr(double mid){
    double y=k*mid;
    double ec=getlen(mid,y,0,y2);
    double eb=getlen(x2,0,mid,y);
    double cb=getlen(0,y2,x2,0);
    return gets(ec,eb,cb);
}
bool check(double mid){
    if(getr(mid)-getl(mid)>1e-6) return true;
    return false;
}
void Solve(){
    cin>>x1>>x2>>dy1>>y2;    
    // A(x1,0)
    // B(x2,0)
    // C(0,y2)
    // D(0,dy1)
    double cd=y2-dy1;
    double ca=getlen(0,y2,x1,0);
    double da=getlen(0,dy1,x1,0);
    double ab=x2-x1;
    double cb=getlen(0,y2,x2,0);
    k = cd/ab;
    double x=0,y;
    double l=0,r=x2;
    while(r-l>1e-6){
        double mid = (l+r)/2;
        if(check(mid))  l=mid;
        else r=mid;
    }
    cout<<SPO(6)<<l<<' '<<k*l<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}