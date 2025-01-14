#include <stdio.h> 			//biblioteca de comunica��o com o usu�rio
#include <stdlib.h> 		//biblioteca de aloca��o de espa�os de memoria
#include <locale.h> 		//biblioteca de aloca��es de texto por regi�o
#include <string.h>			//biblioteca de aloca��o das strings

int cadastro() //Fun��o responsavel polo cadastro de usuarios
{
		//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		//final cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado:\n"); //coleta do CPF do usuario
	scanf("%s", cpf);		//%s se refere as strings, salva suas informa��es
	
		strcpy(arquivo, cpf);		//Responsavel por copiar as strings
	
		FILE *file;					//cria o arquivo

	file = fopen(arquivo, "w"); 	//cria o arquivo
	fprintf(file, cpf);				//salva o valor da variavel
	fclose(file);					//fecha o arquivo
	
	file = fopen(arquivo, "a");		//atualiza o arquivo
	fprintf(file, " CPF portado pelo(a) "); //anexa��o frase, controle de qualidade
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:\n"); //solicita o nome do usuario
	scanf("%s", nome); //salva esse nome na string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, nome); 	//salva o valor na variavel
	fclose(file); 		//fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, " "); 	//controle de qualidade 
	fclose(file);		//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:\n"); //solicita o sobrenome do usuario
	scanf("%s", sobrenome);	//salva informa��o
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, sobrenome);	//salva o valor na variavel
	fclose(file);		//fecha o arquivo
	
	file = fopen(arquivo, "a");		//atualiza o arquivo
	fprintf(file, " que ocupa o cargo de "); 	//controle de qualidade
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:\n");	//solicita o cargo do usuario
	scanf("%s", cargo); 	//salva informa��o
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, cargo);		//salva a informa��o
	fclose(file);		//fecha o arquivo
	
	system("pause");	//pausa o sistema
	
}

int consulta()
{
		setlocale(LC_ALL, "Portuguese");	//Definindo Idioma
	//define as variaveis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");	//solicita o cpf a ser consultado
	scanf("%s",cpf);	//Salva na variavel
	
	FILE *file; 
	file = fopen(cpf, "r"); //l� o arquivo
	
	if(file == NULL) //caso o CPF informado n�o exita ou o numero errado
	{
		printf("\nCPF invalido!\n\nConfirme os dados, e tente novamente!\n");	//mensagem de erro para o usuario
		printf("\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)		//Passa as informa��es do usuario correspondente ao numero informado
	{
			printf("\nEssas s�o as informa��es do usuario: ");
			printf("%s", conteudo);
			printf("\n\n");
	}
	fclose(file);
	system("pause");
}

int excluir()
{		
	//definindo variaveis
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado");  //solicita o usurio a cerca de ser deletado
	scanf("%s", cpf ); //salva essa informa��o
	
	FILE *file;
	file = fopen(cpf, "r");	//l� o arquivo
	fclose(file);
	
	if(file == NULL) 		//
	{
		printf("\nUsurio n�o identificado.\n\nConfirme os dados e tente novamente.\n\n");	////caso o CPF informado n�o exita ou o numero errado
		system ("pause");
	}

	else
	{
		if(remove(cpf) == 0)	//delata o usuario informado
		{
		printf("\nO Usuario foi deletado com sucesso!\n\n");
		system("pause");
		}
	}	
}
int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)	//Codigo de renicializa��o
	{	
		system("cls"); //Limpeza "chat"
		
		setlocale(LC_ALL, "Portuguese");	//Definindo Idioma
	
		printf ("	Cart�rio da EBAC\n\n");		//Titulo
		printf ("Descri��o: \n\n");		//Descri��o menu
			//Inicio menu
		printf ("\t1 -Cadastrar nome:\n");
		printf ("\t2 -Consultar nome:\n");
		printf ("\t3 -Excluir nome:\n\n");
		printf ("\t4 -Sair do sistema\n\n");
		printf ("Selecione a op��o desejada:\n");
			//Final menu
			
		scanf("%d" , &opcao);	//Armazenando escolha usuario
	
		system("cls");	//Limpeza "chat"
			
	switch(opcao) 	//Inicio feedback de sele��o
						
	{
	case 1:
		cadastro(); 	//chamada de fun��es
	break;
			
	case 2:
		consulta();
	break;
			
	case 3:	
		excluir();
	break;	
	
	case 4:
		printf("Obrigado pelo uso do sistema\n\n");
		return 0;
		break;
			
	default:
		printf("Essa op��o n�o est� disponivel\n");
			system("pause");
	break;
					//Fim feedback de sele��o
					
	}
	
	}

}
