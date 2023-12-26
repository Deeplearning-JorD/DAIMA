/*
 * @Author: JorD
 * @LastEditTime: 2023-03-18 21:12:35
 */
package JZY;

import java.util.Scanner;

public class Czyz {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double r = sc.nextDouble(), h = sc.nextDouble();
        Yz ikun = new Yz(r, h);
        System.out.println(ikun.mj() + " " + ikun.tj());
    }
}
class Yz{
    double r, h;
    Yz(double r, double h){
        this.r = r;
        this.h = h;
    }
    double mj(){
        return 3.14 * r * r * 2 + h * 2 * 3.14 * r;
    }
    double tj(){
        return 3.14 * r * r * h;
    }
}
