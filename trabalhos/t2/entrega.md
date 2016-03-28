!TODO
# T2: Experiências com Profilers

	```
	Aluno: Lucas Bovolini
	Disciplina: Programação Paralela
	Professora: Andrea Schwertner Charão
	```

## Parte 1

(a) O tempo gasto na execução da função "dot_product" varia conforme as entradas e, consequentemente, o percentual do tempo gasta no execução das funções "dot_product" e "init_vectors", as demais estatísticas permanecem as mesmas para todas as funções.


(b) A função "dot_product" poderia ser paralelizada pois é a que ocupa a maior parte do tempo de execução que varia, principalmente, conforme o número de vezes em que o produto escalar é calculado.


## Parte 2
Valgrind Callgrind

(a) É de fácil instalação pois está disponível no repositório extra do Arch Linux, a sua saída pode ser visializada através do KCachegrind permitindo uma melhor visualização dos resultados obtidos. Callgrind registra a contagem de instruções , e não o tempo real gasto em uma função. Se você tem um programa onde o gargalo é o arquivo I/O, os custos associados com arquivos de leitura e escrita não irão aparecer no perfil, assim como os que não são tarefas de uso intensivo da CPU.

(b) A função "multiplicar_matrizes" é a que consome praticamente todo o tempo da execução para todas as entradas. Esta função poderia ser paralizada pelo fato de executar muitas instruções na CPU.

Referencias:

The Geek Stuff. GPROF Tutorial – How to use Linux GNU GCC Profiling Tool. http://www.thegeekstuff.com/2012/08/gprof-tutorial/

Wikipedia. List of performance analysis tools. https://en.wikipedia.org/wiki/List_of_performance_analysis_tools#General_purpose.2C_language_independent

Stanford University. Guide to callgrind. https://web.stanford.edu/class/cs107/guide_callgrind.html

Gernot Klingler. gprof, Valgrind and gperftools – an evaluation of some tools for application level CPU profiling on Linux. http://gernotklingler.com/blog/gprof-valgrind-gperftools-evaluation-tools-application-level-cpu-profiling-linux/

Valgrind
gperftools
Allinea MAP
Zoom
Oprofile
