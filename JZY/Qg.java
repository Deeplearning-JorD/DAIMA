/*
 * @Author: JorD
 * @LastEditTime: 2023-03-05 13:26:32
 */
package JZY;

import java.util.Scanner;

public class Qg {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a, b, c;
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();
        double d = b * b - 4 * a * c;
        if(d < 0) System.out.println("无实根");
        else if(d == 0){
            System.out.println(- b / (2 * a));
            System.out.println("1个");
        }else{
            System.out.println((-b - d) / (2 * a));
            System.out.println((-b + d) / (2 * a));
            System.out.println("2个");
        }
    }
}
