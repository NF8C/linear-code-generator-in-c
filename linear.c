#include <stdio.h>


int linearGenerator(int fc , int tn , int bn) {
    /*
    fc Enter the facility Code:
    tn Enter the transmitter number ex. 17316
    bn Enter the button number default is 2 for a single button remote
    (((tn*8)+8388608)+(fc*524288)+bn).to_bytes(8, "big").hex(" ").upper()
    Key: 00 00 00 00 00 9A 1D 22
    10100002 == 9A1D22

    int fc=3;
    int tn=17316;
    int bn=2;
        */
    int dec=((tn*8)+8388608)+(fc*524288)+bn;
    long quotient=((tn*8)+8388608)+(fc*524288)+bn;
    
    long decimalnum, remainder;

    int i, j = 0;

    char hexadecimalnum[16];


    while (quotient != 0)

    {

        remainder = quotient % 16;

        if (remainder < 10)

            hexadecimalnum[j++] = 48 + remainder;

        else

            hexadecimalnum[j++] = 55 + remainder;

        quotient = quotient / 16;

    }
    
    char a[10];
    
    for (i = 0; i <= j; i+=1)
    a[i] = hexadecimalnum[j-i-1];
    
    printf("The code is: %s", a);
    
    return 0;
    
    
}
