/* Abaixo são as bibliotecas usadas, importante ressaltar que a time.h é usada pro funcionamento da função srand */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
  
  /* Int são variaveis com numeros inteiros e char com strings */
  int escolha, num1, num2, resultado, resultado2, i, jogar, sair;
  char somas, escolha2, final;
  
  char par[30] = "par";
  char impar[30] = "impar";
  
  /* Abaixo usei o clear para limpar alguns erros de compilação que não mudavam em nada */
  system("clear"); 
  /* Abaixo você escolhe se quer ser par ou impar */
  printf("Voce deseja ser par(1) ou impar(2):\n");
  scanf("%d", &escolha);
  system("clear");
  
  /* os if's usados são para caso o jogador escolher um numero além de (1) ou (2), obrigando ele a escolher apenas 1 ou 2 para jogar */
  if(escolha > 2 || escolha < 1){
    system("clear");
    printf("Escolha apenas 1 ou 2.\n"); 
    scanf("%d", &escolha);
    
    system("clear");
    if(escolha > 2 || escolha < 1){
        printf("Você foi rebelde e não participará dessa rodada.");
    }
  

  } else {
      
      /* Confirma ao jogador sua escolha e a do adversario */
      if(escolha == 1){
    escolha2 = par;
    printf("Você é par e roberto, seu adversario, é impar.\n");
  } else {
    
    escolha2 = impar;
    printf("Voce é impar e roberto, seu adversario, é par.\n");
  }

  /* Pede um número de 0 a 10 para jogar, lembrando que \n é usado para quebra de linha */
  printf("\nescolha um número de 0 a 10: \n");
  scanf("%d", &num1);
  system("clear");
  
  /* if's usados novamente para caso o jogador escolher um número além do permitido */
  if(num1 > 10 || num1 < 0){
      printf("%d não é um número valido, escolha um número entre 0 e 10!\n", num1);
      scanf("%d", &num1);
      
      system("clear");
      
      if(num1 > 10 || num1 < 0){
          printf("Você foi rebelde e não vai participar dessa rodada.");
      }
     
    
  }else {
    system("clear");
  
    /* srand time foi usado para gerar valores aleatorios a função rand que gera valores fixos aleatorios, com o srand esses valores mudam constantemente */
    srand (time(NULL));
  
    for (i = 0; i < 1; i++){
    
    /* Função rand que gera valores aleatorios, lembrando que ela funciona apenas com a biblioteca stdlib.h */  
    num2 = rand() % 10;
    
    /* Determina as escolhas de ambos jogadores */
    printf("Roberto escolheu o numero %d e voce o numero %d.\n", num2, num1);
    
    /* Calcula se o resultado das escolhas são igual par ou impar (todo número par dividido por 2, deixa em seu resto o número 0, isso é perceptivel usando modulo (%) de 2 */
    resultado=num1+num2;
    resultado2 = resultado % 2;
    
    /* caso o resultado for par ( variavel dos calculos acima igual a 0 ) ele fara uma determinada ação */
    if (resultado2 == 0){
        
        /* Usamos outro if para determinar se a escolha do jogador foi par também */
        if(escolha2 == par){
        
        printf ("\nA soma dos valores escolhidos é %d, ou seja, PAR! \n", resultado);
        printf("\nParabéns, voce escolheu par e ganhou!"); 
        
        /* E se não foi ele imprime outro resultado, em um cenário que o resultado é par e sua escolha foi impar */
        } else {
        
        printf ("\nA soma dos valores escolhidos é %d, ou seja, PAR! \n", resultado);
        printf("\nComo você escolheu impar...\n");
        printf("\nRoberto ganhou e voce infelizmente perdeu!"); 
        
        }
    
    /* E se for impar ele fara outra ação, descrita abaixo. */    
    } else {
        /* esse Else também pode ser interpretado como "if(resultado2 == 1)" */
        
        /* Aqui mesma coisa, usamos um if para determinar se o jogador escolheu impar assim como o resultado */
        if(escolha2 == impar){
            
        printf ("\nA soma dos valores escolhidos é %d, ou seja, IMPAR! \n", resultado);
        printf("\nParabéns, voce escolheu impar e ganhou!"); 
        
        } else {
            
        printf ("\nA soma dos valores escolhidos é %d, ou seja, IMPAR! \n", resultado);
        printf("\nComo você escolheu par...\n");
        printf("\nRoberto ganhou e voce infelizmente perdeu!");
        
        }
    }
    }
  }
  }
 }