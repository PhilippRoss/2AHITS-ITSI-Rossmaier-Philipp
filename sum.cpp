#include <stdio.h>

int main()
{
int n = 0;
int Zahl = 0;
int Sum = 0;
  
  
  printf("Wie viele Zahlen:");
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
    printf("Gib die %d Zahl an:",i + 1);
    scanf("%d",&Zahl);
    Sum = Sum + Zahl;
    }
printf ("Die Summe ist: %d \n",Sum);  
}
