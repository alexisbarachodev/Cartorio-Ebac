#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por criar as strings

int registrar() //Função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis/string
	
	printf("\nDigite o CPF a ser cadastrado: "); //Coleta de informações do usuário = Solicita o CPF do usuário
	scanf("%s", cpf); //Lê o CPF fornecido pelo usuário
	
	strcpy(arquivo, cpf); //strcpy = Responsável por copiar os valores das strings //Copia o CPF para a variável 'arquivo'
	
	FILE *file; //Criação do arquivo
	file = fopen(arquivo, "w"); //Criação do arquivo com o nome do CPF e abre para escrita
	fprintf(file, "CPF: "); //Mostra o CPF em uma única linha
	fprintf(file, cpf); //Salva o valor da variável CPF no arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para nõa sobrepor informações
	fprintf(file, ", \nNOME: "); //Adiciona uma vírgula no arquivo e mostra o Nome em uma única linha
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coleta de informações do usuário = Solicita o nome do usuário
	scanf("%s", nome); //Lê o nome fornecido pelo usuário
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para nõa sobrepor informações
	fprintf(file, nome); //Escreve o nome do arquivo = 'Nome'
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para nõa sobrepor informações
	fprintf(file, ", \nSOBRENOME: "); //Adiciona uma vírgula no arquivo e mostra o Sobrenome em uma única linha
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coleta de informações do usuário = Solicita o sobrenome do usuário
	scanf("%s", sobrenome); //Lê o sobrenome fornecido pelo usuário
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para nõa sobrepor informações
	fprintf(file, sobrenome); //Escreve o nome do arquivo = 'Sobrenome'
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para nõa sobrepor informações
	fprintf(file, ", \nCARGO: "); //Adiciona uma vírgula no arquivo e mostra o Cargo em uma única linha
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coleta de informações do usuário = Solicita o cargo do usuário
	scanf("%s", cargo); //Lê o cargo fornecido pelo usuário
	
	file = fopen(arquivo, "a"); //Atualiza o arquivo para nõa sobrepor informações
	fprintf(file, cargo); //Escreve o nome do arquivo = 'Cargo'
	fprintf(file, ".\n\n"); //Função somente para pular linhas depois da informaçõa 'Cargo'
	fclose(file); //Fecha o arquivo
	
	printf("\nUsuário cadastrado com sucesso!\n\n"); //Mensagem que aparecerá quando o usuário for cadastrado. Informa que o usuário foi cadastrado
	system("pause"); //Pausa o programa para o usuário ver a mensagem
}

int consultar() //Função responsável por consultar os usuários
{
	setlocale(LC_ALL, "Portuguese_Brazil"); //Definição da linguagem para PT-BR
	
	//Início da criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//Fim da criação de variáveis/strings
	
	printf("\nDigite o CPF a ser consultado: "); //Coleta de informações do usuário = Solicita o CPF do usuário
	scanf("%s", cpf); //Lê o CPF fornecido pelo usuário e armazena na string 'cpf'
	
	FILE *file; //Procura o arquivo na biblioteca
	file = fopen(cpf, "r"); //Abre o arquivo com o nome do CPF para leitura ('r' = read = ler)
	
	if(file == NULL) //Verifica se o arquivo foi encontrado ou não
	{
		printf("\nNão foi possível localizar o arquivo! \n"); //Mensagem que aparecerá para o usuário caso ele forneça uma informção equivocada
		return 1; //Retorna 1 para indicar que houve um erro
	}
	
	printf("\nEssas são as informações do usuário:\n\n"); //Mensagem que aparecerá para o usuário ao consultar os dados
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto (while) houver linhas de arquivo para ler do arquivo (diferente do NULL)
	{
		printf("%s", conteudo); //Imprime a linha lida do arquivo
	}
	
	fclose(file); //Fecha o arquivo
	system("pause"); //Pausa para o usuário verificar as informações
	return 0; //Retorna 0 para indicar que a função foi executada com sucesso
}

int deletar() //Função responsável por deletar o usuário
{
	setlocale(LC_ALL, "Portuguese_Brazil"); //Definição da linguagem para PT-BR
	
	char cpf[40]; //Criação da variável CPF
	
	printf("\nDigite o CPF do usuário a ser deletado: "); //Coleta de informações do usuário = Solicita o CPF do usuário
	scanf("%s", cpf); //Lê o CPF fornecido pelo usuário e armazena na string 'cpf'
	
 	if (remove(cpf) == 0) //Tenta remover o arquivo
    {
        printf("\nUsuário deletado com sucesso!\n\n"); //Mensagem de sucesso caso o usuário seja deletado
    }
    else
    {
        printf("\n\nO usuário não se encontra no sistema da EBAC! \n\n"); //Mensagem de erro caso o CPF informado não esteja presente no sistema
    }
	
	system("pause"); //Pausa para o usuário verificar as informações
	return 0; //Retorna 0 para indicar que a função foi executada com sucesso
}

int main() //Função principal do código
{
    //Início da criação de variáveis
	int opcao = 0;
    int laco = 1;
    //Fim da criação de variáveis
    
    //Criação de Login e Senha antes de acessar o sistema
    char login[30]; //string de variável 'login'
    char senha[30]; //string de variável 'senha'
    char login_correto[] = "administrador"; //Declaração que o login correto a ser usado é 'administrador'
    char senha_correta[] = "ebaccartorio"; //Declaraçõo que a senha correta a ser usada é 'ebaccartorio'
    
    int autenticado = 0; //Variável para armazenar o estado de autenticação
    
    while (!autenticado) //Loop até que o usuário seja autenticado
    {
    	printf("### Sistema de Login ###\n\n"); //Caixa de Login e Senha
    	printf("Digite o login: "); //Espaço para o usuário fornecer o login
    	scanf("%s", login); //Lê o login fornecido pelo usuário
    	printf("Digite a senha: "); //Espaço para o usuário fornecer a senha
    	scanf("%s", senha); //Lê a senha fornecida pelo usuário
    	
    	if (strcmp(login, login_correto) == 0 && strcmp(senha, senha_correta) == 0) //Compara os valores fornecidos pelo usuário com os dados corretos de login e senha. 
	//Caso os dados fornecidos pelo usuário sejam diferentes do correto, a condição para a função será verdadeiras
    	{
    		autenticado = 1; //Define o estado de autenticação como verdadeiro
		}
		else
		{
			printf("\nLogin ou Senha incorretos! Tente novamente.\n\n"); //Mensagem que aparecerá caso o usuário forneça login e senha incorretos
		}
	}
    
    for (laco = 1; laco == 1;) 
	{
        system("cls"); //Limpa a tela
        
        setlocale(LC_ALL, "Portuguese_Brazil"); //Definição da linguagem para PT-BR

        printf("### Cartório EBAC ###\n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar Nome\n");
        printf("\t2 - Consultar Nome\n");
        printf("\t3 - Deletar Nome\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: ");

        scanf("%d", &opcao); //Lê a opção escolhida pelo usuário

        system("cls"); //Limpa a tela

        //Caixa de confirmação
        char confirmacao;
        
        printf("Deseja realizar esta tarefa? (S/N): "); //Solicita a confirmaçõa de que o usuário quer realmente realizar a tarefa escolhida
        scanf(" %c", &confirmacao); //Lê a confirmação do usuário

        if (confirmacao == 'S' || confirmacao == 's') //Caso o usuário digite o caracter 's' (maiúsculo ou minúculo), essa mensagem irá aparecer
		{
            switch (opcao) //Executa a opção selecionada
			{
                case 1:
                	registrar(); //Chamada da função registrar
                	break;
                case 2:
                    consultar(); //Chamada da função consultar 
                    break;
                case 3:
                    deletar(); //Chamada da função deletar
                    break;
                case 4:
                	printf("\nObrigado por utilizar o sistema!\n"); //Chamada da opção para sair do sistema
                	return 0;
                	break;
                default:
                    printf("Essa opção não está disponível.\n\n"); //Informa que a opção não está disponível
                    system("pause"); //Pausa no sistema para o usuário verificar as informações
                    break;
            }
        } 
		else //Caso ele digite qualquer coisa que não for o caracter 's', essa mensagem irá aparecer
		{
            printf("\nOperação cancelada.\n\n"); //Informa que a operação foi cancelada
            system("pause"); //Pausa no sistema para o usuário ler a mensagem
        }
    }
    return 0; //Retorna 0 para indicar que a função foi executada com sucesso
}
