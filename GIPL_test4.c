#include <stdio.h>
#include <stdbool.h>

bool match(char *first, char * second)
{
    if (*first == '\0' && *second == '\0')
        return true;

    if (*first == '*' && *(first+1) != '\0' && *second == '\0')
        return false;

    if (*first == *second)
        return match(first+1, second+1);

    if(*first=='~')
        return match(first+1,second)|| match(first,second+1);

    if (*first == '*')
        return match(first+1, second) || match(first, second+1);
    return false;
}

void check(char *first, char *second)
{  match(first, second)? puts("Yes"): puts("No"); }

int main()
{
    check("*", "abc");//YES
    check("*~", "abc");  //NO
    check("*~", "abcabc");//YES
    check("a*a~", "abcabc"); //YES

    return 0;
}