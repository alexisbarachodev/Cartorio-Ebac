#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por criar as strings

int registrar() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis/string
	
	printf("\nDigite o CPF a ser cadastrado: "); //Coleta de informa��es do usu�rio = Solicita o CPF do usu�rio
	scanf("%s", cpf); //L� o CPF fornecido pelo usu�rio
	
	strcpy(arquivo, cpf); //strcpy = Respons�vel por copiar os valores das strings //Copia o CPF para a vari�vel 'arquivo'
	
	FILE *file; //Cria��o do arquivo
	file = fopen(arquivo, "w"); //Cria��o do arquivo com o nome do CPF e abre para escrita
	fprintf(file, "CPF: "); //Mostra o CPF em uma �nica linha
	fprintf(file, cpf); //Salva o valor da vari�vel CPF no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para n�a sobrepor informa��es
	fprintf(file, ", \nNOME: "); //Adiciona uma v�rgula no arquivo e mostra o Nome em uma �nica linha
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coleta de informa��es do usu�rio = Solicita o nome do usu�rio
	scanf("%s", nome); //L� o nome fornecido pelo usu�rio
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para n�a sobrepor informa��es
	fprintf(file, nome); //Escreve o nome do arquivo = 'Nome'
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para n�a sobrepor informa��es
	fprintf(file, ", \nSOBRENOME: "); //Adiciona uma v�rgula no arquivo e mostra o Sobrenome em uma �nica linha
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coleta de informa��es do usu�rio = Solicita o sobrenome do usu�rio
	scanf("%s", sobrenome); //L� o sobrenome fornecido pelo usu�rio
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para n�a sobrepor informa��es
	fprintf(file, sobrenome); //Escreve o nome do arquivo = 'Sobrenome'
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para n�a sobrepor informa��es
	fprintf(file, ", \nCARGO: "); //Adiciona uma v�rgula no arquivo e mostra o Cargo em uma �nica linha
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coleta de informa��es do usu�rio = Solicita o cargo do usu�rio
	scanf("%s", cargo); //L� o cargo fornecido pelo usu�rio
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para n�a sobrepor informa��es
	fprintf(file, cargo); //Escreve o nome do arquivo = 'Cargo'
	fprintf(file, ".\n\n"); //Fun��o somente para pular linhas depois da informa��a 'Cargo'
	fclose(file); //Fecha o arquivo
	
	printf("\nUsu�rio cadastrado com sucesso!\n\n"); //Mensagem que aparecer� quando o usu�rio for cadastrado. Informa que o usu�rio foi cadastrado
	system("pause"); //Pausa o programa para o usu�rio ver a mensagem
}

int consultar() //Fun��o respons�vel por consultar os usu�rios
{
	setlocale(LC_ALL, "Portuguese_Brazil"); //Defini��o da linguagem para PT-BR
	
	//In�cio da cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o de vari�veis/strings
	
	printf("\nDigite o CPF a ser consultado: "); //Coleta de informa��es do usu�rio = Solicita o CPF do usu�rio
	scanf("%s", cpf); //L� o CPF fornecido pelo usu�rio e armazena na string 'cpf'
	
	FILE *file; //Procura o arquivo na biblioteca
	file = fopen(cpf, "r"); //Abre o arquivo com o nome do CPF para leitura ('r' = read = ler)
	
	if(file == NULL) //Verifica se o arquivo foi encontrado ou n�o
	{
		printf("\nN�o foi poss�vel localizar o arquivo! \n"); //Mensagem que aparecer� para o usu�rio caso ele forne�a uma inform��o equivocada
		return 1; //Retorna 1 para indicar que houve um erro
	}
	
	printf("\nEssas s�o as informa��es do usu�rio:\n\n"); //Mensagem que aparecer� para o usu�rio ao consultar os dados
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto (while) houver linhas de arquivo para ler do arquivo (diferente do NULL)
	{
		printf("%s", conteudo); //Imprime a linha lida do arquivo
	}
	
	fclose(file); //Fecha o arquivo
	system("pause"); //Pausa para o usu�rio verificar as informa��es
	return 0; //Retorna 0 para indicar que a fun��o foi executada com sucesso
}

int deletar() //Fun��o respons�vel por deletar o usu�rio
{
	setlocale(LC_ALL, "Portuguese_Brazil"); //Defini��o da linguagem para PT-BR
	
	char cpf[40]; //Cria��o da vari�vel CPF
	
	printf("\nDigite o CPF do usu�rio a ser deletado: "); //Coleta de informa��es do usu�rio = Solicita o CPF do usu�rio
	scanf("%s", cpf); //L� o CPF fornecido pelo usu�rio e armazena na string 'cpf'
	
 	if (remove(cpf) == 0) //Tenta remover o arquivo
    {
        printf("\nUsu�rio deletado com sucesso!\n\n"); //Mensagem de sucesso caso o usu�rio seja deletado
    }
    else
    {
        printf("\n\nO usu�rio n�o se encontra no sistema da EBAC! \n\n"); //Mensagem de erro caso o CPF informado n�o esteja presente no sistema
    }
	
	system("pause"); //Pausa para o usu�rio verificar as informa��es
	return 0; //Retorna 0 para indicar que a fun��o foi executada com sucesso
}

int main() //Fun��o principal do c�digo
{
    //In�cio da cria��o de vari�veis
	int opcao = 0;
    int laco = 1;
    //Fim da cria��o de vari�veis
    
    //Cria��o de Login e Senha antes de acessar o sistema
    char login[30]; //string de vari�vel 'login'
    char senha[30]; //string de vari�vel 'senha'
    char login_correto[] = "administrador"; //Declara��o que o login correto a ser usado � 'administrador'
    char senha_correta[] = "ebaccartorio"; //Declara��o que a senha correta a ser usada � 'ebaccartorio'
    
    int autenticado = 0; //Vari�vel para armazenar o estado de autentica��o
    
    while (!autenticado) //Loop at� que o usu�rio seja autenticado
    {
    	printf("### Sistema de Login ###\n\n"); //Caixa de Login e Senha
    	printf("Digite o login: "); //Espa�o para o usu�rio fornecer o login
    	scanf("%s", login); //L� o login fornecido pelo usu�rio
    	printf("Digite a senha: "); //Espa�o para o usu�rio fornecer a senha
    	scanf("%s", senha); //L� a senha fornecida pelo usu�rio
    	
    	if (strcmp(login, login_correto) == 0 && strcmp(senha, senha_correta) == 0) //Compara os valores fornecidos pelo usu�rio com os dados corretos de login e senha. 
	//Caso os dados fornecidos pelo usu�rio sejam diferentes do correto, a condi��o para a fun��o ser� verdadeiras
    	{
    		autenticado = 1; //Define o estado de autentica��o como verdadeiro
		}
		else
		{
			printf("\nLogin ou Senha incorretos! Tente novamente.\n\n"); //Mensagem que aparecer� caso o usu�rio forne�a login e senha incorretos
		}
	}
    
    for (laco = 1; laco == 1;) 
	{
        system("cls"); //Limpa a tela
        
        setlocale(LC_ALL, "Portuguese_Brazil"); //Defini��o da linguagem para PT-BR

        printf("### Cart�rio EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar Nome\n");
        printf("\t2 - Consultar Nome\n");
        printf("\t3 - Deletar Nome\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: ");

        scanf("%d", &opcao); //L� a op��o escolhida pelo usu�rio

        system("cls"); //Limpa a tela

        //Caixa de confirma��o
        char confirmacao;
        
        printf("Deseja realizar esta tarefa? (S/N): "); //Solicita a confirma��a de que o usu�rio quer realmente realizar a tarefa escolhida
        scanf(" %c", &confirmacao); //L� a confirma��o do usu�rio

        if (confirmacao == 'S' || confirmacao == 's') //Caso o usu�rio digite o caracter 's' (mai�sculo ou min�culo), essa mensagem ir� aparecer
		{
            switch (opcao) //Executa a op��o selecionada
			{
                case 1:
                	registrar(); //Chamada da fun��o registrar
                	break;
                case 2:
                    consultar(); //Chamada da fun��o consultar 
                    break;
                case 3:
                    deletar(); //Chamada da fun��o deletar
                    break;
                case 4:
                	printf("\nObrigado por utilizar o sistema!\n"); //Chamada da op��o para sair do sistema
                	return 0;
                	break;
                default:
                    printf("Essa op��o n�o est� dispon�vel.\n\n"); //Informa que a op��o n�o est� dispon�vel
                    system("pause"); //Pausa no sistema para o usu�rio verificar as informa��es
                    break;
            }
        } 
		else //Caso ele digite qualquer coisa que n�o for o caracter 's', essa mensagem ir� aparecer
		{
            printf("\nOpera��o cancelada.\n\n"); //Informa que a opera��o foi cancelada
            system("pause"); //Pausa no sistema para o usu�rio ler a mensagem
        }
    }
    return 0; //Retorna 0 para indicar que a fun��o foi executada com sucesso
}
