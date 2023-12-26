/*
 * @Author: JorD
 * @LastEditTime: 2023-03-05 13:12:21
 */
package JZY;

import java.util.Scanner;

public class Fenjie {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        System.out.println(a % 10);
        a /= 10;
        System.out.println(a % 10);
        a /= 10;
        System.out.println(a % 10);
        a /= 10;
        System.out.println(a % 10);
        a /= 10;
        System.out.println(a % 10);
    }

}
