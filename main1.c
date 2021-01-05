#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int countDigit(int n);
int prime(int n);
int main ()
{
int N =0 ;

printf("enter the order of square matrix (2 < N < 6) ");
scanf("%d",&N);
int arr[N][N];
int i =0,j =0;
for (i=0; i<N ; i++){
    for(j=0; j<N ; j++)
    {
        printf("enter value for arr[%d][%d]:",i,j);
        scanf("%d", &arr[i][j]);
    }
}
printf("saqure matrix is:\n");
for(i=0; i<N; i++){
    for(j=0; j<N; j++){
        printf(" %d ",arr[i][j]);
        if(j==N-1){
            printf("\n");
            }
        }
    }
    int count_even =0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
           if((arr[i][j]) % 2 == 0)
            count_even++;

        }
    }
     printf("Total count of even numbers %d\n ", count_even);


for(i=j=0;i<N&j<N; i++&j++)
    {


    if(sqrt(arr[i][j]) - floor(sqrt(arr[i][j])) == 0){

        printf("Perfect squares in the Matrix diagonals %d\n ",arr[i][j]);
        }
}

j = N-1;
    for(i=0; i<N & j>=0; i++&j--)
        {
    if(sqrt(arr[i][j]) - floor(sqrt(arr[i][j])) == 0){

        printf("Perfect squares in the Matrix opposite diagonals %d\n ",arr[i][j]);
        }
    }
int min = arr[0][0];
int max = arr[0][0];


for(i=0; i<N ;i++){
    for(j=0;j<N;j++){

 int c = countDigit(arr[i][j]);
 int L = 1;
 int p = 0;
 for(int k = 0; k < c; k++){
   int number = arr[i][j]/L;
    //prime(arr[i][j]%10)
    if ( prime(number%10)==1 ){
        p = 1;
    }
    L = L*10;

 }
 for(i=0;i<N;i++){
     for(j=0;j<N;j++){
 if (p==0){
    if (arr[i][j]< min ){
        min = arr[i][j];
    }
    if (arr[i][j]> max ){
        max = arr[i][j];
    }
 }}}

    }
}
printf("The largest number whose individual digits are prime  %d \n",max);
printf("The smallest number whose individual digits are prime %d\n", min);

return 0;


}
int prime(int n )
{ int flag = 0;
for(int a=2;a<=n;a++)
{
if(n%a==0)
{
//printf("Number is not prime");
flag=1;
break;
}
}
return flag;
 }
 int countDigit(int n)
{
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}


