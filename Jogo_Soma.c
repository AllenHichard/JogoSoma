/*******************************************************************************
Autor: ALLEN HICHARD MARQUES DOS SANTOS
Componente Curricular: Algoritmos I
Concluido em: 09/06/2014
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
******************************************************************************************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>  

/*Prot�tipo das fun��es do algoritmo, cada fun��o ser� explicada no seu escopo*/
void matrizjogo(int alt,int matriz[6][6]);
void soma(int alt, int matriz[6][6], int linha[6], int coluna[6]);
int jogar(int alt,int matriz[6][6]);
void coordenada(int alt, int matriz[6][6],int num);
int resultado(int alt,int matriz[6][6],int linha[6], int coluna[6]);
int jogarautomatico(int alt,int matriz[6][6]);
/*fun��o principal*/
main()
{ 
    int x, alt,num;/* "x" vari�vel para controlar as jogadas, "alt" � o parametro que controla o tamanho da matriz e "num" guarda o retorno de uma fun��o*/
    int nivel, modo_jogo;/* vari�veis do menu do jogo*/
    int matriz[6][6]={{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    /* a matriz foi inicializada [6][6] para control�-la com a vari�vel "alt"*/
    int linha[6],coluna[6];/* para somar as linhas e colunas da matriz*/
    printf("  ***************** Jogo da Soma ******************\n\n");
    /* menu do programa onde pede a entrada de dados para o usu�rio*/
    do{
    /* nivel do jogo*/
        printf("Escolha o nivel do jogo\n\n");
        printf("Digite 1 para o nivel facil\n");
        printf("Digite 2 para o nivel medio\n");
        printf("Digite 3 para o nivel dificil\n\n");
        printf("nivel informado = ");
        scanf("%d",&nivel);
        }while(nivel>3|| nivel<1);
    system("cls");
    printf("  ***************** Jogo da Soma ******************\n\n");
    do{
    /* modo do jogo*/
        printf("Escolha o modo do jogo\n\n");
        printf("Digite 1 para modo manual\n");
        printf("Digite 2 para modo aleatorio\n\n");
        printf("modo de jogo informado = ");
        scanf("%d",&modo_jogo);
        }while(modo_jogo>2|| modo_jogo<1);
    system("cls");
    if(nivel==1 && modo_jogo==1) {
    /* valor enviado como parametro para matriz � igual a 2*/
    /*la�o de repeti��o das jogadas, onde foi escolhido como meio de alternar os jogadores um print,vari�vel de controle "x"*/
      	alt = 2;
      	for(x=0; x<2; x++){        
          	printf("  ***************** Jogo da Soma ******************\n\n");
          	printf("primeiro jogador (linhas)\n\n");
          	printf("     0    1\n");
          	printf("    --   --\n");
          	/*Chamadas das fun��es*/
          	matrizjogo(alt,matriz);
          	soma(alt,matriz,linha,coluna);
          	/*salva o n�mero valido da fun��o que retorna para a main caso as condi��es estejam corretas*/
          	num = jogar(alt,matriz);
          	coordenada(alt,matriz,num);
          	system("cls");
          	printf("  ***************** Jogo da Soma ******************\n\n");
          	printf("segundo jogador (colunas)\n\n");
          	printf("     0    1\n");
          	printf("    --   --\n");
          	/*Chamadas das fun��es*/
          	matrizjogo(alt,matriz);
          	soma(alt,matriz,linha,coluna);
          	/*salva o n�mero valido da fun��o que retorna para a main caso as condi��es estejam corretas*/
          	num = jogar(alt,matriz);
          	coordenada(alt,matriz,num);
          	system("cls");
        }
      	printf("************* Fim do jogo da soma ***************\n");
      	printf("     0   1\n");
      	printf("    --  --\n\n");
      	/*Chamadas das fun��es*/
      	matrizjogo(alt,matriz);
      	soma(alt,matriz,linha,coluna);
      	resultado(alt,matriz,linha,coluna);
      	}
    else if(nivel==1 && modo_jogo==2){
    /* valor enviado como parametro para matriz � igual a 2*/
    /*la�o de repeti��o das jogadas, onde foi escolhido como meio de alternar os jogadores um print, vari�vel de controle "x"*/
    /*fun��o srand para  retorna o valor do rel�gio do computador em segundos (e cujo prot�tipo est� em time.h),...*/
    /* ela est� fora do la�o para que o n�mero seja gerado aleat�rio e n�o crescente*/
    alt = 2;
    srand(time(NULL));
        for(x=0; x<2; x++){        
        	printf("  ***************** Jogo da Soma ******************\n\n");
          	printf("primeiro jogador (linhas)\n\n");
          	printf("     0    1\n");
          	printf("    --   --\n");
          	/*Chamadas das fun��es*/
          	matrizjogo(alt,matriz);
          	soma(alt,matriz,linha,coluna);
          	num = jogarautomatico(alt,matriz);
          	coordenada(alt,matriz,num);
          	system("cls");
          	printf("  ***************** Jogo da Soma ******************\n\n");
          	printf("segundo jogador (colunas)\n\n");
          	printf("     0    1\n");
          	printf("    --   --\n");
          	/*Chamadas das fun��es*/
          	matrizjogo(alt,matriz);
         	soma(alt,matriz,linha,coluna);
         	num = jogarautomatico(alt,matriz);
          	coordenada(alt,matriz,num);
          	system("cls");
    	}
      	printf("************* Fim do jogo da soma ***************\n");
      	printf("     0   1\n");
      	printf("    --  --\n\n");
      	/*Chamadas das fun��es*/
      	matrizjogo(alt,matriz);
      	soma(alt,matriz,linha,coluna);
      	resultado(alt,matriz,linha,coluna);
    }
                                              
    else if(nivel==2 && modo_jogo==1){
      	/* valor enviado como parametro para matriz � igual a 4*/
      	/*la�o de repeti��o das jogadas, onde foi escolhido como meio de alternar os jogadores um print, vari�vel de controle "x"*/
      	alt = 4;
      	for(x=0; x<8; x++){        
          	printf("  ***************** Jogo da Soma ******************\n\n");
          	printf("primeiro jogador (linhas)\n\n");
          	printf("     0    1    2    3\n");
          	printf("    --   --   --   --\n");
          	/*Chamadas das fun��es*/
          	matrizjogo(alt,matriz);
          	soma(alt,matriz,linha,coluna);
          	num = jogar(alt,matriz);
          	coordenada(alt,matriz,num);
          	system("cls");
          	printf("  ***************** Jogo da Soma ******************\n\n");
          	printf("segundo jogador (colunas)\n\n");
          	printf("     0    1    2    3\n");
          	printf("    --   --   --   --\n");
          	/*Chamadas das fun��es*/
          	matrizjogo(alt,matriz);
          	soma(alt,matriz,linha,coluna);
          	num = jogar(alt,matriz);
          	coordenada(alt,matriz,num);
          	system("cls");
        }
    	printf("************* Fim do jogo da soma ***************\n");
    	printf("     0    1    2    3\n");
    	printf("    --   --   --   --\n");
    	/*Chamadas das fun��es*/
    	matrizjogo(alt,matriz);
    	soma(alt,matriz,linha,coluna);
    	resultado(alt,matriz,linha,coluna);
    }
      
    else if(nivel==2 && modo_jogo==2){
      /* valor enviado como parametro para matriz � igual a 4*/
      /*la�o de repeti��o das jogadas, onde foi escolhido como meio de alternar os jogadores um print, vari�vel de controle "x"*/
      /*fun��o srand para  retorna o valor do rel�gio do computador em segundos (e cujo prot�tipo est� em time.h),...*/
      /* ela est� fora do la�o para que o n�mero seja gerado aleat�rio e n�o crescente*/
      	alt = 4;
      	srand(time(NULL));
      	for(x=0; x<8; x++){        
         	printf("  ***************** Jogo da Soma ******************\n\n");
         	printf("primeiro jogador (linhas)\n\n");
         	printf("     0    1    2    3\n");
         	printf("    --   --   --   --\n");
         	/*Chamadas das fun��es*/
        	matrizjogo(alt,matriz);
        	soma(alt,matriz,linha,coluna);
         	num = jogarautomatico(alt,matriz);
         	coordenada(alt,matriz,num);
         	system("cls");
         	printf("  ***************** Jogo da Soma ******************\n\n");
         	printf("segundo jogador (colunas)\n\n");
         	printf("     0    1    2    3\n");
         	printf("    --   --   --   --\n");
         	/*Chamadas das fun��es*/
         	matrizjogo(alt,matriz);
         	soma(alt,matriz,linha,coluna);
         	num = jogarautomatico(alt,matriz);
         	coordenada(alt,matriz,num);
         	system("cls");
        }
      	printf("************* Fim do jogo da soma ***************\n");
      	printf("     0    1    2    3\n");
      	printf("    --   --   --   --\n");
      	/*Chamadas das fun��es*/
      	matrizjogo(alt,matriz);
      	soma(alt,matriz,linha,coluna);
      	resultado(alt,matriz,linha,coluna);
    }
                                        
    else if(nivel==3 && modo_jogo==1){
      	/* valor enviado como parametro para matriz � igual a 6*/
      	/*la�o de repeti��o das jogadas, onde foi escolhido como meio de alternar os jogadores um print, vari�vel de controle "x"*/
      	alt = 6;
      	for(x=0; x<18; x++){        
			printf("  ***************** Jogo da Soma ******************\n\n");
		  	printf("primeiro jogador (linhas)\n\n");
			printf("     0    1    2    3    4    5\n");
			printf("    --   --   --   --   --   --\n");
			/*Chamadas das fun��es*/
		  	matrizjogo(alt,matriz);
		  	soma(alt,matriz,linha,coluna);
		  	num = jogar(alt,matriz);
		  	coordenada(alt,matriz,num);
		  	system("cls");
		  	printf("  ***************** Jogo da Soma ******************\n\n");
		  	printf("segundo jogador (colunas)\n\n");
		  	printf("     0    1    2    3    4    5\n");
		  	printf("    --   --   --   --   --   --\n");
		  	/*Chamadas das fun��es*/
		  	matrizjogo(alt,matriz);
		  	soma(alt,matriz,linha,coluna);
		  	num = jogar(alt,matriz);
		  	coordenada(alt,matriz,num);
		  	system("cls");
      	}
      	printf("************* Fim do jogo da soma ***************\n");
      	printf("     0    1    2    3    4    5\n");
      	printf("    --   --   --   --   --   --\n");
      	/*Chamadas das fun��es*/
      	matrizjogo(alt,matriz);
      	soma(alt,matriz,linha,coluna);
      	resultado(alt,matriz,linha,coluna);
    }
    else if(nivel==3 && modo_jogo==2){
    /* valor enviado como parametro para matriz � igual a 6*/
    /*la�o de repeti��o das jogadas, onde foi escolhido como meio de alternar os jogadores um print, vari�vel de controle "x"*/
    /*fun��o srand para  retorna o valor do rel�gio do computador em segundos (e cujo prot�tipo est� em time.h),...*/
    /*ela est� fora do la�o para que o n�mero seja gerado aleat�rio e n�o crescente*/
      	alt = 6;
      	srand(time(NULL));
      	for(x=0; x<18; x++){        
          	printf("  ***************** Jogo da Soma ******************\n\n");
          	printf("primeiro jogador (linhas)\n\n");
          	printf("     0    1    2    3    4    5\n");
          	printf("    --   --   --   --   --   --\n");
          	/*Chamadas das fun��es*/
          	matrizjogo(alt,matriz);
          	soma(alt,matriz,linha,coluna);
          	num = jogarautomatico(alt,matriz);
          	coordenada(alt,matriz,num);
          	system("cls");
          	printf("  ***************** Jogo da Soma ******************\n\n");
          	printf("segundo jogador (colunas)\n\n");
          	printf("     0    1    2    3    4    5\n");
          	printf("    --   --   --   --   --   --\n");
          	/*Chamadas das fun��es*/
          	matrizjogo(alt,matriz);
          	soma(alt,matriz,linha,coluna);
          	num = jogarautomatico(alt,matriz);
          	coordenada(alt,matriz,num);
          	system("cls");
        }
      	printf("************* Fim do jogo da soma ***************\n");
      	printf("     0    1    2    3    4    5\n");
      	printf("    --   --   --   --   --   --\n");
      	/*Chamadas das fun��es*/
      	matrizjogo(alt,matriz);
      	soma(alt,matriz,linha,coluna);
      	resultado(alt,matriz,linha,coluna);
    }
      getch();
      /*final do programa mostrando o ganhador e sua pontua��o */ 
}
      
  /*fun��o que a mostra a matriz inicial zerada e atualizada a cada jogada*/
  /*a matriz come�a com coordenadas linha "0" e coluna "0", diferente do  comum que seria 1 para ambas*/
  void matrizjogo(int alt,int matriz[6][6]){
	  	int i,j;
	  	for(i=0; i<alt; i++){
	        printf("\n%d|",i);  
	        for(j=0;j<alt;j++){
	            printf("%4d " ,matriz [i] [j]);
	        }
	        printf("\n"); 
	    } 
	  	printf("\n");         
  } 
   
  /*fun��o que a mostra a soma das linhas e colunas da matriz e atualizada a cada jogada*/
   void soma(int alt, int matriz[6][6], int linha[6], int coluna[6]){
	   int i, j;
	   /*soma das linhas armazenadas em um vetor*/
	   for(i = 0; i < alt; i++){
	        linha[i] = 0;
	        for(j = 0; j < alt; j++){
	            linha[i] = linha[i] + matriz[i][j];            
	        }
	        printf ("Soma da linha %d = %d",i, linha[i]);
	        printf("\n");
	    }
	   printf("\n");
   /*somas das colunas armazenadas e um vetor*/
	   for(j = 0; j < alt; j++){
	        coluna[j] = 0;
	        for(i = 0; i < alt; i++){
	            coluna [j] = coluna [j] + matriz[i][j];            
	        }
	        printf ("Soma da coluna %d = %d",j, coluna[j]);
	        printf("\n");
	    } 
	  	printf("\n");
   }                              
   /*pede o n�mero ao jogador da vez*/
   int jogar(int alt,int matriz[6][6]) {          
   		int num,i,j;             
	   	printf("informe o numero: ");
	   	scanf("%d", &num);
   		/*analisa se est� entre 1 e 100*/ 
   		if(num<1||num>100){
            do{
                printf("numero invalido\n");
                printf("informe o numero: ");
                scanf("%d", &num);
            }while(num<1||num>100);
        }    
   		/*analisa se j� existe o n�mero informado na matriz*/                
   		for (i=0; i<alt; i++){
            for (j=0; j<alt; j++){
                if (num==matriz[i][j]){
                do{
                	printf ("numero ja utilizado\n");
   /* foi utilizado uma fun��o recursiva, onde se o valor informado j� tenha na matriz ela refaz toda a fun��o*/
   /* n�o precisando repetir as condi��es que ela possui*/
   /*a vari�vel num, foi colocada para ganhar o valor da pr�pria fun��o, sem essa vari�vel para guardar o n�mero "entra em um loop infinito"*/   
                    num = jogar(alt,matriz);
                    }while (num==matriz[i][j]);
                }
            }
        } 
   /*retorna o numero se for valido para a main que salva essa informa��o para pedir as coordenadas*/     
   		return (num);
   /*retonar o n�mero para a main*/
   }
   
   /*recebe como par�metro o n�mero v�lido e pede as coordenadas*/
   void coordenada(int alt, int matriz[6][6],int num) {
	   	int i, j;
	   	printf("informe a linha: ");
	   	scanf("%d", &i);
	   	printf("informe a coluna: ");
	   	scanf("%d", &j);
   /*verifica de a matriz existe, se as coordenadas que o usuario informou cont�m da matriz*/
  		if(i>=alt || j>=alt){
            do{
                printf(" a matriz nao existe\n");
                printf("informe a linha: ");
                scanf("%d", &i);
                printf("informe a coluna: ");
                scanf("%d", &j);
                }while(i>=alt || j>=alt);
        }
   		/*verifica que a matriz j� tem algum n�mero naquela coordenada*/
   		if(matriz[i][j]!=0){
            do{
                do{
                    printf("ja contem numero ou matriz nao existe\ninforme novamente\n");
                    printf("informe a linha: ");
                    scanf("%d", &i);
                    printf("informe a coluna: ");
                    scanf("%d", &j);
                }while(i>=alt || j>=alt);
            }while(matriz[i][j]!=0);
        }
   /*Se a matriz for 0 na coordenada informada ela receber� o n�mero*/
  		matriz[i][j] = num;   
   }
   
   /*ap�s a matriz est� completa e os vetores j� tenha somado todas as linhas e colunas ela organiza de ordem decrescente as somas e mostra o vencedor*/
   int resultado(int alt,int matriz[6][6],int linha[6], int coluna[6]){
   /*foi utilizado a ordena��o por sele��o para organizar de forma decrescente as somas dos vetores*/
   		int i,j, aux, maiorlinha, maiorcoluna ,cont=0;
   		for(i=0; i<alt-1; i++){
            for(j= i+1; j<alt; j++){
                if(linha[i]<linha[j]){
                    aux = linha[i];
                    linha[i] = linha[j];
                    linha[j] = aux;
                }
            }
        }
   		printf("numero organizado das linhas de ordem decrescente\n\n");
   		/*foi utilizado a ordena��o por sele��o para organizar de forma decrescente as somas dos vetores*/
   		for(i=0; i<alt; i++){
            printf ("%d� maior soma das linhas = %d\n\n",i + 1, linha[i]); 
        }
   		for(i=0; i<alt-1; i++){
            for(j= i+1; j<alt; j++){
                if(coluna[i]<coluna[j]){
                  	aux = coluna[i];
                  	coluna[i] = coluna[j];
                  	coluna[j] = aux;
                }
           }
        }
  		printf("numero organizado das colunas de ordem decrescente\n\n");
   		for(j=0; j<alt; j++){
            printf ("%d� maior soma das colunas = %d\n\n",j+1, coluna[j]); 
        }
   		/* c�digo que mostra o ganhador cont � uma vari�vel controle que foi inicializada com zero*/ 
  		 do{
	      	maiorlinha = linha[0 + cont];
	      	maiorcoluna = coluna[0 + cont];
      		if(maiorlinha>maiorcoluna){
              	printf("o vencedor foi o primeiro jogador com %d pontos de soma", maiorlinha);
                return 0;
                /*utilizado para quando entrar nesse la�o parar a execu��o e s� mostrar o ganhador uma vez*/ 
                /*se n�o fosse colocado esse comando mesmo havendo um ganhador ele iria conferir a proxima maior soma*/ 
            }
      		else if(maiorlinha<maiorcoluna){
                printf("o vencedor foi o segundo jogador com %d pontos de soma", maiorcoluna);
                return 0;
            }
      		else{ 
            	/*condi��o para mostrar o que o jogo foi empatado apenas uma vez*/
            	/*s� ira mostar se cont for menor que o parametro da matriz e contador for diferente de zero, e contador dor igual alt -1*/ 
            	/* condi��o para s� printar no final do jogo e n�o a cada an�lise das somas*/  
            	if(cont<alt && cont!=0 && cont==alt-1){
                    printf("o jogo foi empatado");
                }                     
            	cont++;
            }
       }while(cont<alt && cont!=0);
   }

   /*sorteia o n�mero para o usu�rio escolher as coordenadas*/ 
   int jogarautomatico(int alt,int matriz[6][6]){
   		int i,j,num;
   		/*os n�meros s� seriam sorteados entre 0 a 99, da� o mais 1 para que fique entre 1 e 100 */ 
   		/*n�o � preciso verificar se o n�mero est� entre um e cem, porque o comando s� vai sortear dentro desse limite de 1 a 100*/
   		num=rand() % 100+1 ;         
   		printf("o numero sorteado foi: %d\n", num);
  		/*analisa se j� existe o numero informado na matriz*/                     
  		for (i=0; i<alt; i++){
            for (j=0; j<alt; j++){
                if (num==matriz[i][j]){
                    printf ("numero ja utilizado\n");
                    do{
                        num=jogarautomatico(alt,matriz);   
   						/* foi utilizado uma fun��o recursiva, onde se o valor informado j� tenha na matriz ela refaz toda a fun��o*/
   						/* n�o precisando repetir as condi��es que ela possui*/
   						/*a vari�vel num, foi colocada para ganhar o valor da pr�pria fun��o, sem essa vari�vel para guardar o n�mero "entra em um loop infinito"*/   
                    }while (num==matriz[i][j]);
                }
            }
        }  
   		/*retorna o numero se for valido para a main que salva essa informa��o para pedir as coordenadas*/
   		return (num);
   		/*retonar o n�mero para a main*/
   }
