#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#define max_clients 100
#define file_name "cliente.txt"

int Operator;

typedef struct {
  int id;
  char name[30];
  int age;
 } client;
// clients = array name//
client clients[max_clients];
//sm = SubMenu//
int numberClient = 0;

void saveClient() {
    int i;
    FILE *fClient = fopen(file_name, "w");
    
     fprintf(fClient, "%d\n", numberClient);
  for(i=0; i<numberClient; i++) {
    fprintf(fClient, "%d %s %d", clients[i].id, clients[i].name, clients[i].age);
  }
    fclose(fClient);
    printf("Dados salvos com sucesso!\n");
    system("cls");
}

void loadClient() {
   int i;
   FILE *fClient = fopen(file_name, "r");
   if(fClient == NULL) {
    printf("Dado não encontrado.\n");
    return;
   }
   fscanf(fClient, "%d", &numberClient);
    for(i = 0; i < numberClient; i++) {
        fscanf(fClient, "%d %s %d", &clients[i].id, clients[i].name, &clients[i].age);
   fclose(fClient);
   printf("Dados carregados com sucesso!\n");
   system("cls");
} 
}

void addClient() {
    client newClient;

    if(numberClient >= max_clients) {
        printf("Limite de dados atingido.\n");
        return;
    }
    newClient.id = numberClient + 1;
    printf("Digite o nome do cliente: \n");
    scanf("%s", &newClient.name[30]);
    printf("Digite a idade do cliente: \n");
    scanf("%d", &newClient.age);
    clients[numberClient] = newClient;
    numberClient ++;
    printf("cliente adicionado com sucesso\n");
    system("cls");
}
 
void deleteClient() {
    int id;
    int i, j;
    int found = 0;

    if(numberClient == 0) {
        printf("Registro vazio.\n");
        return;
    }
    printf("Digite o ID do cliente a ser excluído: ");
    scanf("%d", &id);
    for(i=0; i<numberClient; i++) {
     if(clients[i].id == id) {
          found = 1;
          for(j=i; j<numberClient -1; j++) {
            clients[j] = clients[j + 1];
          }
          numberClient--;
          printf("Cliente excluído com sucesso!\n");
          system("pause");
       }
    }
  if(!found) {
    printf("Cliente com ID %d não encontrado.\n", id);
  }
}

void viewClient() {
    int i;

    if(numberClient == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }
  for(i=0; i<numberClient; i++) {
    printf("ID; %d, Nome: %s, Idade: %d", clients[i].id, clients[i].name, clients[i].age);
    system("cls");
  }
}
#define max_products 100
#define product_file "produto.txt"

typedef struct {
  float price;
  char name[30];
  int id;
} product;

product products[max_products];
int numberProducts = 0;

void saveProduct() {
  int i;
  FILE *fProduct = fopen(product_file, "w"); 
  
  fprintf(fProduct, "%d\n", numberProducts);
  for(i=0; i<numberProducts; i++) {
    fprintf(fProduct, "%d %s %f", products[i].id, products[i].name, products[i].price);
  }
  fclose(fProduct);
  return;
  }

void loadProduct() {
    int i;
    FILE *fProduct = fopen(product_file, "r");
    if(fProduct == NULL) {
        printf("Nenhum dado encontrado.\n");
        return;
    }
    fscanf(fProduct, "%d", &numberProducts);
    for(i=0; i<numberProducts; i++) {
      fscanf(fProduct, "%d %s %lf", products[i].id, products[i].name, products[i].price);
    }
    fclose(fProduct);
    return;
 }

void addProduct() {
    product newProduct;

    if(numberProducts >= max_products) {
        printf("Limite de registros atingido.\n");
        return;
    }
    newProduct.id = numberProducts + 1;
    printf("Digite o nome do produto: ");
    scanf("%s", &newProduct.name[30]);
    printf("Digite o valor do produto: ");
    scanf("%2f", &newProduct.price);
    products[numberProducts] = newProduct;
    numberProducts++;
    printf("Produto adicionado com sucesso!\n");
    system("cls");
}

void deletProduct() {
     int id;
    int i, j;
    int found = 0;

    if (numberProducts == 0) {
        printf("Nenhum produto registrado.\n");
        return;
    }
    printf("Digite o ID do produto a ser excluído: ");
    scanf("%d", &id);
    for (i = 0; i < numberProducts; i++) {
        if (products[i].id == id) {
            found = 1;
            for (j = i; j < numberProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            numberProducts--;
            printf("Produto excluído com sucesso!\n");
            system("pause");
        }
    }
    if (!found) {
        printf("Produto com ID %d não encontrado.\n", id);
    } 
}

void viewProduct() {
   int i;

    if(numberProducts == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }
  for(i=0; i<numberProducts; i++); {
    printf("ID; %d, Nome: %s, Preço: %2f", products[i].id, products[i].name, products[i].price);
    system("cls");
  }  
}
#define max_cards 100
#define card_file "cartão.txt"

typedef struct {
  int id;
  char fuunction[10];//debit or credit//
  int number;
  int expireDate;
  int securityCode;
} card;

card cards[max_cards];
int numberCards = 0;

void saveCard() {
  int i;
  FILE *fCard = fopen(card_file, "w");
  
  fprintf(fCard, "%d\n", numberCards);
  for(i=0; i<numberCards; i++) {
    fprintf(fCard, "%d %s %d %d %d", cards[i].id, cards[i].fuunction, cards[i].number, cards[i].expireDate, cards[i].securityCode);
  }
  fclose(fCard);
  printf("Dados salvos com sucesso!\n");
  system("cls");
}

void loadCard() {
  int i;
  FILE *fCard = fopen(card_file, "r");
  if(fCard == NULL) {
    printf("Não foi possível abrir o arquivo.\n");
    return;
  }
  fscanf(fCard, "%d", &numberCards);
  for(i=0; i<numberCards; i++) {
    fscanf(fCard, "%d %s %d %d %d", &cards[i].id, cards[i].fuunction, &cards[i].number, &cards[i].expireDate, &cards[i].securityCode);
  }
  fclose(fCard);
  printf("Dados carregados com sucesso!\n");
  system("cls");
}

void addCard() {
  card newCard;

  if(numberCards >= max_cards) {
    printf("Limite de cartões atingido.\n");
    return;
  }
  newCard.id = numberCards + 1;
  printf("Digite a função(crédito ou débito): ");
  scanf("%s", &newCard.fuunction[10]);
  printf("Digite o número do cartão: ");
  scanf("%d", &newCard.number);
  printf("Digite a data de vencimento do cartão: ");
  scanf("%d", &newCard.expireDate);
  printf("Digite o código de segurança do cartão: ");
  scanf("%d", &newCard.securityCode);
  cards[numberCards] = newCard;
  numberCards++;
  printf("Cartão adicionado com sucesso!\n");
  system("cls");
}

void deleteCard() {
    int id;
    int i, j;
    int found = 0;

    if(numberCards == 0) {
      printf("Nenhum cartão cadastrado.\n");
      return;
    }
    printf("Digite o ID do cartão a ser excluído: ");
    scanf("%d", &id);
    for(i=0; i<numberCards; i++) {
      if(cards[i].id == id) {
        found = 1;
        for(j=i; j<numberCards; j++) {
          cards[j] = cards[j + 1];
        }
        numberCards--;
        printf("Cartão excluído com sucesso!\n");
        system("pause");
      }
    }
}

void viewCard() {
   int i;

    if (numberCards == 0) {
        printf("Nenhum cartão cadastrado.\n");
        return;
    }
    for (i = 0; i < numberCards; i++) {
        printf("ID: %d\nFunção: %s\nNúmero: %d\nValidade: %d\nCVV: %d", cards[i].id, cards[i].fuunction[10], cards[i].number, cards[i].expireDate, cards[i].securityCode);
    }
}

#define max_emps 100
#define emps_file "funcionários.txt"

typedef struct {
  int id;
  char name[30];
  int age;
} emp;

emp emps[max_emps];
int numberEmps = 0;

void saveEmployer() {
   int i;
   FILE *fEmps = fopen(emps_file, "w");
   
   fprintf(fEmps, "%d\n", numberEmps);
    for(i = 0; i < numberEmps; i++) {
        fprintf(fEmps, "%d %s %d\n", emps[i].id, emps[i].name, emps[i].age);
    }
   fclose(fEmps);
   printf("Dados salvos com sucesso!\n");
   system("cls");
}

void loadEmployer() {
    int i;
    FILE *fEmps = fopen(emps_file, "r");
    if (fEmps == NULL) {
        printf("Nenhum dado registrado.\n");
        return;
    }
    fscanf(fEmps, "%d", &numberEmps);
    for(i = 0; i < numberEmps; i++) {
        fscanf(fEmps, "%d %s %d", &emps[i].id, emps[i].name, &emps[i].age);
    }
    fclose(fEmps);
    printf("Dados carregados com sucesso.\n");
    system("cls");
}

void addEmployer() {
    emp newEmp;

    if(numberEmps >= max_emps) {
        printf("Limite de dados atingido.\n");
        return;
    }
    newEmp.id = numberEmps + 1;
    printf("Digite o nome do funcionário: \n");
    scanf("%s", &newEmp.name[30]);
    printf("Digite a idade do funcionário: \n");
    scanf("%d", &newEmp.age);
    emps[numberEmps] = newEmp;
    numberEmps ++;
    printf("Funcionário adicionado com sucesso\n");
    system("cls");
}

void deleteEmployer() {
    int id;
    int i, j;
    int found = 0;

    if(numberEmps == 0) {
        printf("Registro vazio.\n");
        return;
    }
    printf("Digite o ID do funcionário a ser excluído: ");
    scanf("%d", &id);
    for(i=0; i<numberEmps; i++) {
     if(emps[i].id == id) {
          found = 1;
          for(j=i; j<numberEmps -1; j++) {
            emps[j] = emps[j + 1];
          }
          numberEmps--;
          printf("Funcionário excluído com sucesso!\n");
          system("pause");
       }
    }
  if(!found) {
    printf("Funcionário com ID %d não encontrado.\n", id);
  }
}

void viewEmployer() {
    int i;

    if(numberEmps == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }
  for(i=0; i<numberEmps; i++) {
    printf("ID; %d, Nome: %s, Idade: %d", emps[i].id, emps[i].name, emps[i].age);
    system("cls");
  }
}

void MenuPrincipal () { 

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
    scanf("%d", &Operator);
}

void SubMenuCadastro () {
  
    printf("+====================================+\n");
    printf("|          MENU DE CADASTRO          |\n");
    printf("+------------------------------------+\n");
    printf("|   1 - CLIENTE    |  2 - PRODUTO    |\n");
    printf("+------------------------------------+\n");
    printf("|  3 - PAGAMENTO   |  4 - funcionário|\n"); 
    printf("+------------------------------------+\n");
    printf("|     5 - RETORNAR AO MENU GERAL     |\n");
    printf("+====================================+\n");
    printf("Informe a operação desejada: \n");
    scanf("%d", &Operator);
} 

void SubMenuImpressao () {
    
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
    scanf("%d", &Operator);
}

int main() {
  setlocale(LC_ALL, "");

while(1) {
MenuPrincipal();
switch(Operator) {
  case 1:
  SubMenuCadastro();
  switch(Operator) {
    case 1:
        addClient();
        saveClient();
        break;
    case 2:
        addProduct();
        break;
    case 3:
        addCard();
        break;
    case 4:
        addEmployer();
        break;
    case 5:
        MenuPrincipal();
        break;
    default:
        printf("Opção inválida.\n");

  }
  case 2:
  SubMenuImpressao();
  }
 }
}