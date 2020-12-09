#include <string.h>
#include <stdio.h>

int main()
{
    char movnome[1] = "#";
    
//    scanf (" %s", movnome);

    printf("%d\n", strcmp(movnome,"#"));


        movnome[1] = "0";
    
//    scanf (" %s", movnome);

    printf("%d\n", strcmp(movnome,"0"));


        movnome[1] = "1";
    
//    scanf (" %s", movnome);

    printf("%d\n", strcmp(movnome,"1"));
                    
return 0;
}