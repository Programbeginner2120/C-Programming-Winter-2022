#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

/* Question 1:
1.1). The following code prints out 3, and it does not print out 5 due to
the fact that the expression A && B on line 10 short circuits upon
evaluating bool b = 0 (aka false) and does not set x to equal 5.
*/
void question1a(){
    int x = 3;
    bool b = 0 && (x = 5);
    printf("%d\n", x);
}

// Question 1.2
void question1b(){
    int A = 0;
    int B = 0;
    for (int i = 0; i < 4; i++){
        printf("A: %d\nB: %d\n", A, B);
        printf("%d\n", !(A && B) == !A || !B);
        if (A == 0 && B == 1)
            A = 1;
        else{
            B = A;
            A = !A;
        }
    }
}

// Helper for later questions
char * fromDecimalToBinary(int num){
    char res [1000] = {0};
    char ch = {0};
    for (int i = 7; i >= 0; i--){
        int division = num / pow(2,i);
        if (division != 0){
            ch = '1';
            num = num % (int)pow(2,i);
        }
        else
            ch = '0';
        strncat(res, &ch, 1);
    }
    char * rv = res; // Since I used a pre allocated array, making char pointer equal to the pre allocated array
    return rv;
}


//Helper for later questions
int fromBinaryToDecimal(char string []){
    int res = 0;
    int curr;
    for(int i = 0; i < 8; i++){
        if (string[i] == '0')
            curr = 0;
        else
            curr = 1;
        res += curr * pow(2,8 - (i + 1));
    }
    return res;
}


// Question for 2.1
void question2aShift(){
    char res [1000] = {0};
    int num = 0b00110111;
    num = num >> 2;
    strncat(res, fromDecimalToBinary(num), 1000);
    printf("%c\n", res[strlen(res) - 1]);
}


//Question for 2.1 
void question2aMask(){
    int num = 0b00110111;
    int mask = 0b00000100;
    int decimalRes = num & mask;
    char res [1000] = {0};
    strncat(res, fromDecimalToBinary(num), 1000);
    printf("%c\n", res[strlen(res) - 1]);
}


// Question for 2.2
void question2b(){
    char eightBit [1000] = {0};
    printf("Enter an 8 bit number in binary:\n");
    scanf("%s", eightBit);
    for (int i = 0; i < strlen(eightBit); i++){
        if (eightBit[i] == '0')
            eightBit[i] = '1';
        else
            eightBit[i] = '0';
    }
    int decimalRes = fromBinaryToDecimal(eightBit) + 1;
    char binaryRes [1000] = {0};
    strncat(binaryRes, fromDecimalToBinary(decimalRes), 1000);
    printf("%s\n", binaryRes);
}


// Question for 3.1
void question3a(bool usePreAdd, int i){
    if (usePreAdd)
        printf("%d\n", ++i);
    else
        printf("%d\n", i++);
}


//Question for 3.2
void question3b(int y){
    int a = y % 19;
    int c = y % 100;
    int b = y / 100;
    int e = b % 4;
    int d = b / 4;
    int g = (8*b + 13) / 25;
    int h = (19*a + b - d - g + 15) % 30;
    int k = c % 4;
    int j = c / 4;
    int m = (a + 11*h) / 319;
    int r = (2 * e + 2 * j - k - h + m + 32) % 7;
    int n = (h - m + r + 90) / 25;
    int p = (h - m + r + n + 19) % 32;
    printf("Easter Sunday falls on month %d and day %d\n", n, p);
}


// Main function for program
int main(){
    question1a();
    question1b();
    question2aShift();
    question2aMask();
    question2b();
    question3a(true, 1);
    question3b(2001);
}

