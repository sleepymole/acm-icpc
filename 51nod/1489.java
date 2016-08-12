import java.util.Scanner;

public class Main{
    static int a;
    static int b;
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        a = scan.nextInt();
        b = scan.nextInt();
        int[] h = new int[n + 3];
        for (int i = 0; i < n; i++) {
            h[i] = scan.nextInt();
            h[i]++;
        }
        int ans=solve(h,n);
        System.out.println(ans);
    }
    public static int solve(int[] h,int n){
        if(n==3) return Math.max(Math.max((h[0]-1)/b+1,(h[2]-1)/b+1),(h[1]-1)/a+1);
        int x=(h[0]-1)/b+1;
        int y=(h[n-1]-1)/b+1;
        h[1]-=a*x;
        h[2]-=b*x;
        h[n-2]-=a*y;
        h[n-3]-=b*y;
        return x+y+dfs(h,1,n-2);
    }
    public static int dfs(int[] h,int s,int e){
        if(s==e) return h[s]>0?(h[s]-1)/a+1:0;
        if(h[s]<=0) return dfs(h,s+1,e);
        int ans=0x3f3f3f3f;
        int[] tmp=h.clone();
        int k=(h[s]-1)/a+1;
        for(int i=0;i<=k;i++){
            h=tmp.clone();
            int tot=i;
            h[s]-=i*a;
            h[s+1]-=i*b;
            if(h[s]>0){
                int t=(h[s]-1)/b+1;
                tot+=t;
                h[s+1]-=a*t;
                h[s+2]-=b*t;
            }
            tot+=dfs(h,s+1,e);
            ans=Math.min(ans,tot);
        }
        return ans;
    }
}