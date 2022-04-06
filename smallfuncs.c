#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*checks an integer array for duplicate values,
behavior undefined if no duplicate value
*arr: int arr being checked
length: length of array
returns: first non-duplicated element
*/
int nondup(int *arr, unsigned length){
        for(int i = 0; i < length; i+=1){
                int dup = 0;
                /*checks for duplicate element*/
                for(int j = 0; j < length; j+=1){
                        if(arr[i] == arr[j])
                                dup+=1;
                }
                if(dup < 2) {
                        return arr[i];
                }
        }
}
/*writes the fibonacci sequence to *dest until num
*dest: where fib numbers are being written to
num: how long sequence is being counted to
*/ 
void fibarray(unsigned char *dest, unsigned num){
        if(num == 0)
                return;
        if(num == 1){
                *dest = 1;
                return;
        }

        *dest = 1;
        *(dest + 1) = 1;

        for(int i = 2; i < num; i++){
                *(dest + i) = *(dest + i - 1) + *(dest + i - 2);
        }
}
/* reverses the first length elements of arr in place
*arr: array being manipulated
length; how much of the array is reversed
*/
void reverse(int *arr, unsigned length){
        for(int i =0; i < length / 2; i+=1){
        int temp = *(arr + length - 1 - i);
        *(arr + length - 1 - i) = *(arr + i);
        *(arr + i) = temp;
        }
}/*converts all lower case letters in s to upper case letters
*s: string being converted
*/
void capitalize(char *s) {
        for (int i = 0; s[i] != '\0'; i++) {
                /*checks for valid character*/
                if(s[i] >= 'a' && s[i] <= 'z') {
                        *(s + i) = *(s + i) - 32;
                }
        }
}
/*rearranges first length values of arr such that non-zero values
maintain order and zero values are pushed to the end
*arr: array being manipulated
length; point in array before zeros stop being pushed
*/
void push0(int *arr, unsigned length){
        int zcount = 0;
        int nonZero[length];
        int j = 0;
        for(int i = 0; i < length; i++){
                if(arr[i] == 0){
                zcount++;
                }
                else{
                nonZero[j] = arr[i];
                j++;
                }
        }
        /*moves ordered non-zeros to arr*/
        for(int i = 0; i < length; i++){
                arr[i] = nonZero[i];
        }
        for(int i = (length - zcount); i < length; i++){
                arr[i] = 0;
        }
}
int main() {
        /*Test capitalize*/
        char *s = strdup("the book \"The C Programming Language.\"");
        printf("before: %s\n", s);
        capitalize(s);
        printf("after:  %s\n", s);
        free(s);

        /*Test fibarray*/
        unsigned char a[64];
        fibarray(a, 64);
        for (int row=0; row<4; row+=1) {
                for (int col=0; col<16; col+=1) {
                        printf(" %02hhx", a[row*16 + col]);
                }
                printf("\n");
        }
        /*Test reverse*/
        int x[] = {1, 1, 2, 3, 5, 8, 13, 21};
        for (int i=0; i<8; i+=1) printf("%d, ", x[i]); printf("\n");
        reverse(x, 6);
        for (int i=0; i<8; i+=1) printf("%d, ", x[i]); printf("\n");

        /*Test push0*/
        int y[] = {1, 7, 3, 2, 0, 5, 0, 8, 0, 7, 5, 6, 8, 8, 7, 7, 2, 9};
        for (int i=0; i<18; i+=1) printf("%d ", y[i]); printf("\n");
        push0(y, 15);
        for (int i=0; i<18; i+=1) printf("%d ", y[i]); printf("\n");

        /*Test nondup*/
        int z[] = {28, 12, 8, 0, 0, 28, 8};
        printf("%d\n", nondup(z, 7));
        printf("%d\n", nondup(z + 2, 5));

        return 0;
}

