#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

int main()
{
    // int input;
    // scanf("%d", &input);
    setlocale(LC_ALL, "");
    wchar_t c[3] = "¤";
    printf("%ls", c);
    return 0;
}