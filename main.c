#include "clipboard.h"
#include "stdio.h"
int main()
{
    char* result;
    result = clip();
    printf("%s\n", result);
}
