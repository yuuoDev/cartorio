#include <stdio.h> //biblioteca de comunicaÁ„o com o usuario
#include <stdlib.h> //biblioteca de alocaÁ„o de espaÁo em memoria
#include <locale.h> //biblioteca de alocaÁıes de texto por regi√£o
#include <string.h> // biblioteca responsavel da string

int registro() // fun√ß√£o responsavel por cadastra os usuarios no sistema
{
	//inicio da cria√ß√£o da string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria√ß√£o da string
	
	printf("Digite o CPF para se cadastra:");
	scanf("%s", cpf);
	
	strcpy(arquivo,cpf); //responsavel pela a string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome para ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf ("digite o sobrenome para ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo para ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fclose(file);
	
	system ("pause");//fim do cadastro 
	
}

 int consulta() //inicio da consulta
 {
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file ==NULL)
	{
		printf("O arquivo n√£o foi localizado.\n ");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("Essas s√£o as informaÁıes do usuario:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause"); //fim da consulta 
	
	
 }
 
 int deletar()//inicio do deletar usuario 
 {
 	char cpf[40];
 	
 	printf("Digite o cpf para ser deletado: ");
 	scanf("%s",cpf);
 	
 	remove(cpf);
 	
 	FILE *file;
 	file = fopen(cpf,"r");
 	
 	if(file==NULL)
 	{
 	 printf("O usuario nao se encontra no sistema.\n");	
	 system ("pause"); //fim do deletar usuario
	}
 	
 }
 
 
int main()

{
	int opcao=0; //definindo as variaveis
	int x=1; // definindo laco
	char senhadigitada[10]="a";
	int comparacao;
	
	comparacao = strcmp(senhadigitada, "admin");
	

	
	
	
		system("cls");
		for(x=1;x=1;)
		{

			system("cls");
	
    		setlocale(LC_ALL, "portuguese");

   			printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
   			printf("Escolha a op√ß√£o desejada do menu:\n\n");
    		printf("\t1 - Registrar nomes\n");
   			printf("\t2 - Consultar nomes\n");
   			printf("\t3 - Deletar nomes\n");
   			printf("\t4 - sair do menu\n");
			printf("Op√ß√£o:"); //fim do men
			scanf("%d",&opcao); //armazenando a escolha do usuario
    
  		 system("cls");//responsavel por apagar a tela

 	 	  switch(opcao)
 	  		{
   		 		case 1:
				registro();
 	  	 		break;
    	
 		   		case 2:
    			consulta();
    			break;
    	
    			case 3:
    			deletar();
				break;
			
				case 4:
				printf("obrigado por usar o menu.");
				return 0;
				break;
						
				default:
				printf ("essa fun√ß√£o nao existe\n");
    			system("pause");
    			break;
			}
    
		}

}
