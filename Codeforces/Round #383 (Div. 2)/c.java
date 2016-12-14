import java.util.Scanner;

public class Main {
    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    static boolean vis[];
    static int sgn;

    public static int dfs(int pos, int step, int arr[], int n) {
        if (vis[pos]) {
            if (pos == sgn) return step;
            return -1;
        }
        vis[pos] = true;
        return dfs(arr[pos], step + 1, arr, n);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int arr[] = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = scan.nextInt();
        }
        vis = new boolean[n + 1];
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            sgn = i;
            int sta = dfs(i, 0, arr, n);
            if (sta != -1) {
                if (sta % 2 == 0) sta >>= 1;
                ans = lcm(ans, sta);
            } else {
                ans = -1;
                break;
            }
        }
        System.out.println(ans);
    }
}