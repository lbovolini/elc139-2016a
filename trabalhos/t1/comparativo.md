[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2016a) > T1

TOP500 & me: Comparativo de Arquiteturas Paralelas
--------------------------------------------------

Nome: Lucas Bovolini

| Característica                                            | Computador no TOP500  | Meu computador  |
| --------------------------------------------------------- | --------------------- | --------------- |
| Nome/Título                                               | SEKIREI-ACC                      | Asus S46CB                |
| Imagem (foto, diagrama, screenshot, etc.)                 | <img src="http://ep.yimg.com/ay/yhst-10634168652522/4xg0f28796-lenovo-intel-xeon-e5-2680-v3-2-5ghz-30mb-cache-12-core-processor-6.png" height="250" width="250"> |  <img src="https://www.asus.com/media/global/products/4NCrBoVHxzty7brJ/P_500.jpg" height="250" width="250"> |
| Classificação de Flynn                                    | MIMD                      | MIMD                |
| Memória: compartilhada, distribuída ou ambas?             | Distribuída                     |  Compartilhada               |
| Número total de núcleos de processamento                  | 15,552                       |  2               |
| Fabricante e modelo do(s) processador(es)                 | Intel Xeon E5-2680v3                      | Intel Core i5-3317U                |
| Frequência do(s) processador(es)                          | 2.5 GHz ~ 3.3 GHz                      | 1.7 GHz ~ 2.6 GHz                |
| Memória total                                             | 36,864 GB                      |  6 GB               |
| Tipo(s) de interconexão entre os núcleos/processadores    | Infiniband FDR e Intel QuickPath Interconnect (QPI)                     | Direct Media Interface (DMI 2.0)                |
| Desempenho Linpack                                        | 777.4 TFlop/s                      |  17.9 GFlop/s              |

### Referências
- TOP500. SEKIREI-ACC - SGI ICE XA, XEON E5-2680V3 12C 2.5GHZ, INFINIBAND FDR, NVIDIA K40. http://www.top500.org/system/178527
- Intel. Intel® Xeon® Processor E5-2680 v3 
(30M Cache, 2.50 GHz). http://ark.intel.com/pt-br/products/81908/Intel-Xeon-Processor-E5-2680-v3-30M-Cache-2_50-GHz
- Intel. Intel® Core™ i5-3317U Processor 
(3M Cache, up to 2.60 GHz). http://ark.intel.com/pt-br/products/65707/Intel-Core-i5-3317U-Processor-3M-Cache-up-to-2_60-GHz
- Asus. S46CB. https://www.asus.com/br/Notebooks/S46CB/
- Communities Intel. What is Direct Media Interface (DMI)?. https://communities.intel.com/thread/13051?start=0&tstart=0
- Wikipedia. Intel QuickPath Interconnect. https://en.wikipedia.org/wiki/Intel_QuickPath_Interconnect
- Hardware Secrets. Everything You Need to Know About The QuickPath Interconnect (QPI). http://www.hardwaresecrets.com/everything-you-need-to-know-about-the-quickpath-interconnect-qpi/
