/*Напишете програма PrintPatterns, която отпечата следните текстови графики наекрана. Графиките една под друга:
 # # # # # # # # # # #
   # # # # # # # # #  
     # # # # # # # 
       # # # # #  
         # # # 
           #

           #
         # # #
       # # # # #
     # # # # # # #
   # # # # # # # # #
 # # # # # # # # # # #

            #
         # # #
       # # # # #
     # # # # # # #
   # # # # # # # # #
 # # # # # # # # # # #
   # # # # # # # # #
     # # # # # # #
       # # # # #
         # # #
           #
*/

# include <stdio.h>

int main()
{
    int rows = 0;
    printf("Number of rows:");
    scanf("%d", &rows);

    for (int i = rows; i >= 1; i--)
    {
        for (int in = 1; in <= rows - i; in++) { printf("  "); };
        for (int st = 1; st <= 2 * i - 1; st += 1) { printf("* "); };
        printf("\n");
    }

    printf("\n");

    for (int i = 1; i <= rows; i++)
    {
        for (int in = 1; in <= rows - i; in++) { printf("  "); };
        for (int st = 1; st <= 2 * i - 1; st += 1) { printf("* "); };
        printf("\n");
    }

    printf("\n");

    for (int i = 1; i <= rows; i++)
    {
        for (int in = 1; in <= rows - i; in++) { printf("  "); };
        for (int st = 1; st <= 2 * i - 1; st += 1) { printf("* "); };
        printf("\n");
    }
    for (int i = rows - 1; i >= 1; i--)
    {
        for (int in = 1; in <= rows - i; in++) { printf("  "); };
        for (int st = 1; st <= 2 * i - 1; st += 1) { printf("* "); };
        printf("\n");
    }

    return 0;
}
