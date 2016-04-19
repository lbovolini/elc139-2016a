[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2016a) > T3

# T3: Programação Paralela Multithread 
Aluno: Lucas Bovolini 
Curso: Sistemas de Informação 
Disciplina: Programação Paralela - elc139-2016a 
Primeiro semestre de 2016 
Professora: [Andrea Schwertner Charão](http://www.inf.ufsm.br/~andrea) 
Carga horária: 60h


## Questões Pthreads

1. Cosiderando 4 threads, worsize igual a 100 e número de repetições igual a 100.
	
	Particionamento: O particionamento consiste na divisõo dos vetores do pelo número de threads. Será alocado um vetor a com 400 posições que será preenchido pela função fill() com o valor 0.01 e um vetor b também com 400 posições que será preenchido com o valor 1.0.

	Mapeamento: A função dotprod_threads() cria as 4 threads e distribui a execução do produto escalar em 4 threads onde a thread 0 irá calcular o produto escalar das primeiras 100 posições dos vetores.

	Aglomeração: A aglomeração consiste no agrupamento de várias multiplicações e somas realizadas por cada thread.

	Comunicação: Cada thread realiza a soma dos resultados parciais do produto escalar obtidos por cada thread na variável c.

	```
	//pthread_mutex_lock (&mutexsum);
	dotdata.c += mysum;
	//pthread_mutex_unlock (&mutexsum);
	```

2. 1,836 com 2 theads e 2,106 com 4 threads.

3. Há uma pequena variação no speedup, em geral mantém-se o mesmo speedup.

4. Todos os testes foram executados quatro vezes em um processador com 2 núcleos e 4 threads, os resultados correspondem à média

	| Threads | Worksize | Repetições | Tempo(us) | Tempo(s) | Speedup |
	| ------- | -------- | ---------- | --------- | -------- | ------- |
	| 1 | 1000000 | 2000 | 7262762us | 72,6s | 1    |
	| 2 | 500000  | 2000 | 3900462us | 39s   | 1,86 |
	| 4 | 250000  | 2000 | 3409511us | 34s   | 2,13 |

	| Threads | Worksize | Repetições | Tempo(us) | Tempo(s) | Speedup |	
	| ------- | -------- | ---------- | --------- | -------- | ------- |
	| 1 | 1000000 | 500  | 1818139us | 1,8s  | 1    |
	| 2 | 500000  | 500  | 1021660us | 1s    | 1,8  |
	| 4 | 250000  | 500  | 864474us  | 0.86s | 2,09 |

	| Threads | Worksize | Repetições | Tempo(us) | Tempo(s) | Speedup |	
	| ------- | -------- | ---------- | --------- | -------- | ------- |
	| 1 | 1000000 | 5000 | 1787005us | 17,8s | 1    |
	| 2 | 500000  | 5000 | 9807174us | 9,8s  | 1,82 |
	| 4 | 250000  | 5000 | 8554546us | 8,5s  | 2,1  |


5. pthreads_dotprod.c usa um mutex que garante a consistência dos dados, atomicidade e evita que duas ou mais threads executem o código "dotdata.c += mysum;" ao mesmo tempo. Como os resultados não dependem da ordem das operações, o resultado final será o mesmo com ou sem mutex. Inconsistências podem ser geradas sem mutex.