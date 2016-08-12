import java.beans.beancontext.BeanContext;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static  void main(String[] args){
        Scanner scan=new Scanner(System.in);
        int t=scan.nextInt();
        for(int i=0;i<t;i++){
            long a=scan.nextLong();
            long b=scan.nextLong();
            if(a>b) {
                long tmp = a;
                a = b;
                b = tmp;
            }
            BigDecimal gold=new BigDecimal("1.6180339887498948482045868");
            BigDecimal c=BigDecimal.valueOf(b-a);
            long x=gold.multiply(c).longValue();
            if(a==x) System.out.println('B');
            else  System.out.println('A');
        }

    }
}