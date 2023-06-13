
#include<stdio.h>
#include<stdlib.h>
#define QTD_CONTAS 100

struct CONTA{
    int CORRENTE, DATA_ABERTURA, AGENCIA, FLAG;
    char CORRENTISTA[50], CIDADE[20], ESTADO[3];
    float SALDO;
} CONTA[QTD_CONTAS];

void inicializaFlags(){
    int i = 0;
    for(i = 0; i < QTD_CONTAS; i++){
        CONTA[i].FLAG = 0;
    }
}

int chamarMenu(){
    int OPCAO, TENTATIVAS;
    OPCAO = TENTATIVAS = 0;
    printf("Digite uma opção do menu: \n");
    do{
        if(TENTATIVAS != 0 && (OPCAO <= 0 || OPCAO > 4)){
            printf("Opção inválida. Digite novamente:\n");
        }
        printf("Menu\n");
        printf("\t 1 - Inclusão\n");
        printf("\t 2 - Alteração\n");
        printf("\t 3 - Exclusão\n");
        printf("\t 4 - Encerrar programa\n");
        scanf("%d", &OPCAO);
        TENTATIVAS++;
    }while(TENTATIVAS != 0 && (OPCAO <= 0 || OPCAO > 4));
    return OPCAO;
}

void validaNome(int ID)
{
  char NOME[50];
  do
  {
    scanf("%s", &NOME[0]);
    if (strlen(NOME) == 0)
    {
      printf("O nome não pode ser vazio.\n");
      printf("Digite novamente: \n");
    }
    else if (strlen(NOME) > 49)
    {
      printf("Nome maior que o tamanho máximo permitido (%d)\n", 50);
      printf("Digite novamente: \n");
    }
    else if (strlen(NOME) < 2)
    {
      printf("Digite ao menos 2 caracteres para o nome\n");
      printf("Digite novamente: \n");
    }
    else
    {
      strcpy(CONTA[ID].CORRENTISTA, NOME);
    }
  } while (strlen(NOME) <= 2 || strlen(NOME) > 49);
  while (getchar() != '\n')
  {
  };
}

void validaDataAbertura(int ID){
    int DATA_ABERTURA, VALIDADO, DIA, MES, ANO;
    VALIDADO = 1;
    do{
        if(VALIDADO == 0){
            printf("Digite novamente a data da abertura(DDMMAAAA): \n");
        }
        scanf("%d", &DATA_ABERTURA);
        DIA = (DATA_ABERTURA/1000000);
        MES = ((DATA_ABERTURA/10000)%100);
        ANO = DATA_ABERTURA%10000;
        if(DIA <= 0 || DIA > 31){
            printf("Dia informado inválido\n");
            VALIDADO = 0;
        } else if(MES <= 0 || MES > 12){
            printf("Mes informado inválido\n");
            VALIDADO = 0;
        } else if(ANO <= 1970 || ANO > 2050){
            printf("Ano informado inválido informado inválido\n");
            VALIDADO = 0;
        } else {
            VALIDADO = 1;
        }
    } while(VALIDADO != 1);
    CONTA[ID].DATA_ABERTURA = DATA_ABERTURA;
}

void validaCidade(int ID)
{
  char CIDADE[20];
  do
  {
    scanf("%s", &CIDADE[0]);
    if (strlen(CIDADE) == 0)
    {
      printf("O nome da cidade não pode ser vazio.\n");
      printf("Digite novamente: \n");
    }
    else if (strlen(CIDADE) > 19)
    {
      printf("Nome da cidade maior que o tamanho máximo permitido (%d)\n", 20);
      printf("Digite novamente: \n");
    }
    else if (strlen(CIDADE) < 2)
    {
      printf("Digite ao menos 2 caracteres para o nome da cidade\n");
      printf("Digite novamente: \n");
    }
    else
    {
      strcpy(CONTA[ID].CIDADE, CIDADE);
    }
  } while (strlen(CIDADE) <= 2 || strlen(CIDADE) > 19);
  while (getchar() != '\n')
  {
  };
}

void validaEstado(int ID)
{
  char ESTADO[3];
  do
  {
    scanf("%s", &ESTADO[0]);
    if (strlen(ESTADO) == 0)
    {
      printf("O estado não pode ser vazio.\n");
      printf("Digite novamente: \n");
    }
    else if (strlen(ESTADO) > 2)
    {
      printf("Sigla do estado maior que o tamanho máximo permitido (%d)\n", 2);
      printf("Digite novamente: \n");
    }
    else if (strlen(ESTADO) < 2)
    {
      printf("Digite ao menos 2 caracteres para o estado\n");
      printf("Digite novamente: \n");
    }
    else
    {
      strcpy(CONTA[ID].ESTADO, ESTADO);
    }
  } while (strlen(ESTADO) != 2);
  while (getchar() != '\n')
  {
  };
}

void incluirConta(){
    int i, FLAG;
    i = FLAG = 0;
    for (i = 0; i < QTD_CONTAS; i++)
    {
        if (CONTA[i].FLAG == 0)
        {
            break;
        }
    }
    printf("Digite o número da conta corrente: \n");
    scanf("%d", &CONTA[i].CORRENTE);
    printf("Digite o nome do correntista: \n");
    validaNome(i);
    printf("Digite a data de abertura. Digitar somente números no padrão DDMMAAAA\n");
    validaDataAbertura(i);
    printf("Digite a agencia: \n");
    scanf("%d", &CONTA[i].AGENCIA);
    printf("Digite a cidade: \n");
    validaCidade(i);
    printf("Digite a sigla do estado: \n");
    validaEstado(i);
    printf("Digite o saldo da conta: \n");
    scanf("%f", &CONTA[i].SALDO);
}

int buscarContaCorrente(int CORRENTE){
    int ID, CORRENTE;
    ID = 0;
    for(ID; ID < QTD_CONTAS; ID++){
        if(CONTA[ID].FLAG != 0 && CONTA[ID].CORRENTE == CORRENTE){
            return ID;
        }
    }
    printf("Nenhuma conta encontrada.\n");

    return -1;
}

void alterarConta(){
    int ID, CORRENTE;
    ID = CORRENTE = 0;
    printf("Digite a conta que deseja alterar (código da conta corrente):\n");
    ID = buscarContaCorrente(CORRENTE);
}

void excluirConta(){

}

int main(){
    inicializaFlags();
    do{
        switch(chamarMenu()){
        case 1:
            incluirConta();
            break;
        case 2:
            alterarConta();
            break;
        case 3:
            excluirConta();
            break;
        case 4:
            printf("Programa encerrado pelo usuário.\n");
            return;
        default:
            break;
        }
    }while(1);

    system("pause");
    return 0;
}
