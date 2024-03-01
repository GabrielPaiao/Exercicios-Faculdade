#include <stdio.h>

int main()
{
	//VAR
	int ni, soma=0;

	//INICIO
	scanf("%d", &ni);
	int  num[ni];

	for (int cont=0; cont < ni; cont++)
	{
		scanf("%d", &num[cont]);
		if (num[cont] == 0)
		{
			for (int c=0; c < cont; c++)
			{
				if (num[c] == 0)
					num[c-1] = 0;
			}
		}
	}

	for (int cont=0; cont < ni; cont++)
		soma += num[cont];

	printf("%d\n", soma);

	//FIM
	return 0;
}