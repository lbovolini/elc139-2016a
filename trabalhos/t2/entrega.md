

# T2: Experiências com Profilers

	
- Aluno: Lucas Bovolini
- Disciplina: Programação Paralela 2016/01
- Professora: Andrea Schwertner Charão


## Parte 1

- (a) O tempo gasto na execução da função "dot_product" varia conforme as entradas e, consequentemente, o percentual do tempo gasta no execução das funções "dot_product" e "init_vectors", as demais estatísticas permanecem as mesmas para todas as funções.

- (b) A função "dot_product" poderia ser paralelizada pois é a que ocupa a maior parte do tempo de execução que varia, principalmente, conforme o número de vezes em que o produto escalar é calculado.

![gprof-dotprod_seq-30000000-90](https://cloud.githubusercontent.com/assets/7422061/14092627/bb7fcf0e-f51e-11e5-86eb-091e23ed27a7.png)
> Executado com: tamanho do vetor 30.000.000 e número de repetições 90

![gprof-dotprod_seq-3000-10000](https://cloud.githubusercontent.com/assets/7422061/14092653/e873d302-f51e-11e5-91eb-2740b365ca8a.png)
> Executado com: tamanho do vetor 3.000 e número de repetições 10.000


## Parte 2

### Valgrind Callgrind

- (a) É de fácil instalação pois está disponível no repositório extra do Arch Linux, a sua saída pode ser visializada através do KCachegrind permitindo uma melhor visualização dos resultados obtidos. Callgrind registra a contagem de instruções , e não o tempo real gasto em uma função. Se você tem um programa onde o gargalo é o arquivo I/O, os custos associados com arquivos de leitura e escrita não irão aparecer no perfil, assim como os que não são tarefas de uso intensivo da CPU.

- (b) A função "multiplicar_matrizes" é a que consome praticamente todo o tempo da execução para todas as entradas. Esta função poderia ser paralizada pelo fato de executar muitas instruções na CPU.

![callgrind-mat_mul-1000-01](https://cloud.githubusercontent.com/assets/7422061/14092725/60ca581c-f51f-11e5-856d-3d8cfcb8c654.png)

![callgrind-mat_mul-1000-02](https://cloud.githubusercontent.com/assets/7422061/14092735/7152591e-f51f-11e5-82a1-8ece22a0b33f.png)

![callgrind-mat_mul-1000-03](https://cloud.githubusercontent.com/assets/7422061/14092752/7a683b22-f51f-11e5-9f5c-59e614c6b3fb.png)

![callgrind-mat_mul-1000-04](https://cloud.githubusercontent.com/assets/7422061/14092793/c1d93678-f51f-11e5-9484-441c47cff8d6.png)



### Referências

- The Geek Stuff. GPROF Tutorial – How to use Linux GNU GCC Profiling Tool. http://www.thegeekstuff.com/2012/08/gprof-tutorial/

- Wikipedia. List of performance analysis tools. https://en.wikipedia.org/wiki/List_of_performance_analysis_tools#General_purpose.2C_language_independent

- Stanford University. Guide to callgrind. https://web.stanford.edu/class/cs107/guide_callgrind.html

- Gernot Klingler. gprof, Valgrind and gperftools – an evaluation of some tools for application level CPU profiling on Linux. http://gernotklingler.com/blog/gprof-valgrind-gperftools-evaluation-tools-application-level-cpu-profiling-linux/