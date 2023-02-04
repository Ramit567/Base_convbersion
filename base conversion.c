#include<stdio.h>
#include<stdlib.h>

int menu(int n)
{
    printf("              ********************---------------------------**********************\n");
    printf("                                        Available Tasks\n");
    printf("              ********************---------------------------**********************\n");
    printf("              *********************************************************************\n");

    printf("                                     1.  Binary to Octal\n");
    printf("                                     2.  Binary to Decimal\n");
    printf("                                     3.  Binary to Hexadecimal\n");
    printf("                                     4.  Octal to Binary\n");
    printf("                                     5.  Octal to Decimal\n");
    printf("                                     6.  Octal to Hexadecimal\n");
    printf("                                     7.  Decimal to Binary\n");
    printf("                                     8.  Decimal to Octal\n");
    printf("                                     9.  Decimal to Hexadecimal\n");
    printf("                                    10.  Hexadecimal to Binary\n");
    printf("                                    11.  Hexadecimal to Octal\n");
    printf("                                    12.  Hexadecimal to Decimal\n");
    printf("                                     0.  Exit\n");
    printf("              *********************************************************************\n\n");
    printf("              Choice :");

    int o;
    scanf("%d",&o);

    if(o==1)
        b_o();

    else if(o==2)
        b_d();

    else if(o==3)
        b_h();

    else if(o==4)
        o_b();

    else if(o==5)
        o_d();

    else if(o==6)
        o_h();

    else if(o==7)
        d_b();

    else if(o==8)
        d_o();

    else if(o==9)
        d_h();
    else if(o==10)
        h_b();

    else if(o==11)
        h_o();

    else if(o==12)
        h_d();
    else if(o==0)
        return 0;

    else if(o<1 || o>12)
        printf("                   Invalid Input !\n");

    printf("              *********************************************************************\n");
    printf("              1. Main Menu\n");
    printf("              0. Exit\n");
    printf("              *********************************************************************\n");
    printf("              ");

    scanf("%d",&n);
    system("cls");
    return n;
}

void b_o()
{

    long int bin, oct=0,r,i=1;
    printf("              Enter a binary number : ");
    scanf("%ld",&bin);
    int b=bin;
    while(bin!=0)
    {
        r=bin%10;
        oct=oct+r*i;
        i=i*2;
        bin=bin/10;
    }
    printf("              Binary to Octal:%ld(B)=%lo(O)\n",b,oct);
}


void b_d()
{
    long int bin, dec=0,r,i=1;
    printf("              Enter a binary number : ");
    scanf("%ld",&bin);
    int b=bin;
    while(bin!=0)
    {
        r=bin%10;
        dec=dec+r*i;
        i=i*2;
        bin=bin/10;
    }
    printf("              Binary to decimal:%ld(B)=%ld(d)\n\n\n",b,dec);
    return 0;

}
void b_h()
{
    long int bin, hex=0,r,i=1;
    printf("Enter a binary number : ");
    scanf("%ld",&bin);
    int b=bin;
    while(bin!=0)
    {
        r=bin%10;
        hex=hex+r*i;
        i=i*2;
        bin=bin/10;
    }
    printf("               Binary to Hexadecimal:%ld(B)=%lhx(hx)\n\n\n",b,hex);
    return 0;
}

void o_b()
{
    char octalnum[50];
    long i = 0;

    printf("                Enter any octal number: ");
    scanf("%s", octalnum);
    printf("                Equivalent binary value: ");
    while (octalnum[i])
    {
        switch (octalnum[i])
        {
        case '0':
            printf("000");
            break;
        case '1':
            printf("001");
            break;
        case '2':
            printf("010");
            break;
        case '3':
            printf("011");
            break;
        case '4':
            printf("100");
            break;
        case '5':
            printf("101");
            break;
        case '6':
            printf("110");
            break;
        case '7':
            printf("111");
            break;
        default:
            printf("                 invalid octal digit %c\n\n\n ", octalnum[i]);
            return 0;
        }
        i++;
    }
    return 0;
}
void o_d()
{
    long int octal, decimal = 0;
    int i = 0;

    printf("Enter any octal number: ");
    scanf("%ld", &octal);
    while (octal != 0)
    {
        decimal =  decimal +(octal % 10)* pow(8, i++);
        octal = octal / 10;
    }
    printf("              Equivalent decimal value: %ld\n\n\n",decimal);
    return 0;
}
void o_h()
{
    int OCTALVALUES[] = {0, 1, 10, 11, 100, 101, 110, 111};

    long long octal, tempOctal, binary, place;
    char hex[65] = "";
    int rem;

    place = 1;
    binary = 0;

    printf("                Enter any octal number: ");
    scanf("                 %lld", &octal);
    tempOctal = octal;


    while(tempOctal > 0)
    {
        rem = tempOctal % 10;
        binary = (OCTALVALUES[rem] * place) + binary;
        tempOctal /= 10;

        place *= 1000;
    }


    while(binary > 0)
    {
        rem = binary % 10000;
        switch(rem)
        {
        case 0:
            strcat(hex, "0");
            break;
        case 1:
            strcat(hex, "1");
            break;
        case 10:
            strcat(hex, "2");
            break;
        case 11:
            strcat(hex, "3");
            break;
        case 100:
            strcat(hex, "4");
            break;
        case 101:
            strcat(hex, "5");
            break;
        case 110:
            strcat(hex, "6");
            break;
        case 111:
            strcat(hex, "7");
            break;
        case 1000:
            strcat(hex, "8");
            break;
        case 1001:
            strcat(hex, "9");
            break;
        case 1010:
            strcat(hex, "A");
            break;
        case 1011:
            strcat(hex, "B");
            break;
        case 1100:
            strcat(hex, "C");
            break;
        case 1101:
            strcat(hex, "D");
            break;
        case 1110:
            strcat(hex, "E");
            break;
        case 1111:
            strcat(hex, "F");
            break;
        }

        binary /= 10000;
    }

    strrev(hex);

    printf("                Octal number: %lld\n", octal);
    printf("                Hexadecimal number: %s", hex);
    printf("n\n\n");


}
void d_b()
{
    int a[10],n,i;

    printf("Enter a Decimal number : ");
    scanf("%d",&n);
    for(i=0; n>0; i++)
    {
        a[i]=n%2;
        n=n/2;
    }
    printf("\nBinary of Given Number is =  ");
    for(i=i-1; i>=0; i--)
    {
        printf("%d",a[i]);
    }

}
void d_o()
{
    long decimalnum, remainder, quotient;
    int octalNumber[100], i = 1, j;

    printf("Enter the decimal number: ");
    scanf("%ld", &decimalnum);
    quotient = decimalnum;
    while (quotient != 0)
    {
        octalNumber[i++] = quotient % 8;
        quotient = quotient / 8;
    }
    printf("Equivalent octal value ");
    for (j = i - 1; j > 0; j--)
        printf("%d", octalNumber[j]);
   printf("n\n\n");
}
void d_h()
{


    int a;
    printf("              Decimal Number is:");
    scanf("%d",&a);
    printf("              hexadecimal Number is %x\n\n\n",a);




}
void h_b()
{

    char hexNum[100];
    long int count=0;
    printf("               Enter a hexadecimal number To Convet it into Binary : ");
    scanf("%s",hexNum);
    printf("                        Binary Number is :        ");
    while(hexNum[count])
    {
        switch(hexNum[count])
        {
        case '0' :
            printf("0000");
            break;
        case '1' :
            printf("0001");
            break;
        case '2' :
            printf("0010");
            break;
        case '3' :
            printf("0011");
            break;
        case '4' :
            printf("0100");
            break;
        case '5' :
            printf("0101");
            break;
        case '6' :
            printf("0110");
            break;
        case '7' :
            printf("0111");
            break;
        case '8' :
            printf("1000");
            break;
        case '9' :
            printf("1001");
            break;
        case 'A' :
            printf("1010");
            break;
        case 'B' :
            printf("1011");
            break;
        case 'C' :
            printf("1100");
            break;
        case 'D' :
            printf("1101");
            break;
        case 'E' :
            printf("1110");
            break;
        case 'F' :
            printf("1111");
            break;
        case 'a' :
            printf("1010");
            break;
        case 'b' :
            printf("1011");
            break;
        case 'c' :
            printf("1100");
            break;
        case 'd' :
            printf("1101");
            break;
        case 'e' :
            printf("1110");
            break;
        case 'f' :
            printf("1111");
            break;
        default :
            printf("                      Invalid Entry, Please Try Again  %c\n\n\n\n\n",hexNum[count]);
        }
        count++;
    }

}


void h_o()
{
    int a;
    printf("                Hexadecimal Number is:");
    scanf("%x",&a);
    printf("                octal Number is %o\n\n\n",a);
}
void h_d()
{

    int a;
    printf("                Hexadecimal Number is:");
    scanf("%x",&a);
    printf("                Decimal Number is %d\n\n\n",a);





}

int main()
{
    int o=1, n;

    while(n=1)
    {
        n = menu(n);
        if(n==0)
            return 0;
    }
    return 0;
}
