/*
 * @Author: JorD
 * @LastEditTime: 2023-03-12 13:05:17
 */
package JZY;

import java.util.Scanner;

/**
 * Sulie
 */
public class Sulie {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int now = sc.nextInt();
        if(now <= 3){
            System.out.println(1);
        }else{
            int a = 1, b = 1, c = 1, d = 0;
            for(int i = 4;i <= now;i ++){
                d = a + b + c;
                a = b;
                b = c;
                c = d;
            }
            System.out.println(d);
        }
    }
}