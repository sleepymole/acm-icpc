import java.util.Scanner;

public class Main {
    public static long min(long a, long b) {
        return a < b ? a : b;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        long n = scan.nextLong();
        long a = scan.nextLong();
        long b = scan.nextLong();
        long c = scan.nextLong();
        long ans = (long) 1e18;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if ((n + i + j * 2 + k * 3) % 4 == 0) {
                        ans = min(ans, a * i + b * j + c * k);
                    }
                }
            }
        }
        System.out.println(ans);
    }
}