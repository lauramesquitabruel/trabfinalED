#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
   int dia;
   int mes;
   int ano;
} Data;

typedef struct fardo{
   char cultivar[20];
   char tipoDeFeno;
   int diametro;
} Fardo;

typedef struct producao{
   int codigo;
   Data dataProducao;
   Fardo tipoDeFardo;  
   int qtDeFardos;
   float duracao;
} Producao;

typedef struct TLista{
  Producao prod;
  struct TLista *prev, *next;
} Lista;

typedef struct tsentinela{
  Lista *head, *tail;
} Sentinela;

Sentinela incluirProducao(Sentinela s) {
    Fardo fardo; Data data; Producao producao; Lista *p, *aux;

    printf("Código desejado: ");
    scanf(" %d", &producao.codigo);

    for (aux = s.head; aux != NULL; aux = aux->next) {
        if (aux->prod.codigo == producao.codigo) {
            printf("Código de produção já existe. Insira um código único.\n");
            return s;
        }
    }

    getchar();

    printf("Data da produção (ex: 11 12 2023): ");
    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);

    printf("Cultivar: ");
    scanf("%s", fardo.cultivar);

    printf("Tipo de feno: ");
    scanf(" %c", &fardo.tipoDeFeno);

    printf("Diâmetro: ");
    scanf("%d", &fardo.diametro);

    printf("Quantidade de fardos: ");
    scanf(" %d", &producao.qtDeFardos);

    printf("Duração da produção: ");
    scanf(" %f", &producao.duracao);

    producao.dataProducao = data;
    producao.tipoDeFardo = fardo;

    p = (Lista *)malloc(sizeof(Lista));
    p->prod = producao;
    p->next = NULL;
    p->prev = NULL;
    if (s.head == NULL) {
        s.head = p;
        s.tail = p;
    } else {
        s.tail->next = p;
        p->prev = s.tail;
        s.tail = p;
    }
    return s;
}

void consultarData(Data d, Sentinela s) {
    Lista *aux;
    int encontrou = 0;

    for (aux = s.head; aux != NULL; aux = aux->next) {
        if (aux->prod.dataProducao.dia == d.dia && aux->prod.dataProducao.mes == d.mes && aux->prod.dataProducao.ano == d.ano) {
            if (!encontrou) {
                printf("%02d/%02d/%04d: %s - %c - %d \n", d.dia, d.mes, d.ano, aux->prod.tipoDeFardo.cultivar, aux->prod.tipoDeFardo.tipoDeFeno, aux->prod.qtDeFardos);
                encontrou = 1;
            } else {
                printf("\n%02d/%02d/%04d: %s - %c - %d \n", d.dia, d.mes, d.ano, aux->prod.tipoDeFardo.cultivar, aux->prod.tipoDeFardo.tipoDeFeno, aux->prod.qtDeFardos);
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum registro encontrado para a data: %02d/%02d/%04d\n", d.dia, d.mes, d.ano);
    }
}

void consultarCultivar(Sentinela s, char c[]) {
    Lista *aux;
    int encontrou = 0;

    for (aux = s.head; aux != NULL; aux = aux->next) {
        if (strcmp(aux->prod.tipoDeFardo.cultivar, c) == 0) {
            if (!encontrou) {
                printf("%s: %c - %d \n", aux->prod.tipoDeFardo.cultivar, aux->prod.tipoDeFardo.tipoDeFeno, aux->prod.qtDeFardos);
                encontrou = 1;
            } else {
                printf("\n%s: %c - %d \n", aux->prod.tipoDeFardo.cultivar, aux->prod.tipoDeFardo.tipoDeFeno, aux->prod.qtDeFardos);
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum registro encontrado para a cultivar: %s\n", c);
    }
}

void alterarProducao(Sentinela s, int codigo) {
    Lista *aux;

    for (aux = s.head; aux != NULL; aux = aux->next) {
        if (aux->prod.codigo == codigo) {
            printf("Registro encontrado. Escolha o campo que deseja alterar:\n");
            printf("1. Data da produção\n");
            printf("2. Cultivar\n");
            printf("3. Tipo de feno\n");
            printf("4. Diâmetro\n");
            printf("5. Código desejado\n");
            printf("6. Quantidade de fardos\n");
            printf("7. Duração da produção\n");
            printf("8. Cancelar\n");

            int op;
            scanf("%d", &op);

            switch (op) {
                case 1:
                    printf("Nova data da produção (ex: 11 12 2023): ");
                    scanf("%d %d %d", &aux->prod.dataProducao.dia, &aux->prod.dataProducao.mes, &aux->prod.dataProducao.ano);
                    break;
                case 2:
                    printf("Novo cultivar: ");
                    scanf("%s", aux->prod.tipoDeFardo.cultivar);
                    break;
                case 3:
                    printf("Novo tipo de feno: ");
                    scanf(" %c", &aux->prod.tipoDeFardo.tipoDeFeno);
                    break;
                case 4:
                    printf("Novo diâmetro: ");
                    scanf("%d", &aux->prod.tipoDeFardo.diametro);
                    break;
                case 5:
                    printf("Novo código desejado: ");
                    scanf(" %d", &aux->prod.codigo);
                    break;
                case 6:
                    printf("Nova quantidade de fardos: ");
                    scanf(" %d", &aux->prod.qtDeFardos);
                    break;
                case 7:
                    printf("Nova duração da produção: ");
                    scanf(" %f", &aux->prod.duracao);
                    break;
                case 8:
                    printf("Operação de alteração cancelada.\n");
                    return;
                default:
                    printf("Opção inválida.\n");
            }

            printf("Registro alterado com sucesso.\n");
            return;
        }
    }

    printf("Nenhum registro encontrado com o código %d.\n", codigo);
}

Sentinela excluirProducao(Sentinela s) {
  Lista *aux, *prev = NULL;
  int codigo;
  printf("Código da produção que deseja alterar: ");
  scanf("%d", &codigo);

  for (aux = s.head; aux != NULL; prev = aux, aux = aux->next) {
      if (aux->prod.codigo == codigo) {
          if (prev == NULL) {
              s.head = aux->next;
          } else {
              prev->next = aux->next;
          }
          if (aux == s.tail) {
              s.tail = prev;
          }
          free(aux);
          printf("Registro excluído com sucesso.\n");
          return s;
      }
  }

    printf("Nenhum registro encontrado com o código %d.\n", codigo);
}

void listarTudo(Sentinela s) {
    Lista *aux;

    printf("Lista de todos os registros de produção:\n");

    for (aux = s.head; aux != NULL; aux = aux->next) {
        printf("Código: %d\n", aux->prod.codigo);
        printf("Data da produção: %02d/%02d/%04d\n", aux->prod.dataProducao.dia, aux->prod.dataProducao.mes, aux->prod.dataProducao.ano);
        printf("Cultivar: %s\n", aux->prod.tipoDeFardo.cultivar);
        printf("Tipo de feno: %c\n", aux->prod.tipoDeFardo.tipoDeFeno);
        printf("Diâmetro: %d\n", aux->prod.tipoDeFardo.diametro);
        printf("Quantidade de fardos: %d\n", aux->prod.qtDeFardos);
        printf("Duração da produção: %.2f\n", aux->prod.duracao);
        printf("---------------------------\n");
    }
}


void menu(){
    printf("1. Incluir Produção \n");
    printf("2. Consultar \n");
    printf("3. Alterar \n");
    printf("4. Excluir \n");
    printf("5. Listar Tudo \n");
    printf("6. Sair \n");
    printf("O que você deseja fazer: ");
    return;
}

//////////////////////////////////////// MAIN /////////////////////////////////////////
int main(void) {
    Sentinela s;
    s.head = NULL;
    s.tail = NULL;

    int op;
    do {
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                s = incluirProducao(s);
                break;
            case 2: {
                int c;
                printf("1. Consultar por data\n2. Consultar por Cultivar\n");
                scanf("%d", &c);
                if (c == 1) {
                    Data data;
                    printf("Data da produção (ex: 11 12 2023): ");
                    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
                    consultarData(data, s);
                } else if (c == 2) {
                    char cult[20];
                    printf("Cultivar: ");
                    scanf("%s", cult);
                    consultarCultivar(s, cult);
                }
                break;
            }
            case 3: {
                int codigo;
                printf("Informe o código da produção que deseja alterar: ");
                scanf("%d", &codigo);
                alterarProducao(s, codigo);
                break;
            }
            case 4: {
              s = excluirProducao(s);
              break;
            }
            case 5: {
              listarTudo(s);
              break;
            }
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (op != 6);

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////