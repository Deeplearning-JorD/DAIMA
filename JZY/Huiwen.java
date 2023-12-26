/*
 * @Author: JorD
 * @LastEditTime: 2023-03-12 13:22:22
 */
package JZY;

public class Huiwen {
    public static void main(String[] args) {
        for(int i = 1;i <= 9;i ++){
            for(int j = 0;j <= 9;j ++){
                for(int k = 0;k <= 9;k ++){
                    if(i == k){
                        System.out.println(""+i+j+k);
                    }
                }
            }
        }
    }
}
