import java.awt.*;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(), n1 = scan.nextInt(), n2 = scan.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scan.nextInt();
        }
        Arrays.sort(a);
        if (n1 < n2) {
            int tmp = n1;
            n1 = n2;
            n2 = tmp;
        }
        long sum1 = 0, sum2 = 0;
        for (int i = n - n1 - n2; i < n - n2; i++) {
            sum1 += a[i];
        }
        for (int i = n - n2; i < n; i++) {
            sum2 += a[i];
        }
        double ans = 1.0 * sum1 / n1 + 1.0 * sum2 / n2;
        System.out.printf("%.8f\n", ans);
    }
}