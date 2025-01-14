#include <stdio.h> 			//biblioteca de comunicação com o usuário
#include <stdlib.h> 		//biblioteca de alocação de espaços de memoria
#include <locale.h> 		//biblioteca de alocações de texto por região
#include <string.h>			//biblioteca de alocação das strings

int cadastro() //Função responsavel polo cadastro de usuarios
{
		//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
		//final criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado:\n"); //coleta do CPF do usuario
	scanf("%s", cpf);		//%s se refere as strings, salva suas informações
	
		strcpy(arquivo, cpf);		//Responsavel por copiar as strings
	
		FILE *file;					//cria o arquivo

	file = fopen(arquivo, "w"); 	//cria o arquivo
	fprintf(file, cpf);				//salva o valor da variavel
	fclose(file);					//fecha o arquivo
	
	file = fopen(arquivo, "a");		//atualiza o arquivo
	fprintf(file, " CPF portado pelo(a) "); //anexação frase, controle de qualidade
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
	scanf("%s", sobrenome);	//salva informação
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, sobrenome);	//salva o valor na variavel
	fclose(file);		//fecha o arquivo
	
	file = fopen(arquivo, "a");		//atualiza o arquivo
	fprintf(file, " que ocupa o cargo de "); 	//controle de qualidade
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:\n");	//solicita o cargo do usuario
	scanf("%s", cargo); 	//salva informação
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, cargo);		//salva a informação
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
	file = fopen(cpf, "r"); //lê o arquivo
	
	if(file == NULL) //caso o CPF informado não exita ou o numero errado
	{
		printf("\nCPF invalido!\n\nConfirme os dados, e tente novamente!\n");	//mensagem de erro para o usuario
		printf("\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)		//Passa as informações do usuario correspondente ao numero informado
	{
			printf("\nEssas são as informações do usuario: ");
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
	scanf("%s", cpf ); //salva essa informação
	
	FILE *file;
	file = fopen(cpf, "r");	//lê o arquivo
	fclose(file);
	
	if(file == NULL) 		//
	{
		printf("\nUsurio não identificado.\n\nConfirme os dados e tente novamente.\n\n");	////caso o CPF informado não exita ou o numero errado
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
	
	for(laco=1;laco=1;)	//Codigo de renicialização
	{	
		system("cls"); //Limpeza "chat"
		
		setlocale(LC_ALL, "Portuguese");	//Definindo Idioma
	
		printf ("	Cartório da EBAC\n\n");		//Titulo
		printf ("Descrição: \n\n");		//Descrição menu
			//Inicio menu
		printf ("\t1 -Cadastrar nome:\n");
		printf ("\t2 -Consultar nome:\n");
		printf ("\t3 -Excluir nome:\n\n");
		printf ("\t4 -Sair do sistema\n\n");
		printf ("Selecione a opção desejada:\n");
			//Final menu
			
		scanf("%d" , &opcao);	//Armazenando escolha usuario
	
		system("cls");	//Limpeza "chat"
			
	switch(opcao) 	//Inicio feedback de seleção
						
	{
	case 1:
		cadastro(); 	//chamada de funções
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
		printf("Essa opção não está disponivel\n");
			system("pause");
	break;
					//Fim feedback de seleção
					
	}
	
	}

}
