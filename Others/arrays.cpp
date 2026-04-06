#include <cstdio>
#include <iostream>

int main(){
    int a[10];
    int n = 5;

    for (int i = 0; i < n; i++) {
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }
    int idx;
    int val;
    printf("Enter the index: ");
    scanf("%d", &idx);
    printf("Enter the value: ");
    scanf("%d", &val);
    for (int i = 5; i > idx; i--) {
    a[i] = a[i - 1];
    };
    a[idx] = val;
    for (int i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    };
    int delete_val;
    printf("Enter the index: ");
    scanf("%d", &delete_val);
    for (int i = delete_val; i < 5; i++){
        a[i] = a[i+1];
    };
    n--;
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
