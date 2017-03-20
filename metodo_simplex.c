#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <curses.h>


int main(){
	
	int qntVarDecisao = 0, i,maxOuMin,qntVarRestricao = 0,k = 1,j = 1,x=1,y=1,soma = 0,auxPivo = 0,auxPivoMenorIgual = 0;
	int pegaLinhaPivo = 0;
	float pegaPivo;
	float varDecisao[qntVarDecisao],vetZ[1000],colunaPivo,diviPivo =0,pivo;
	float varRestricao[x = 1000][y = 1000];
	float menorIgual[qntVarRestricao],maiorIgual[qntVarRestricao];
	float nlp[1000][1000];//NOVA LINHA PIVÔ
	float matIdentidade [1000][1000];
	printf("\n1 - MAXIMIZAR\n2 - MINIMIZAR\n");
		scanf("%d",&maxOuMin);

	switch(maxOuMin)
	{
		case 1: 
				
					maxOuMin = 1;
					
		break;
		case 2: 
					maxOuMin = 2;
					
		break;	
		default:printf("\nOpcao Inválida\n"); 
		break;
			
	}
		

		printf("Informe quantas variaveis de decisao serao utilizadas:\n");
		scanf("%d",&qntVarDecisao);
			if (y < qntVarDecisao){
				y = qntVarDecisao ;
				
			}
//-----------------------------------Entrada------------------------------------------------------------------		
		for(i = 1 ; i<=qntVarDecisao; i++)
		{
			printf("\n Digite apenas o numero da %dº variavel de decisao: \n",i );
			scanf("%f",&varDecisao[i]);

			vetZ[i] = varDecisao[i] * (- 1);
			if (colunaPivo >= vetZ[i]){
				colunaPivo = vetZ[i];
				auxPivo = i;
			}
		}

		
		printf("Informe quantas restricoes serao utilizadas:\n");
		scanf("%d",&qntVarRestricao);
		if (x < qntVarRestricao){
				x =  qntVarRestricao;
				
			}
		


		for(j = 1 ; j<=qntVarRestricao; j++)
		{

			for(k = 1 ; k<=qntVarDecisao; k++)
			{
			printf("\n Digite o numero da %dº linha e da %dº coluna : \n",j,k);
			scanf("%f",&varRestricao[j][k]);
			fflush(stdin);
			
			}
				if(maxOuMin == 1)
				{   printf("\n  <=  \n");
				    scanf("%f",&menorIgual[j]);
					/*if(varRestricao[j][auxPivo] )
					{
						auxPivoMenorIgual = j;
						if(pivo <= varRestricao[j][auxPivo])
						pivo = menorIgual[auxPivoMenorIgual];
						printf("%f pivoooooooooooo\n",pivo);
						
					}*/
					if(varRestricao[j][auxPivo] )
					{
						
						if(pivo <= menorIgual[j]){
						pegaPivo = menorIgual[j];
						if((pegaPivo / varRestricao[j][auxPivo]) > 0)
						{
							pegaPivo = pegaPivo / varRestricao[j][auxPivo];
							if(pivo <= pegaPivo )
							pivo = varRestricao[j][auxPivo];
							pegaLinhaPivo = j;
						}

					}
					}
					fflush(stdin);
				}
				 else if (maxOuMin == 2)
			 	{
				 	printf("\n  >=  \n");
					scanf("%f",&maiorIgual[j]);
					
					fflush(stdin);
				 
			 	}
			fflush(stdin);
			
		}
		
		
		printf("\n\n");

				if(maxOuMin == 1)
				{ printf("MAXIMIZAR Z = ");
				}
				 else if (maxOuMin == 2)
			 	{
				 	printf("MINIMIZAR Z =");
				 
			 	}
				
	for(i = 1 ; i<=qntVarDecisao; i++)
		{	
			if (i < qntVarDecisao)
				{
					printf(" %0.2fX%d + ",varDecisao[i],i);
				}
			else
				printf("%0.2f X%d ",varDecisao[i],i);

		}
		
	printf("\n\n SUJEITO A: \n");
	printf("               ");
	for(j = 1 ; j<=qntVarRestricao; j++)
		{
			for(k = 1 ; k<=qntVarDecisao; k++)
			{
			printf(" %0.2fX%d  ",varRestricao[j][k],k);
			fflush(stdout);			
			fflush(stdin);
	
			}
			if(maxOuMin == 1)
				{ printf(" <= %0.2f ",menorIgual[j]);
						
				}
				 else if (maxOuMin == 2)
			 	{
				 	printf(" >= %0.2f ",maiorIgual[j]);
				 		
				 
			 	}
			printf(" \n\n               ");
			
		}
		printf("%0.2f e o nosso pivo", pivo );
	
//------------------------------------------------//MATRIZ IDENTIDADE--------------------------------------------------------
		
	for(j = 1 ; j<=qntVarRestricao; j++)
		{
			for(k = 1 ; k<=qntVarRestricao; k++)
			{
				matIdentidade [j][k] = 0;

			}
				matIdentidade [j][j] = 1;
				
		}
	printf("\n\n TABELA 1: ");
	printf("\n\n Simplex:                 \n");
	 printf("               ");
	for(j = 1 ; j<=qntVarRestricao; j++)
		{
			for(k = 1 ; k<=qntVarDecisao; k++)
			{

			printf(" %0.2fX%d  ",varRestricao[j][k],k);
			fflush(stdout);			
			fflush(stdin);
			}
			for(k = 1 ; k<=qntVarRestricao; k++)
			{
				printf(" %0.2f ",matIdentidade [j][k]);
			}
		
			if(maxOuMin == 1)
				{ printf(" | %0.2f ",menorIgual[j]);
						
				}
				 else if (maxOuMin == 2)
			 	{
				 	printf(" | %0.2f ",maiorIgual[j]);
				 		
				 
			 	}
			printf(" \n               ");
			
		}
		soma = qntVarDecisao + qntVarRestricao + 1;
		
		for(i = qntVarDecisao ; i<=soma; i++)
		{
			vetZ[i] = vetZ[i] + 0;
		}

		printf("\n           Z = ");
		
		for(i = 1 ; i<=soma; i++)
		{	
			printf("  %0.2f ",vetZ[i]);
			if (i == (soma -1)){

				printf(" |");
			}
		}
		printf(" \n\n");
		
//----------------------------------------------------NOVA LINHA PIVÔ---------------------------------------------
for(j = pegaLinhaPivo ; j<= pegaLinhaPivo; j++)
		{
			for(k = 1 ; k<=qntVarDecisao; k++)
			{
				varRestricao[j][k] = (varRestricao[j][k] / pivo);
			
			}
			matIdentidade[j][j] = (matIdentidade [j][j] / pivo);
			menorIgual[j] = menorIgual[j] / pivo;
			maiorIgual[j] = maiorIgual[j] / pivo;
		}
		
		for(j = 1 ; j<=qntVarRestricao; j++)
		{
			for(k = 1 ; k<=qntVarDecisao; k++)
			{
				printf(" %0.3f  ",varRestricao[j][k]);
			
			}
			for(k = 1 ; k<=qntVarRestricao; k++)
			{
				printf(" %0.3f ",matIdentidade [j][k]);
			}
			if(maxOuMin == 1)
				{ printf(" | %0.2f ",menorIgual[j]);
						
				}
				 else if (maxOuMin == 2)
			 	{
				 	printf(" | %0.3f ",maiorIgual[j]);
				 		
				 
			 	}
			printf(" \n               ");
			printf(" \n\n ");
		}
  return 0;
}