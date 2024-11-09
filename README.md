# TP1-Kit-BOOM

Trabaho da disciplina de Projeto e Análise de Algoritmos da Universidade Federal de São João Del Rei 
feito por Arthur Carvalho Rodrigues Oliveira e Felipe de Araujo Antunes Quintas.

Este trabalho tem o seguinte texto como sua descrição:

Você foi contratado pelo Explosivos Jepslon para elaborar o programa de embalamento do Kit
BOOM, que consiste de 4 explosivos com polaridade quádrupla. Neste contexto, você tem que
posicionar os vários explosivos do kit de tal forma que dois explosivos do mesmo tipo não fiquem
adjacentes entre si na mesma caixa. Os explosivos possuem cores bem distintas, mas o espaço
para armazená-los é bem definido, pois eles não podem sofrer movimentos bruscos.
Mais especificamente, as cores são azul (Az), amarelo (Am), vermelho (Vm) e verde (Vd). Os
explosivos são encapsulados em barras com largura de 1 centímetro e comprimento de 1, 2 ou
3 centímetros e devem ser acomodados em uma caixa com 6 por 6 centímetros. As barras são
identificadas pelo seu tamanho (1,2 ou 3) e pela sua cor (Az, Am, Vm, ou Vd). Uma possível
composição do Kit BOOM é a seguinte:

Exemplo presente em /Entrada_saida/Arquivos_entrada/composicao.txt

Para facilitar a sua tarefa de desenvolvimento, você desenvolveu uma forma de representação
de uma configuração, onde cada linha traz a posição inicial e final de uma barra, assim como a
especificação da mesma:

Exemplo presente em /Entrada_saida/Arquivos_entrada/configuracao.txt

O programa testa, para cada composição, várias configurações a fim de verificar se a configuração é válida ou não. Para testar altere os arquivos de entrada(composicao.txt e configuracao.txt), onde para cada configuração existe uma quebra de linha entre elas no arquivo de texto. Na saída do programa, além da saída da verificação da validade da configuração, ainda existe a saída das funções gettimeofday() e getrusage(), porém são apenas para fins de análise.
Para compilar o programa apenas digite "make" no terminal e depois "make run" para rodá-lo, "make clean" para excluir os arquivos objetos(.o) e o executável(.exe).