#include <stdio.h>
#include <ctype.h>

int main() {
    char grm[20][20];
    int n, i, j;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", grm[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 3; grm[i][j] != '\0'; j++) {

            // Check for two non-terminals together
            if (isupper(grm[i][j]) && isupper(grm[i][j+1])) {
                printf("Not operator grammar\n");
                return 0;
            }
        }
    }

    printf("Operator grammar\n");
    return 0;
}
