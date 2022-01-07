#include <stdio.h>
#include "../../include/helper.h"

int is_digit(char c);

int is_digit(char c) {
    int r = 0;

    if ((c>=48) && (c<=57)) {
        r = 1;
    }

    return (r);
}

// Given valid strings with numbers in it return adition string.
char *add(char *n1, int n1l, char *n2, int n2l) {
    int i = 0;
    char *res = NULL;
    int blen = 0, slen = 0;
    char *bs = NULL, *ss = NULL;

    // First check if both input strings are valid strings.
    for (i=0; i<2; i++) {
        char *temp = NULL;

        if (i == 0) {
            temp = n1;
        } else {
            temp = n2;
        }

        while (*temp) {
            if (is_digit(*temp) == 0) {
                printf("Invalid input string\n");
                goto error;
            }
            temp++;
        }
    }

    // decide which string is bigger.
    blen = strlen(n1);
    slen = strlen(n2);
    if (blen > slen) {
        bs = n1;
        ss = n2;
    } else {
        bs = n2;
        ss = n1;
        i = blen;
        blen = slen;
        slen = i;
    }

    // allocate memory for result.
    i = blen + 1;
    res = malloc(i);
    if (!res) {
        printf("Error: allocating memeotu\n");
        exit(0);
    }
    memset(res, '.', i);
    res[i] = '\0';

#define val(c)      ((c) - '0')
#define tochar(n)   ()
    char ch_arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    // put pointers at right places.
    char *b = bs + (blen - 1);
    char *s = ss + (slen - 1);
    char *r = res + (i - 1);
    char c = 0;
    int diff = blen - slen;

    while (slen--) {
        int nu = val(*b) + val(*s) + c;

        if (nu >= 10) {
            c = 1;
        } else {
            c = 0;
        }

        nu = nu % 10;
        *r = ch_arr[nu];
        r--; b--; s--;
    }

    while (diff--) {
        int nu = val(*b) + c;

        if (nu >= 10) {
            c = 1;
        } else {
            c = 0;
        }
        nu = nu % 10;
        *r = ch_arr[nu];
        r--; b--;
    }

    if (c == 1) {
        *r = ch_arr[1];
        r--;
    }

    return (res);

error:
    res = NULL;
    return res;
}

/*
 * Given two large strings containing large numbers, perform addition.
 */
int main() {
    char n1[100], n2[100];
    char *res = NULL;

    memset(n1, 0, sizeof(n1));
    memset(n2, 0, sizeof(n2));

    printf("e first n: ");
    scanf("%s", n1);
    printf("\ne second n: ");
    scanf("%s", n2);
#if 0
    strcpy(n1, "9999999999");
    strcpy(n2, "1");
#endif

    printf("n1_len = %d, n2_len=%d\n", strlen(n1), strlen(n2));
    printf("n1 = %s\n+\nn2 = %s\n", n1, n2);
    printf("-------------------\n");

    res = add(n1, strlen(n1), n2, strlen(n2));

    printf("Result = %s\n", res);

    free(res);

    return (0);
}
