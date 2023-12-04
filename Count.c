#include <stdio.h>
int main(){
    int n;
    printf("Type in the limit of array:");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        printf("Input a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("Amount of array:%lu ",sizeof(a) / sizeof(a[0]));
    return 0;
}