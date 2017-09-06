#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

#define BUF_SIZE 4096

struct {
    int cur, eof;
    char buf[BUF_SIZE];
    char next_char() {
        if (cur == BUF_SIZE) {
            if (eof) return -1;
            int bytes = fread(buf, 1, BUF_SIZE, stdin);
            if (bytes < BUF_SIZE) {
                memset(buf + bytes, -1, BUF_SIZE - bytes);
                buf[bytes] = -1;
                eof = 1;
            }
            cur = 0;
        }
        return buf[cur++];
    }
    int next_int() {
        int x = 0;
        char ch = next_char();
        while (ch < '0' || ch > '9') {
            if (ch == -1) return 0;
            ch = next_char();
        }
        while (ch >= '0' && ch <= '9') {
            x = (x << 3) + (x << 1) + ch - '0';
            ch = next_char();
        }
        return x;
    }
} IO = {BUF_SIZE};

void write(int n) {
    if (n >= 10) write(n / 10);
    putchar(n % 10 + '0');
}

int main() {
    // freopen("input", "r", stdin);
    // freopen("output", "w", stdout);
    int startTime = (int) ((double) clock() / CLOCKS_PER_SEC * 1000);
    int n = IO.next_int();
    cout << n << endl;
    int endTime = (int) ((double) clock() / CLOCKS_PER_SEC * 1000);
    cout << (endTime - startTime) << "ms" << endl;
    return 0;
}
