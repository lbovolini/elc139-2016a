[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2016a) > T3

# T3: Programação Paralela Multithread

	
- Aluno: Lucas Bovolini
- Disciplina: Programação Paralela 2016/01
- Professora: Andrea Schwertner Charão


## Questões Pthreads

1. Cosiderando 4 threads, worsize igual a 100 e número de repetições igual a 100;

Particionamento:
	O particionamento consiste na divisõo dos vetores do pelo número de threads
	Será alocado um vetor a com 400 posições que será preenchido pela função fill() com o valor 0.01 e um vetor b também com 400 posições que será preenchido com o valor 1.0.

Mapeamento:
	A função dotprod_threads() cria as 4 threads e distribui a execução do produto escalar em 4 threads onde a thread 0 irá calcular o produto escalar das primeiras 100 posições dos vetores.

Aglomeração e Comunicação:

   //pthread_mutex_lock (&mutexsum);
   dotdata.c += mysum;
   //pthread_mutex_unlock (&mutexsum);

Cada thread realiza a aglomeração dos resultados do produto escalar parciais, obtidos por cada thread, por meio da soma destes na variável c.


2. 1,836 com 2 theads e 2,106 com 4 threads.

3. Há uma pequena variação no speedup, em geral manten-se o mesmo speedup.

4. 
	1 1000000 2000 => 7262762us - 72,6s
	2 500000  2000 => 3900462us - 39s - 1,86
	4 250000  2000 => 3409511us - 34s - 2,13

	1 1000000 500 => 1818139us - 1,8s
	2 500000  500 => 1021660us - 1s    - 1,8
	4 250000  500 => 864474us  - 0.86s - 2,09

	1 1000000 5000 => 17870057us - 17,87s
	2 500000  5000 =>  9807174us - 9,8s - 1,82
	4 250000  5000 =>  8554546us - 8,5s -  2,1

5. pthreads_dotprod.c usa um mutex que garante a consistência dos dados, atomicidade e evita que duas ou mais threads executem o código "dotdata.c += mysum;" ao mesmo tempo. Como os resultados não dependem da ordem das operações, o resultado final será o mesmo com ou sem mutex. Inconsistências podem ser geradas sem mutex.



