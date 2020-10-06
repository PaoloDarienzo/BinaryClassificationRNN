// C 99

#include <stdio.h>
#include <string.h>

int L, D, N;
char gwords[5000][16];
char cword[15][26]; // 1 if letter from index i1 of test word can be i2
char str[17 * 5000 + 1];  // a test case

int main() {
    scanf("%d %d %d\n", &L, &D, &N);
    // L = length of words
    // D = # good words
    // N = # test cases
    
    for (int i = 0; i < D; i++)
        scanf("%s\n", gwords[i]);

    for (int i = 1; i <= N; i++) {
        memset(cword, 0, sizeof(cword));
        scanf("%s\n", str);
        int pc = 0;
        for (int j = 0; j < L; j++) {
            if (str[pc] == '(')
                while (str[++pc] != ')')
                    cword[j][str[pc] - 'a'] = 1;
            else cword[j][str[pc] - 'a'] = 1;
            pc++;
            }
            
        int cnt = 0;
        for (int j = 0; j < D; j++) {
            int g = 0;
            while (g < L && cword[g][gwords[j][g] - 'a'])
                g++;
                
            cnt += g == L;
        }
        
        printf("Case #%d: %d\n", i, cnt);
    }
    
    return 0;    
}

