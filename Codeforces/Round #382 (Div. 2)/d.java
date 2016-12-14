import java.util.Scanner;

public class Main {
    public static boolean isPrime(int n) {
        if (n == 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int ans;
        if (isPrime(n)) ans = 1;
        else if (n % 2 == 0) ans = 2;
        else if (isPrime(n - 2)) ans = 2;
        else ans = 3;
        System.out.println(ans);
    }
}