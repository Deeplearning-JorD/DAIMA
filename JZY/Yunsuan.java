/*
 * @Author: JorD
 * @LastEditTime: 2023-03-12 13:11:45
 */
package JZY;

import java.util.Scanner;

public class Yunsuan {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int now = sc.nextInt();
        double res = 0;
        int d = 0;
        for(int i = 1;i <= now;i ++){
            if(d == 0){
                res += i;
            }else if(d == 1){
                res -= i;
            }else if(d == 2){
                res *= i;
            }else if(d == 3){
                res /= i;
            }
            d ++;
            d %= 4;
        }
        System.out.println(res);
    }
}
