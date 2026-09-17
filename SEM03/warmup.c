//agregado long long para probar
#include <stdio.h>
int main(void){
    printf("C version: %ld\n", __STDC_VERSION__);
    printf("En Bytes: int: %zu | long: %zu | long long: %zu | float: %zu | double: %zu\n",
    sizeof(int), sizeof(long), sizeof(long long), sizeof(float), sizeof(double));
    return 0;
}