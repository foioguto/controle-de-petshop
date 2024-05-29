#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_CLIENTS 100
#define CLIENT_FILE "cliente.txt"
#define MAX_PRODUCTS 100
#define PRODUCT_FILE "produto.txt"
#define MAX_CARDS 100
#define CARD_FILE "cartao.txt"
#define MAX_EMPS 100
#define EMPS_FILE "funcionarios.txt"

typedef struct {
    int id;
    char name[30];
    int age;
} client;

typedef struct {
    float price;
    char name[30];
    int id;
} product;

typedef struct {
    int id;
    char function[10]; // debit or credit
    int number;
    int expireDate;
    int securityCode;
} card;

typedef struct {
    int id;
    char name[30];
    int age;
} emp;

client clients[MAX_CLIENTS];
product products[MAX_PRODUCTS];
card cards[MAX_CARDS];
emp emps[MAX_EMPS];

int OpMenu, OpCadastro, OpImpressao;
int numberClients = 0;
int numberProducts = 0;
int numberCards = 0;
int numberEmps = 0;

void saveClient() {
    FILE *fClient = fopen(CLIENT_FILE, "w");
    if (fClient == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(fClient, "%d\n", numberClients);
    int i;
    for (i = 0; i < numberClients; i++) {
        fprintf(fClient, "%d %s %d\n", clients[i].id, clients[i].name, clients[i].age);
    }
    fclose(fClient);
    printf("Dados de clientes salvos com sucesso!\n");
}

void loadClient() {
    FILE *fClient = fopen(CLIENT_FILE, "r");
    if (fClient == NULL) {
        printf("Dado não encontrado.\n");
        return;
    }
    fscanf(fClient, "%d", &numberClients);
    int i;
    for (i = 0; i < numberClients; i++) {
        fscanf(fClient, "%d %s %d", &clients[i].id, clients[i].name, &clients[i].age);
    }
    fclose(fClient);
    printf("Dados do cliente carregados com sucesso!\n");
}

void addClient() {
    if (numberClients >= MAX_CLIENTS) {
        printf("Limite de dados atingido.\n");
        return;
    }
    client newClient;
    newClient.id = numberClients + 1;
    printf("Digite o nome do cliente: ");
    scanf("%s", newClient.name);
    printf("Digite a idade do cliente: ");
    scanf("%d", &newClient.age);
    clients[numberClients] = newClient;
    numberClients++;
    printf("Cliente adicionado com sucesso\n");
    saveClient();
}

void deleteClient() {
    int id;
    printf("Digite o ID do cliente a ser excluído: ");
    scanf("%d", &id);
    int found = 0;
    int i, j;
    for (i = 0; i < numberClients; i++) {
        if (clients[i].id == id) {
            found = 1;
            for (j = i; j < numberClients - 1; j++) {
                clients[j] = clients[j + 1];
            }
            numberClients--;
            printf("Cliente excluído com sucesso!\n");
            saveClient();
            break;
        }
    }
    if (!found) {
        printf("Cliente com ID %d não encontrado.\n", id);
    }
}

void viewClient() {
    if (numberClients == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }
    int i;
    for (i = 0; i < numberClients; i++) {
        printf("ID: %d, Nome: %s, Idade: %d\n", clients[i].id, clients[i].name, clients[i].age);
    }
}

void saveProduct() {
    FILE *fProduct = fopen(PRODUCT_FILE, "w");
    if (fProduct == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(fProduct, "%d\n", numberProducts);
    int i;
    for (i = 0; i < numberProducts; i++) {
        fprintf(fProduct, "%d %s %f\n", products[i].id, products[i].name, products[i].price);
    }
    fclose(fProduct);
    printf("Dados de produtos salvos com sucesso!\n");
}

void loadProduct() {
    FILE *fProduct = fopen(PRODUCT_FILE, "r");
    if (fProduct == NULL) {
        printf("Nenhum dado encontrado.\n");
        return;
    }
    fscanf(fProduct, "%d", &numberProducts);
    int i;
    for (i = 0; i < numberProducts; i++) {
        fscanf(fProduct, "%d %s %f", &products[i].id, products[i].name, &products[i].price);
    }
    fclose(fProduct);
    printf("Dados de produtos carregados com sucesso!\n");
}

void addProduct() {
    if (numberProducts >= MAX_PRODUCTS) {
        printf("Limite de registros atingido.\n");
        return;
    }
    product newProduct;
    newProduct.id = numberProducts + 1;
    printf("Digite o nome do produto: ");
    scanf("%s", newProduct.name);
    printf("Digite o valor do produto: ");
    scanf("%f", &newProduct.price);
    products[numberProducts] = newProduct;
    numberProducts++;
    printf("Produto adicionado com sucesso!\n");
    saveProduct();
}

void deleteProduct() {
    int id;
    printf("Digite o ID do produto a ser excluído: ");
    scanf("%d", &id);
    int found = 0;
    int i, j;
    for (i = 0; i < numberProducts; i++) {
        if (products[i].id == id) {
            found = 1;
            for (j = i; j < numberProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            numberProducts--;
            printf("Produto excluído com sucesso!\n");
            saveProduct();
            break;
        }
    }
    if (!found) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

void viewProduct() {
    if (numberProducts == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }
    int i;
    for (i = 0; i < numberProducts; i++) {
        printf("ID: %d, Nome: %s, Preço: %.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

void saveCard() {
    FILE *fCard = fopen(CARD_FILE, "w");
    if (fCard == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(fCard, "%d\n", numberCards);
    int i;
    for (i = 0; i < numberCards; i++) {
        fprintf(fCard, "%d %s %d %d %d\n", cards[i].id, cards[i].function, cards[i].number, cards[i].expireDate, cards[i].securityCode);
    }
    fclose(fCard);
    printf("Dados de cartões salvos com sucesso!\n");
}

void loadCard() {
    FILE *fCard = fopen(CARD_FILE, "r");
    if (fCard == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }
    fscanf(fCard, "%d", &numberCards);
    int i;
    for (i = 0; i < numberCards; i++) {
        fscanf(fCard, "%d %s %d %d %d", &cards[i].id, cards[i].function, &cards[i].number, &cards[i].expireDate, &cards[i].securityCode);
    }
    fclose(fCard);
    printf("Dados de cartões carregados com sucesso!\n");
}

void addCard() {
    if (numberCards >= MAX_CARDS) {
        printf("Limite de cartões atingido.\n");
        return;
    }
    card newCard;
    newCard.id = numberCards + 1;
    printf("Digite a função (crédito ou débito): ");
    scanf("%s", newCard.function);
    printf("Digite o número do cartão: ");
    scanf("%d", &newCard.number);
    printf("Digite a data de vencimento do cartão (mês/ano): ");
    scanf("%d", &newCard.expireDate);
    printf("Digite o código de segurança do cartão: ");
    scanf("%d", &newCard.securityCode);
    cards[numberCards] = newCard;
    numberCards++;
    printf("Cartão adicionado com sucesso!\n");
    saveCard();
}

void deleteCard() {
    int id;
    printf("Digite o ID do cartão a ser excluído: ");
    scanf("%d", &id);
    int found = 0;
    int i, j;
    for (i = 0; i < numberCards; i++) {
        if (cards[i].id == id) {
            found = 1;
            for (j = i; j < numberCards - 1; j++) {
                cards[j] = cards[j + 1];
            }
            numberCards--;
            printf("Cartão excluído com sucesso!\n");
            saveCard();
            break;
        }
    }
    if (!found) {
        printf("Cartão com ID %d não encontrado.\n", id);
    }
}

void viewCard() {
    if (numberCards == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }
    int i;
    for (i = 0; i < numberCards; i++) {
        printf("ID: %d, Função: %s, Número: %d, Data de Vencimento: %d, Código de Segurança: %d\n", cards[i].id, cards[i].function, cards[i].number, cards[i].expireDate, cards[i].securityCode);
    }
}

void saveEmployer() {
    FILE *fEmp = fopen(EMPS_FILE, "w");
    if (fEmp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(fEmp, "%d\n", numberEmps);
    int i;
    for (i = 0; i < numberEmps; i++) {
        fprintf(fEmp, "%d %s %d\n", emps[i].id, emps[i].name, emps[i].age);
    }
    fclose(fEmp);
    printf("Dados do funcionário salvos com sucesso!\n");
}

void loadEmployer() {
    FILE *fEmp = fopen(EMPS_FILE, "r");
    if (fEmp == NULL) {
        printf("Dado não encontrado.\n");
        return;
    }
    fscanf(fEmp, "%d", &numberEmps);
    int i;
    for (i = 0; i < numberEmps; i++) {
        fscanf(fEmp, "%d %s %d", &emps[i].id, emps[i].name, &emps[i].age);
    }
    fclose(fEmp);
    printf("Dados do funcionário carregados com sucesso!\n");
}

void addEmployer() {
    if (numberEmps >= MAX_EMPS) {
        printf("Limite de dados atingido.\n");
        return;
    }
    emp newEmp;
    newEmp.id = numberEmps + 1;
    printf("Digite o nome do funcionário: ");
    scanf("%s", newEmp.name);
    printf("Digite a idade do funcionário: ");
    scanf("%d", &newEmp.age);
    emps[numberEmps] = newEmp;
    numberEmps++;
    printf("Funcionário adicionado com sucesso\n");
    saveEmployer();
}

void deleteEmployer() {
    int id;
    printf("Digite o ID do funcionário a ser excluído: ");
    scanf("%d", &id);
    int found = 0;
    int i, j;
    for (i = 0; i < numberEmps; i++) {
        if (emps[i].id == id) {
            found = 1;
            for (j = i; j < numberEmps - 1; j++) {
                emps[j] = emps[j + 1];
            }
            numberEmps--;
            printf("Funcionário excluído com sucesso!\n");
            saveEmployer();
            break;
        }
    }
    if (!found) {
        printf("Funcionário com ID %d não encontrado.\n", id);
    }
}

void viewEmployer() {
    if (numberEmps == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }
    int i;
    for (i = 0; i < numberEmps; i++) {
        printf("ID: %d, Nome: %s, Idade: %d\n", emps[i].id, emps[i].name, emps[i].age);
    }
}

void Menu () { 

    printf("+=====================================+\n");
    printf("|   MENU GERAL DO CONTROLE DE VENDAS  |\n");
    printf("+-------------------------------------+\n");
    printf("|   1 - Cadastro    |   2 - Impressão |\n");
    printf("+-------------------------------------+\n");
    printf("|   3 - Pedidos     |   4 - Excluir   |\n");
    printf("+-------------------------------------+\n");
    printf("|               5 - SAIR              |\n");
    printf("+=====================================+\n");
    printf("Informe a operção desejada: \n");
    scanf("%d", &OpMenu);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    while (1) {
        Menu();
        switch (OpMenu) {
            case 1:
            printf("+====================================+\n");
            printf("|          MENU DE CADASTRO          |\n");
            printf("+------------------------------------+\n");
            printf("|   1 - CLIENTE    |  2 - PRODUTO    |\n");
            printf("+------------------------------------+\n");
            printf("|   3 - CARTÃO     |  4 - funcionário|\n"); 
            printf("+------------------------------------+\n");
            printf("|     5 - RETORNAR AO MENU GERAL     |\n");
            printf("+====================================+\n");
            printf("Informe a operação desejada: \n");
            scanf("%d", &OpCadastro);
            switch (OpCadastro) {
                 case 1:
                   addClient();
                   system("pause");
                   Menu();
                  break;
                 case 2:
                   addProduct();
                   system("pause");
                   Menu();
                  break;
                 case 3:
                   addCard();
                   system("pause");
                   Menu();
                  break;
                 case 4:
                   addEmployer();
                   system("pause");
                   Menu();
                  break;
                 case 5:
                   Menu();
                  break;
            default:
                 printf("Opção inválida. Tente novamente.\n");
                 break;
            }
            case 2:
            printf("+====================================+\n");
            printf("|         MENU DE IMPRESSÃO          |\n");
            printf("+------------------------------------+\n");
            printf("|   1 - CLIENTE    |  2 - PRODUTO    |\n");
            printf("+------------------------------------+\n");
            printf("|   3 - PEDIDO     |  4 - Pagamento  |\n"); 
            printf("+------------------------------------+\n");
            printf("|     5 - RETORNAR AO MENU GERAL     |\n");
            printf("+====================================+\n");
            printf("Informe a operação desejada: \n");
            scanf("%d", &OpImpressao);
            switch (OpImpressao) {
                 case 1:
                   viewClient();
                   system("pause");
                   Menu();
                  break;
                 case 2:
                   viewProduct();
                   system("pause");
                   Menu();
                  break;
                 case 3:
                   viewCard();
                   system("pause");
                   Menu();
                  break;
                 case 4:
                   viewEmployer();
                   system("pause");
                   Menu();
                  break;
                 case 5:
                   Menu();
                  break;
            default:
                 printf("Opção inválida. Tente novamente.\n");
                 break;
            }
            
            case 5:
                printf("Saindo...");
                exit(0);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
