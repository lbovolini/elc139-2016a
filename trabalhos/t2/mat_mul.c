#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


/*
 * Tempo (wallclock) em microssegundos
 */ 
long wtime()
{
   struct timeval t;
   gettimeofday(&t, NULL);
   return t.tv_sec*1000000 + t.tv_usec;
}


// aloca e retorna matriz
long **alocar_matriz(int m, int n)
{
	int i = 0;
	long **matriz = NULL;

	if(!(matriz = (long**)malloc(m * sizeof(long*))))
	{
    	printf("Erro de alocacao de memoria\n");
    	exit(EXIT_FAILURE);
    }

	for (i = 0; i < m; i++)
	{
		if(!(matriz[i] = (long*)malloc(n * sizeof(long))))
		{
			printf("Erro de alocacao de memoria\n");
    		exit(EXIT_FAILURE);
		}
	}

	return matriz;
}


void desalocar_matriz(long **matriz, int m, int n)
{
	int i = 0;

	if(!matriz) return;

	for (i = 0; i < m; i++)
	{
		free(matriz[i]);
	}

	free(matriz);
}


/* preenche a matriz com a soma dos indices do elemento corrente  */
void preencher_matriz(long **matriz, int m, int n)
{
	int i = 0, j = 0;

	if(!matriz)
	{
		printf("Matriz invalida\n");
		exit(1);
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			matriz[i][j] = i + j;
		}
	}
}


// multiplica matrizes e retorna matriz resultado
long **multiplicar_matrizes(long **matriz1, long **matriz2, int m, int n)
{
	int i = 0, j = 0, k = 0;
	long soma = 0;
	long **resultado = NULL;

	if(!matriz1 || !matriz2)
	{
		printf("Impossivel multiplicar matrizes.\n");
		exit(0);
	}


	// aloca matriz resultado
	resultado = alocar_matriz(m,n);


	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				soma = soma + (matriz1[i][k]) * (matriz2[k][j]);
			}
			resultado[i][j] = soma;
			soma = 0;
		}
	}

	return resultado;
}


// main
int main(int argc, char *argv[])
{
	int m, n;

	long start_time, end_time;

	long **mat1 = NULL, 
		 **mat2 = NULL,
		 **res = NULL;

	if ((argc != 2)) {
		printf("Uso: %s <dimensao das matrizes>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// linhas
	n = atoi(argv[1]);

	//colunas
	m = atoi(argv[1]);

	if(n > 1000 || n < 1)
	{
		printf("Informe um numero positivo <= 1000.\n");
		exit(EXIT_FAILURE);
	}

	// matrizes
	mat1 = alocar_matriz(m, n);
	mat2 = alocar_matriz(m, n);

	start_time = wtime();
	res = multiplicar_matrizes(mat1, mat2, m, n);
	end_time = wtime();

	printf("Tempo de calculo = %ld usec\n", (long) (end_time - start_time));

	desalocar_matriz(mat1, m, n);
	desalocar_matriz(mat2, m, n);

	mat1 = NULL;
	mat2 = NULL;

	return 0;
}