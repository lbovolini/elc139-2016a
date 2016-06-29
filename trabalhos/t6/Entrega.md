[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2016a) > T6

# T6: Ray-tracer paralelo com MPI

Aluno: Lucas Bovolini  
Curso: Sistemas de Informação  
Disciplina: Programação Paralela - elc139-2016a  
Primeiro semestre de 2016  
Professora: [Andrea Schwertner Charão](http://www.inf.ufsm.br/~andrea)  
Carga horária: 60h

## Ray-tracer paralelo com MPI
[ray_parallel](ray_parallel)

![tests](https://cloud.githubusercontent.com/assets/7422061/15033579/80ccdc6c-1242-11e6-80b6-25a948580339.png)

###Versão 1:
```c
#pragma omp critical
total = total + prime;
```

###Versão 2:
```c
reduction ( + : total )
```

###Versão 3:
```c
#pragma omp atomic 
total = total + prime;
```

##Tempos

| Threads | V1        | V2        | V3        |
| ------- | ----------| --------- | --------- |
| 1       | 50,058593 | 51,692310 | 50,932766 |
| 2       | 27,233782 | 26,360526 | 25,605622 |
| 4       | 20,696240 | 20,721801 | 20,267425 |

##Speedup

| Threads | V1        | V2        | V3        |
| ------- | ----------| --------- | --------- |
| 2       | 1,8381065 | 1,8989982 | 1,9549844 |
| 4       | 2,4187288 | 2,4157452 | 2,4699039 |

##Eficiência

| Threads | V1        | V2        | V3        |
| ------- | ----------| --------- | --------- |
| 2       | 91,90%    | 94,94%    | 97,74%    |
| 4       | 60,46%    | 60,39%    | 61,74%    |


##Referências