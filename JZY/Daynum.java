/*
 * @Author: JorD
 * @LastEditTime: 2023-03-05 13:32:49
 */
package JZY;

import java.util.Scanner;

public class Daynum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int year = sc.nextInt();
        int month = sc.nextInt();
        if(month == 2){
            if(year % 4 == 0 && year % 100 != 0){
                System.out.println(29);
            }else if(year % 400 == 0){
                System.out.println(29);
            }else System.out.println(28);
        }else if(month <= 7){
            if(month % 2 == 1) System.out.println(31);
            else System.out.println(30);
        }else if(month % 2 == 1) System.out.println(30);
        else System.out.println(31);
    }
}
