import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int k=scan.nextInt();
        String str=scan.next();
        boolean found=false;
        for(int i=0;i<n;i++){
            if(str.charAt(i)=='T'||str.charAt(i)=='G'){
                for(int j=i+k;j<n;j+=k){
                    if(str.charAt(j)=='T'||str.charAt(j)=='G'){
                        found=true;
                        break;
                    }else if(str.charAt(j)=='#'){
                        break;
                    }
                }
                break;
            }
        }
        if(found) System.out.println("YES");
        else System.out.println("NO");
    }
}