/*
 * @Author: JorD
 * @LastEditTime: 2023-03-05 13:22:03
 */
package JZY;

import java.util.Scanner;

public class zhuanhuan {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double h = sc.nextDouble();
        h *= 3600;
        System.out.println((int)(h/3600)); 
        System.out.println((int)((h%3600)/60));
        System.out.println((int)(h % 60));
    }
}
