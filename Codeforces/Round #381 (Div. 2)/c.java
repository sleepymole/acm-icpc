import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        int len = n;
        for (int i = 0; i < m; i++) {
            int l = scan.nextInt();
            int r = scan.nextInt();
            if (r - l + 1 < len) len = r - l + 1;
        }
        System.out.println(len);
        for (int i = 0; i < n; i++) {
            System.out.print((i % len) + " ");
        }
        System.out.println();
    }
}