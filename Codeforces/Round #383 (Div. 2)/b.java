import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int x = scan.nextInt();
        int maxSize = 1 << 17;
        int num[] = new int[maxSize];
        for (int i = 0; i < n; i++) {
            int tmp = scan.nextInt();
            num[tmp]++;
        }
        long ans = 0;
        for (int i = 0; i < maxSize; i++) {
            if (x == 0) ans += (long) num[i] * (num[i] - 1);
            else ans += (long) num[i] * num[i ^ x];
        }
        ans /= 2;
        System.out.println(ans);
    }
}