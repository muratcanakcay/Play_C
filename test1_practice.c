# include <stdio.h>
void main ()
{
int n = 10 ,p = 5, q = 10, r;
r = n == (p = q);
printf ("A : n =%d p =%d q =%d r =%d \n", n, p, q, r);
n = p = q = r = 5;
n += p += q;
printf ("B : n =%d p =%d q =%d \n", n, p, q);
q = n < p?n++:p++;
printf ("C : n =%d p =%d q =%d \n", n, p, q);
q = n > p?++n:++p ;
printf ("D : n =%d p =%d q =%d \n", n, p, q);
n =5; p =2;
q = n++ > p || p++ != 3;
printf ("E : n =%d p =%d q =%d \n", n, p, q);
for (n = -2; n < ++q; n++, q--, p = q%2)
    {
    if (n == p)
    continue;
    printf ("E-%d : n=%d p=%d q=%d \n", n+3, n, p, q);
    }

char *morse[26] = {".-", "-..." ,"-.-.", "-..", "." ,"..-.", "-..", "....", "..", ".---", "-.-", ".-..", "--", "-." , "---", ".--.", ".-.", "...", "-", "..-", ".--", "...-", "-..-", "-.-", "--.."};
printf("%s\n", morse[12]);
}
