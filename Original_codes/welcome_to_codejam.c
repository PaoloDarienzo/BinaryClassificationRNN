// C 99

#include <stdio.h>
#include <string.h>

char welcome[] = "welcome to code jam";
int wlen = sizeof(welcome) - 1;

int m1[500], m2[500];
int *p1 = m1, *p2 = m2, *pt;
char str[501];

int main() {
    int N;
    scanf("%d\n", &N);
    for (int n = 1; n <= N; n++) {
        gets(str);
        int slen = strlen(str);

        for (int i = 0; i < wlen; i++) {
            for (int j = 0; j < slen; j++) {
                p2[j] = j > 0 ? p2[j - 1] : 0;
                if (welcome[i] == str[j]) {
                    p2[j] += i > 0 ? p1[j] : 1;
                    p2[j] %= 10000;
                }
            }

            pt = p2;
            p2 = p1;
            p1 = pt;
        }
        
        printf("Case #%d: %04d\n", n, p1[slen - 1]);
    }
        
    return 0;
}

