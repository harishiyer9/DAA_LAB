#include <stdio.h>

char*s="#include <stdio.h>%cchar*s=%c%s%c;%cint main(void){printf(s,5,5,s,5,10,10);}%c";

int main(void)
{
    printf(s,5,5,s,5,10,10);
}
