#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <curses.h>


int main(){
	
	int qntVarDecisao = 0, i,maxOuMin,qntVarRestricao = 0,k = 1,j = 1,x=1,y=1,soma = 0,auxPivo = 0,auxPivoMenorIgual = 0;
	int pegaLinhaPivo = 0,pegaLinha = 0,opc[1000];
	float pegaPivo,auxNovaLinhaP[1000],auxLinhaP[1000],numero = 9999999,auxVar1[1000],auxVar2[1000],auxVar3[1000];
	float varDecisao[qntVarDecisao],vetZ[1000],colunaPivo,diviPivo =0,pivo;
	float varRestricao[x = 1000][y = 1000];
	float menorIgual[qntVarRestricao],maiorIgual[qntVarRestricao];
	float nlp[1000][1000];//NOVA LINHA PIVÔ
	float matIdentidade [1000][1000],auxMaiorI[1000],auxMenorI[1000],auxLinhaId[1000],multNLP=0;
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
				{   printf("\n Digite 1 para <= 2 para maiorIgual \n");
			        scanf("%d",&opc[j]);
			        if(opc[j] == 1)
			        {
			        printf("\n <= \n");
				    scanf("%f",&menorIgual[j]);
					}
					else if(opc[j] == 2)
			        {
			        	printf("\n >= \n");
						scanf("%f",&menorIgual[j]);
			        }
			        else printf("\n OPCAO INVALIDA\n");
					/*if(varRestricao[j][auxPivo] )
					{
						auxPivoMenorIgual = j;
						if(pivo <= varRestricao[j][auxPivo])
						pivo = menorIgual[auxPivoMenorIgual];
						printf("%f pivoooooooooooo\n",pivo);
						
					}*/
					if(varRestricao[j][auxPivo] )
					{
						pegaPivo = menorIgual[j];
						if((pegaPivo / varRestricao[j][auxPivo]) > 0)
						{
							pegaPivo = pegaPivo / varRestricao[j][auxPivo];
							if(numero >= pegaPivo){numero = pegaPivo;
							pivo = varRestricao[j][auxPivo];
							pegaLinhaPivo = j;}
						}

					
					}
					fflush(stdin);
					printf("pivoooooo zsds %f \n",pivo);
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
				{ 
					if(opc[j] == 1)
					{
					printf(" <= %0.2f ",menorIgual[j]);
					}
					else if(opc[j] == 2)
					{
					printf(" >= %0.2f ",menorIgual[j]);
					}
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
			if (opc[j] == 1)
			{
				matIdentidade [j][j] = 1;
			}
			else if(opc[j] == 2)
			{
				matIdentidade [j][j] = -1;
			}
				
				
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
				auxLinhaP[k] = varRestricao[j][k];
				auxNovaLinhaP[k] = auxLinhaP[k];
			}
			matIdentidade[j][j] = (matIdentidade [j][j] / pivo);
			auxLinhaId[j] = matIdentidade[j][j];
			menorIgual[j] = menorIgual[j] / pivo;
			auxMenorI[j] = menorIgual[j];
			maiorIgual[j] = maiorIgual[j] / pivo;
			auxMaiorI[j] = maiorIgual[j];
		}
		
		
		
		if (pegaLinhaPivo == 1)
		{
			
		
			for(j = 2 ; j  <= qntVarRestricao; j++)	
			{
				
					
				
				for(k = 1 ; k <= qntVarDecisao; k++)
				{	
					multNLP = (varRestricao[j][auxPivo]*-1);
					auxVar1[k] = multNLP * (auxNovaLinhaP[k]);
					varRestricao[j][k] = auxVar1[k] + varRestricao[j][k]  ;
				
					
					
					//colocar Z tbm
				}
					 for(k = 1 ; k <= qntVarRestricao; k++)
				{	
					auxVar2[k] =  multNLP * auxLinhaId[k];
					matIdentidade[j][k] = auxVar2[k] + matIdentidade[j][k] ;
					}
					auxVar3[j] = multNLP * auxMenorI[pegaLinhaPivo];
					menorIgual[j] = auxVar3[j] + menorIgual[j];
					auxMaiorI[pegaLinhaPivo] = multNLP * auxMaiorI[pegaLinhaPivo];
					maiorIgual[j] = auxMenorI[pegaLinhaPivo] + maiorIgual[j];
					
			}
			}
		else if (pegaLinhaPivo == qntVarRestricao)
		{
			
		
			for(j = (qntVarRestricao-1) ; j > 0 ;j--)	
			{
				
					
				
				for(k = 1 ; k <= qntVarDecisao; k++)
				{	
					multNLP = (varRestricao[j][auxPivo]*-1);
					auxVar1[k] = multNLP * (auxNovaLinhaP[k]);
					varRestricao[j][k] = auxVar1[k] + varRestricao[j][k]  ;
				
					//colocar Z tbm
				}
					 for(k = 1 ; k <= qntVarRestricao; k++)
				{	
					auxVar2[k] =  multNLP * auxLinhaId[k];
					matIdentidade[j][k] = auxVar2[k] + matIdentidade[j][k] ;
					}
					auxVar3[j] = multNLP * auxMenorI[pegaLinhaPivo];
					menorIgual[j] = auxVar3[j] + menorIgual[j];
					auxMaiorI[pegaLinhaPivo] = multNLP * auxMaiorI[pegaLinhaPivo];
					maiorIgual[j] = auxMenorI[pegaLinhaPivo] + maiorIgual[j];
					
			}
			}

			
		else if (pegaLinhaPivo > 1)
		{
			for(j = (pegaLinhaPivo-1) ; j  > 0 ; j--)	
			{
								
				for(k = 1 ; k <= qntVarDecisao; k++)
				{	
					multNLP = (varRestricao[j][auxPivo]*-1);
					auxVar1[k] = multNLP * (auxNovaLinhaP[k]);
					varRestricao[j][k] = auxVar1[k] + varRestricao[j][k];

				}
					 for(k = 1 ; k <= qntVarRestricao; k++)
				{	
					auxVar2[k] =  multNLP * auxLinhaId[k];
					matIdentidade[j][k] = auxVar2[k] + matIdentidade[j][k];
					}
					auxVar3[j] = multNLP * auxMenorI[pegaLinhaPivo];
					menorIgual[j] = auxVar3[j] + menorIgual[j];
			}

			
			 for(j = qntVarRestricao ; j  > pegaLinhaPivo; j--)	
			{
				
					
				
				for(k = 1 ; k <= qntVarDecisao; k++)
				{	
					multNLP = (varRestricao[j][auxPivo]*-1);
					auxVar1[k] = multNLP * (auxNovaLinhaP[k]);
					varRestricao[j][k] = auxVar1[k] + varRestricao[j][k]  ;
				
					
					
					
				}
					 for(k = 1 ; k <= qntVarRestricao; k++)
				{	
					auxVar2[k] =  multNLP * auxLinhaId[k];
					matIdentidade[j][k] = auxVar2[k] + matIdentidade[j][k] ;
					}
					auxVar3[j] = multNLP * auxMenorI[pegaLinhaPivo];
					menorIgual[j] = auxVar3[j] + menorIgual[j];
					
					

			}
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