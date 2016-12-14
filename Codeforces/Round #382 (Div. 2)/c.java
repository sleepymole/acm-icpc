import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        long n = scan.nextLong();
        long f[] = new long[100];
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i < 100; i++) {
            f[i] = f[i - 1] + f[i - 2] + 1;
        }
        n--;
        int ans = 0;
        while (f[ans + 1] <= n) ans++;
        System.out.println(ans);
    }
}