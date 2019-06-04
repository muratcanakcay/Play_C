#include <stdio.h>

void main()
{
    void add_pointer(int* p_x)
    {
        *p_x = *p_x + 1;
    }
    void fake_add_pointer(int p_x)
    {
        p_x = p_x + 1;
    }
    int a = 4;
    add_pointer(&a);
    printf("%d\n", a);
    fake_add_pointer(a);
    printf("%d\n", a);
    add_pointer(&a);
    printf("%d\n", a);
}
