#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
1 <= L <= 15
1 <= D <= 5000
1 <= N <= 500
*/

int L, D, N;

#define L_MAX 15
#define D_MAX 5000
#define N_MAX 500

char vocab[D_MAX][L_MAX + 1+ 3];

#define TEST_CASE_LEN 1000
char testCase[TEST_CASE_LEN + 1];

FILE *fin;

void Solve(char *testCase, int numTestCase) {
    /*
    (ab)(bc)(ca)
    abc
    (abc)(abc)(abc)
    (zyx)bc
    */

    int i;

    int startPos[L_MAX];
    int endPos[L_MAX];
    int pos;
    int letter;
    int numMatches = 0;



    //Parse the test case pattern
    pos = 0;
    for (i = 0; i < L; i++) {
        if (testCase[pos] == '(') {
            pos++;
            startPos[i] = pos;
            for (;; pos++)
                if (testCase[pos] == ')') {
                    endPos[i] = pos - 1;
                    pos++;
                    break;
                }
        }
        else {
            startPos[i] = endPos[i] = pos;
            pos++;
        }
    }
    assert(pos == strlen(testCase));

    for (i = 0; i < D; i++) {

        for (letter = 0; letter < L; letter++) {
            if (startPos[letter] == endPos[letter]) {
            //one letter
                if (testCase[startPos[letter]] != vocab[i][letter])
                    break;
            }
            else
            if (startPos[letter] < endPos[letter]) {
            //interval in parantheses
                for (pos = startPos[letter]; pos <= endPos[letter]; pos++) {
                    if (testCase[pos] == vocab[i][letter])
                        break;
                }
                if (pos == endPos[letter] + 1)
                    break;
            }
        }

        if (letter == L)
        //word vocab[i] is matching the pattern
            numMatches++;
    }

    printf("Case #%d: %d\n", numTestCase + 1, numMatches);
}

void ReadData() {
    int i, j;
    #define STRLEN_MAX 100
    char str[STRLEN_MAX + 1];

    fscanf(fin, "%d", &L);
    assert(L >= 1 && L <= L_MAX);

    fscanf(fin, "%d", &D);
    assert(D >= 1 && D <= D_MAX);

    fgets(str, STRLEN_MAX, fin);
    sscanf(str, "%d", &N);
    //scanf("%d", &N);
    assert(N >= 1 && N <= N_MAX);

    for (i = 0; i < D; i++) {
        fgets(vocab[i], L_MAX + 3, fin);

        if (vocab[i][strlen(vocab[i]) - 1] == '\n')
            vocab[i][strlen(vocab[i]) - 1] = 0;
        if (vocab[i][strlen(vocab[i]) - 1] == '\r')
            vocab[i][strlen(vocab[i]) - 1] = 0;
        //scanf("%s", vocab[i], L_MAX, stdin);
        //printf("%s %d\n", vocab[i], strlen(vocab[i]));

        assert(strlen(vocab[i]) == L);

        for (j = 0; j < L; j++)
            if ( !(vocab[i][j] >= 'a' && vocab[i][j] <= 'z') )
                break;
        if (j < L) {
            D--;
            i--;
            continue;
        }

    }
    //"You may assume that all known words provided are unique."

    for (i = 0; i < N; i++) {
        fgets(testCase, TEST_CASE_LEN, fin);
        if (testCase[strlen(testCase) - 1] == '\n')
            testCase[strlen(testCase) - 1] = 0;
        if (testCase[strlen(testCase) - 1] == '\r')
            testCase[strlen(testCase) - 1] = 0;

        Solve(testCase, i);
    }
}

int main() {
    //freopen("Z:\\1Job_Search\\Google\\Google_CodeJAM_2009\\Qualification Round\\A\\A2.in", "rt", stdin);
    fin = stdin;
    ReadData();

    fclose(fin);

    return 0;
}
