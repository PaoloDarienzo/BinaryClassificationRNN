// C 99

#include <stdio.h>
#include <string.h>

int T, W, H;
int alt[100][100];
int c[100][100];

char next_color;

char get_color(int i, int j) {
    if (c[i][j])
        return c[i][j];

    int min_alt = alt[i][j] - 1;

    if (i > 0 && alt[i - 1][j] < min_alt)
        min_alt = alt[i - 1][j];
    if (j > 0 && alt[i][j - 1] < min_alt)
        min_alt = alt[i][j - 1];
    if (j < W - 1 && alt[i][j + 1] < min_alt)
        min_alt = alt[i][j + 1];
    if (i < H - 1 && alt[i + 1][j] < min_alt)
        min_alt = alt[i + 1][j];
    
    if (i > 0 && alt[i - 1][j] == min_alt)
        return c[i][j] = get_color(i - 1, j);
    if (j > 0 && alt[i][j - 1] == min_alt)
        return c[i][j] = get_color(i, j - 1);
    if (j < W - 1 && alt[i][j + 1] == min_alt)
        return c[i][j] = get_color(i, j + 1);
    if (i < H - 1 && alt[i + 1][j] == min_alt)
        return c[i][j] = get_color(i + 1, j);

    return c[i][j] = next_color++;
}

int main() {
    scanf("%d", &T);
    for (int n = 1; n <= T; n++) {
        memset(c, 0, sizeof(c));
        next_color = 'a';
        
        scanf("%d %d", &H, &W);
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                scanf("%d", &alt[i][j]);

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (!c[i][j])
                    get_color(i, j);

        printf("Case #%d:\n", n);
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++) {
                printf("%c", c[i][j]);
                if (j < W - 1)
                    printf(" ");
                else
                    puts("");
            }
    }
    
    return 0;
}

