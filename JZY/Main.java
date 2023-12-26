package JZY;
import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[]args){
        new Main().run();
    }
    Scanner in=new Scanner(System.in);
    int n,m,i,u,v,x,y;
    int f[];
    int f(int a){
        if(f[a]==a)return a;
        return f[a]=f(f[a]);
    }
    boolean merge(int x,int y){
        System.out.println(x+"!"+y);
        x=f(x);
        y=f(y);
        if(x==y){
            w[x]=1;
            return false;
        }
        f[x]=y;
        if(w[x]==1)w[y]=1;
        return true;
    }
    int []w;
    void solve(){
        n=in.nextInt();
        m=in.nextInt();
        f=new int[n<<1|1];
        w=new int[n<<1|1];
        for(i=1;i<f.length;i++)f[i]=i;
        for(i=1;i<=n;i++){
            merge(i, i+n);
        }
        int a=0,b=0;
        while(m-->0){
            u=in.nextInt()+(in.next().charAt(0)=='B'?n:0;
            v=in.nextInt()+(in.next().charAt(0)=='B'?n:0);
            merge(u,v);
        }
        for(i=1;i<f.length;i++){
            System.out.println(i+" "+f[i]+" "+w[i]);
            if(f[i]==i){
                if(w[i]==1)a++;
                else b++;
            }
        }
        System.out.println();
        System.out.println(a+" "+b);
    }
    int te;
    void run(){
        int t=1;
        // t=in.nextInt();
        for(te=1;te<=t;te++){
            solve();
        }

    }
}