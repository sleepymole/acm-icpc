import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        int a[] = new int[n + 1];
        int b[] = new int[m];
        for (int i = 1; i <= n; i++) {
            a[i] = scan.nextInt();
        }
        for (int i = 0; i < m; i++) {
            int l = scan.nextInt();
            int r = scan.nextInt();
            for (int j = l; j <= r; j++) {
                b[i] += a[j];
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (b[i] > 0) ans += b[i];
        }
        System.out.println(ans);
    }
}