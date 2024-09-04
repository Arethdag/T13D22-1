#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    char name[1000];
    char string[1000];
    char c[256];
    int status = 1;
    while (status != -1) {
        scanf("%d", &status);
        switch (status) {
            case 1:
                scanf("%s", name);
                f = fopen(name, "r");
                if (f == NULL) {
                    printf("n/a\n");
                    fclose(f);
                } else {
                    if (fgets(c, 256, f) == NULL) {
                        printf("n/a\n");
                    } else {
                        fgets(c, 256, f);
                        printf("%s", c);
                    }
                }
                break;
            case 2:
                f = fopen(name, "a");
                if (f == NULL) {
                    printf("n/a\n");
                    fclose(f);
                } else {
                    fflush(stdin);
                    fgets(string, 1000, stdin);
                    fprintf(f, "%s", string);
                    fclose(f);
                    f = fopen(name, "r");
                    printf("\n");
                    while (!feof(f)) {
                        if (fgets(c, 256, f) != NULL) printf("%s", c);
                    }
                    printf("\n");
                }
                fclose(f);
                break;
            case -1:
                break;
            default:
                printf("n/a\n");
                // status = -1;
                break;
        }
    }
    return 0;
}