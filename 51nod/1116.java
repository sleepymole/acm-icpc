import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scan=new Scanner((System.in));
        String s=scan.next();
        int minAry=0;
        int sum=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int c=(s.charAt(i)>='0'&&s.charAt(i)<='9')?s.charAt(i)-'0':s.charAt(i)-'A'+10;
            minAry=Math.max(minAry,c+1);
            sum+=c;
        }
        int x=0;
        boolean found=false;
        if(minAry>1){
            for(int i=minAry;i<=36;i++){
                if(sum%(i-1)==0){
                    found=true;
                    x=i;
                    break;
                }
            }
        }
        if(found) System.out.println(x);
        else System.out.println("No Solution");
    }
}