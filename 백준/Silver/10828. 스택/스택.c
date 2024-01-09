#include <stdio.h>

int stack[10000];
int topnum = 0;
void push(int item) {
    if (topnum >= 9999) {
        return;
    }
    topnum++;
    stack[topnum] = item;
}
char pop(void) {
    int item;

    if (topnum <= 0)
        printf("-1\n");
    else {
        item = stack[topnum];
        topnum--;
        printf("%d\n", item);
    }
}
char size(void) {
    printf("%d\n", topnum);
}
char empty(void) {
    if (topnum == 0) {
        printf("1\n");
    }
    else
        printf("0\n");
}
char top(void) {
    int item;

    if (topnum <= 0)
        printf("-1\n");
    else {
        item = stack[topnum];
        printf("%d\n", item);
    }
}

int main() {
    char arr[6];
    int N, n;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", &arr);
        if (strcmp(arr, "push") == 0) {
            scanf("%d", &n);
            push(n);
        }
        else if (strcmp(arr, "pop") == 0) {
            pop();
        }
        else if (strcmp(arr, "size") == 0) {
            size();
        }
        else if (strcmp(arr, "empty") == 0) {
            empty();
        }
        else if (strcmp(arr, "top") == 0) {
            top();
        }
    }
}