[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2016a) > T6

# T6: Ray-tracer paralelo com MPI

Aluno: Lucas Bovolini  
Curso: Sistemas de Informação  
Disciplina: Programação Paralela - elc139-2016a  
Primeiro semestre de 2016  
Professora: [Andrea Schwertner Charão](http://www.inf.ufsm.br/~andrea)  
Carga horária: 60h

## Ray-tracer paralelo com MPI
[ray_parallel.cpp](ray_parallel)

## Particionamento e Aglomeração

O algorimo ray tracing utiliza um vetor com as dimensões da imagem de saída (altura * largura), é calculado para cada pixel da imagem.

```C++
...

for (int y=n-1; y>=0; --y) 
    for (int x=0; x<n; ++x)
...
```

O primeiro laço de repetição percorre a altura e o segundo percorre a largura. Sendo assim, é possível dividir a execução do laço que percorre a altura pelo número de threads ou processadores disponíveis.

```C++
...

int wsize = n / (size - 1);
int start = (rank - 1) * wsize;
int end = start + wsize;
...

void worker(..) {
  ...

  for (int y = (end - 1); y >= start; --y) 
    for (int x=0; x<n; ++x)
    ...
}

...
```


## Mapeamento
Cada thread ou processador, não-mestre, executará igualmente o mesmo trabalho, se não for possível dividir igualmente o trabalho ou se o processador possuir somente uma thread, a thread mestre realizará o trabalho restante.

```C++
// 1 Thread
int remainder = n;

// 2 thread ou mais
if(size > 1) {
  remainder = n % (size - 1);
}

if(remainder) {
  worker(buff, level, n, ss, n - remainder, n, buffer_size - (remainder * n));
}
...


// Para cada thread ou processador não-meste

int wsize = n / (size - 1);
int start = (rank - 1) * wsize;
int end = start + wsize;

worker(block_buffer, level, n, ss, start, end, 0);

wsize = trabalho de cada thread ou processador
start = altura inicial
end = altura final
size = numero de processadores ou threads
n = altura
...
```

## Comunicação 
Cada thread não-mestre realiza seu trabalho e envia o resultado para a thread mestre. A thread mestre aguarda a execução do trabalho de cada thread não-mestre, recebe o resultado de cada thread e salva no vetor que contém o resultado final.

```C++
// Mestre
...

for(int i = 1; i < size; i++) {
  MPI_Recv(&buff[((i - 1) * block_size)], block_size, MPI_CHAR, size - i, tag, MPI_COMM_WORLD, &status);
}
...

// Não-mestre
...

MPI_Send(block_buffer, block_size, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
...
```


## Tempos

![tempo](https://cloud.githubusercontent.com/assets/7422061/16459165/471bffde-3df8-11e6-8644-403bb4700814.png)

| Threads | level 8  | 
| ------- | ---------|
| 1       | 16645169 |
| 2       | 17876797 |
| 3       | 13586019 |
| 4       | 10901365 |



## Speedup

![speedup](https://cloud.githubusercontent.com/assets/7422061/16459164/4719325e-3df8-11e6-8195-d5ed6d633248.png)

| Threads | level 8  | 
| ------- | -------- |
| 1       | 1        |
| 2       | 0,931    |
| 3       | 1,225    |
| 4       | 1,526    |



## Eficiência

![eficiencia](https://cloud.githubusercontent.com/assets/7422061/16459163/470eebb4-3df8-11e6-8f56-2325cf71b2bc.png)

| Threads | level 8  |
| ------- | -------- |
| 1       | 100%     |
| 2       | 46,55%   |
| 3       | 40,83%   |
| 4       | 38,15%   |


## Referências
- Open MPI. Open MPI: Open Source High Performance Computing. https://www.open-mpi.org/

