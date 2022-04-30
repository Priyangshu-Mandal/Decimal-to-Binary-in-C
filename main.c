#include <stdio.h>


int zeros = 0;


void zero(int bool){
    static int start = 0;
    if(bool == 1){
        start = 1;
    }
    if (start != 1){
        zeros += 1;
    }
}


int revNum(int n){
    int rev = 0;
    while(n!=0){
        rev = rev*10+n%10;
        n /= 10;
    }
    return rev;
}


int main(int argc, char const *argv[])
{
    long dec, bin = 0;
    int rem;

    printf("Enter the decimal number: ");
    scanf("%ld", &dec);

    do{
        rem = dec%2;
        dec -= rem;
        dec /= 2;
        bin *= 10;
        bin += rem;

        zero(rem);
    } while (dec != 0);

    bin = revNum(bin);

    while(zeros != 0){
        bin *= 10;
        zeros -= 1;
    }
    
    printf("Binary = %ld", bin);
    
    return 0;
}