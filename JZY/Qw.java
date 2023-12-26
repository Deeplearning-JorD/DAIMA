/*
 * @Author: JorD
 * @LastEditTime: 2023-03-12 13:21:45
 */
package JZY;

import java.util.Scanner;

public class Qw {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double n = sc.nextInt();
        double now = 0, down = 5;
        for(int i = 1;;i ++){
            now += 6;
            if(now >= n){
                System.out.println(i);
                break;
            }
            now -= down;
            down /= 2;
        }
    }
}
