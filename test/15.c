#include <stdio.h>
#include <stdio.h>
int a[3];
int cal[200];
int sum;
void next()
{
    a[0] = a[1];
    a[1] = a[2];
    a[2] = (a[0] + a[1])%10000;
}
void squrae()
{
    int temp = (a[0] * a[1] + a[1] * a[2])%10000;
    a[0] = (a[0] * a[0] + a[1] * a[1])%10000;
    a[2] = (a[1] * a[1] + a[2] * a[2])%10000;
    a[1] = temp;
}
int main()
{
    int nmax = 10000000;
    int i = 0;
    while(i < nmax){
        a[0] = 0;
        a[1] = 1;
        a[2] = 1;
        int j = 0;
        while(j<200){
            cal[j] = 0;
            j = j + 1;
        }
        int n = i;
        int x = 0;
        while(n > 1)
        {
            if(n % 2)
            {
                cal[x] = 0;
                n = n - 1;
            }
            else
            {
                cal[x] = 1;
                n = n / 2;
            }
            x = x + 1;
        }
        j = x - 1;
        while(j>=0){
            if(!cal[j]) next();
            else squrae();
            j = j - 1;
        }
        sum = sum + a[1];
        sum = sum % 10000;
        i = i + 1;
    }
    return 0;
}