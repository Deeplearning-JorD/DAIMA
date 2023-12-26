/*
 * @Author: JorD
 * @LastEditTime: 2023-03-12 13:16:54
 */
package JZY;

import java.util.Scanner;

public class Jttn {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt(), n = sc.nextInt();
        int x = (n - 2 * m) / 2, y = m - x;
        System.out.println("鸡："+x+"，兔子："+y);
    }
}

