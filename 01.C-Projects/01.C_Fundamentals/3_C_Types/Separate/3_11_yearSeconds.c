/* 
Напишете програма, която изчислява броя на секундите в една година. 
*/

# include <stdio.h> 

int yearDaysCount(int year)
{
   if (year % 4 == 0) 
   { 
       return 366;
   }
   else 
   { 
       return 365; 
   }
}

int main()
{
    int iYear = -1;
    int iSeconds = -1;

    printf("\nEnter year:");
    scanf("%d", &iYear);

    iSeconds = yearDaysCount(iYear) * 24 * 60 * 60;
 
    printf("\nYear %d has %d seconds.", iYear, iSeconds);

    return 0;
}