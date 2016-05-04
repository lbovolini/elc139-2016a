[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2016a) > T4

# T4: Floyd-Warshall Paralelo em Multicore

Aluno: Lucas Bovolini  
Curso: Sistemas de Informação  
Disciplina: Programação Paralela - elc139-2016a  
Primeiro semestre de 2016  
Professora: [Andrea Schwertner Charão](http://www.inf.ufsm.br/~andrea)  
Carga horária: 60h

## Floyd-Warshall Paralelo em Multicore 
[floyd_parallel](floyd_parallel)


Particionamento: A partir do segundo laço a execução do código é dividida em n partes.

Comunicaçao: As threads compartilham as variáveis "n" e "s".

Aglomeracao: Cada uma das Num Threads irão executar o for mais interno de 0 até n.

Mapeamento: A partir do segundo laço a execução do código é dividida em n partes e cada uma das Num Threads executam 1 parte, paralelamente, até a execução das n partes. 

