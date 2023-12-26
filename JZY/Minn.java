package JZY;

import java.util.Scanner;

public class Minn {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int now = 0;
        for(int i = 1;;i ++){
            now += i * i;
            if(now > x){
                System.out.println(i);
                break;
            }
        }
    }
}
