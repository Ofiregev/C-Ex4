#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void(*ptfun)(int,int);

void add(int a, int b){
    printf("Addition is:%d\n",a+b);
}
void substruct(int a, int b)
{
    printf("Substructing is:%d\n",a-b);

}
void milt(int a , int b)
{
    printf("multi is:%d\n",a*b);

}
int main(int argc, char const *argv[])
{
    // ptfun a;
    // a = add;
    // ptfun b;
    // b = substruct;
    // ptfun c;
    // c = milt;
    // printf("please enter your chois and 2 numbers\n");
    // char ch;
    // int num1, num2;
    // scanf("%c\n %d\n %d",&ch,&num1,&num2);
    // // scanf("num 1 %d, num 2 %d", num1,num2);
    // if(ch=='a')
    // {
    //     a(num1,num2);
    // }
    // else if(ch == 'b')
    // {
    //     b(num1, num2);
    // }
    // else if(ch == 'c')
    // {
    //     c(num1, num2);
    // }
 
    return 0;
}


