#include <stdio.h>
int main()
{
   char texto_original[1000], texto_revertido[1000];
   int inicio, final, qte = 0;
   printf("Digite um texto:");
   gets(texto_original);
   while (texto_original[qte] != '\0')
      qte++;    // Calculando o tamnaho da string

   final = qte - 1;
   for (inicio = 0; inicio < qte; inicio++) {
      texto_revertido[inicio] = texto_original[final];
      final--;
   }

   texto_revertido[inicio] = '\0';

   printf("%s\n", texto_revertido);

   return 0;
}