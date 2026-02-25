#include <stdio.h>

int main()
{
int n = 0;
int Zahl = 0;
int Sum = 0;
  
  
  printf("Wie viele Zahlen:");
  if (scanf("%d", &n) != 1) {
      while (getchar() != '\n'); // clear buffer
      printf("Ungültige Eingabe. Bitte eine Zahl eingeben.\n");
      return 1;
  }
  for (int i = 0; i < n; i++)
  {
    printf("Gib die %d Zahl an:",i + 1);
    if (scanf("%d", &Zahl) != 1) {
        while (getchar() != '\n'); // clear buffer
        printf("Ungültige Eingabe. Bitte eine Zahl eingeben.\n");
        i--; // repeat this iteration
        continue;
    }
    Sum = Sum + Zahl;
    }
printf ("Die Summe ist: %d \n",Sum);  
}
