Trabaho da disciplina de Projeto e Análise de Algoritmos da Universidade Federal de São João Del Rei 

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

2 3Az  
2 2Az  
3 1Az  
2 2Vm  
2 1Vm  
2 3Am  
1 1Am  
2 2Vd  
2 3Vd  

Para facilitar a sua tarefa de desenvolvimento, você desenvolveu uma forma de representação
de uma configuração, onde cada linha traz a posição inicial e final de uma barra, assim como a
especificação da mesma:

1 1 3 1 3Am  
4 1 6 1 3Am  
1 2 3 2 3Vd  
4 2 4 2 1Az  
5 2 6 2 2Vd  
1 3 3 3 3Vd  
4 3 4 3 1Am  
5 3 5 3 1Vm  
6 3 6 3 1Vm  
1 4 1 5 2Vm  
2 4 2 5 2Vm  
3 4 3 5 2Az  
4 4 4 5 2Vd  
5 4 5 5 2Az  
6 4 6 4 1Az  
6 5 6 5 1Az  
1 6 3 6 3Az  
4 6 6 6 3Az  

O programa testa, para cada composição, várias configurações a fim de verificar se é válida ou não. Para testar, altere os arquivos de entrada(composicao.txt e configuracao.txt), onde para cada configuração existe uma quebra de linha entre elas no arquivo de texto

Para compilar o programa apenas digite "make" no terminal e depois "make run" para rodá-lo, "make clean" para excluir os arquivos objetos(.o) e o executável(.exe).