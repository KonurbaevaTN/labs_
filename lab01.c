# include <stdio.h>
# include <math.h>
int main()
{
   int a, b ;
   int s1, s2;
   float sa, sb;
   printf (" Enter a -> ") ;
   scanf ("%d" , &a ) ;
   printf (" Enter b -> ") ;
   scanf ("%d" , &b ) ;
   printf (" Enter c -> ") ;
   if (! a && ! b)
        return 0;

   while(a)
   {
     s1+=a%10;
     a /= 10;
   }

   while(b)
   {
     s2+=b%10;
     b /= 10;
   }
   if (s1>s2)
   {
      sa=s2/b;
      printf("%u", sa);
   }
   else
   {
      sb=s1/b;
      printf("%u", sb);
   }
}
