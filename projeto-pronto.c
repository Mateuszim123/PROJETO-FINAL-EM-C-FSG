#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NOME 50
#define MAX_ALUNOS 10

float CalculandoArea(float r, float pi) {
    float area = pi * pow(r, 2);
    return area;
}

float CalculandoConsumo(float kms, float litros_combustivel) {
    float consumo_medio = kms / litros_combustivel;
    return consumo_medio;
}

float CalcularPagamentoFuncionario(char nome[MAX_NOME], float hrs_trabalhadas, float valor_do_pagamento) {
    float pagamento = hrs_trabalhadas * valor_do_pagamento;
    return pagamento;
}

void AprovadoReprovado(float nota1, float nota2) {
    float media = (nota1 + nota2) / 2;

    if (media > 6.0) {
        printf("APROVADO\n");
    } if (media < 6.0) {
        printf("REPROVADO\n");
    }
}

void MERCADO(int quant[], int codigo[], int num_itens) {
    float ValorPagar = 0;

    for (int i = 0; i < num_itens; i++) {
        switch (codigo[i]) {
            case 1:
                ValorPagar += 5.0 * quant[i];
                break;
            case 2:
                ValorPagar += 3.50 * quant[i];
                break;
            case 3:
                ValorPagar += 4.80 * quant[i];
                break;
            case 4:
                ValorPagar += 8.90 * quant[i];
                break;
            case 5:
                ValorPagar += 7.32 * quant[i];
                break;
            default:
                printf("OPCAO INVALIDA no item %d!\n", i+1);
                return;
        }
    }

    printf("Valor a pagar: %.2f\n", ValorPagar);
}

void TemperaturaConversao(float c[], float f[], char unid[], int num_temperaturas) {
    for (int i = 0; i < num_temperaturas; i++) {
        if (unid[i] == 'f') {
            c[i] = (f[i] - 32) * 5 / 9;
            printf("TEMPERATURA EQUIVALENTE A CELSIUS: %.2f\n", c[i]);
        } else if (unid[i] == 'c') {
            f[i] = (c[i] * 9 / 5) + 32;
            printf("TEMPERATURA REFERENTE A FAHRENHEIT: %.2f\n", f[i]);
        } else {
            printf("UNIDADE DE TEMPERATURA INVALIDA no item %d :)\n", i+1);
        }
    }
}

int main() {
    printf("\t===============================\n");
    printf("\tBEM VINDO AO PROGRAMA DO COSMA\n");
    printf("\t===============================\n");

    int escolha;
    char continuar;

    do {
        printf("\n\n=================PROJETO FINAL==========================\n\n\n");

        printf("\tEscolha o programa que deseja executar:\n");
        printf("\t1 - Calcular area\n");
        printf("\t2 - Calcular consumo de combustivel\n");
        printf("\t3 - Calcular pagamento de funcionario\n");
        printf("\t4 - Verificar aprovacao/reprovacao no semestre\n");
        printf("\t5 - Converter temperatura\n");
        printf("\tQual Opcao voce deseja?\n ");
        printf("\n\n========================================================\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                float raio, pi;
                system("cls");
                printf("Digite o raio: ");
                scanf("%f", &raio);
                printf("Digite o valor de pi: ");
                scanf("%f", &pi);
                float area = CalculandoArea(raio, pi);
                printf("A area e: %.2f\n", area);
                break;
            }
            case 2: {
                float kms, litros_combustivel;
                system("cls");
                printf("Digite a quantidade de quilometros percorridos: ");
                scanf("%f", &kms);
                printf("Digite a quantidade de litros de combustivel: ");
                scanf("%f", &litros_combustivel);
                float consumo_medio = CalculandoConsumo(kms, litros_combustivel);
                printf("O consumo medio e: %.2f\n", consumo_medio);
                break;
            }
            case 3: {
                char nome[MAX_ALUNOS][MAX_NOME];
                float hrs_trabalhadas[MAX_ALUNOS], valor_do_pagamento[MAX_ALUNOS];
                int num_funcionarios;
                system("cls");
                printf("Digite o numero de funcionarios: ");
                scanf("%d", &num_funcionarios);
                getchar();

                for (int i = 0; i < num_funcionarios; i++) {
                    printf("Digite o nome do funcionario %d: ", i+1);
                    fgets(nome[i], sizeof(nome[i]), stdin);
                    nome[i][strcspn(nome[i], "\n")] = '\0';
                    printf("Digite as horas trabalhadas do funcionario %d: ", i+1);
                    scanf("%f", &hrs_trabalhadas[i]);
                    printf("Digite o valor do pagamento por hora do funcionario %d: ", i+1);
                    scanf("%f", &valor_do_pagamento[i]);
                    getchar();
                }

                for (int i = 0; i < num_funcionarios; i++) {
                    float pagamento = CalcularPagamentoFuncionario(nome[i], hrs_trabalhadas[i], valor_do_pagamento[i]);
                    printf("O pagamento do funcionario %d (%s) e: %.2f\n", i+1, nome[i], pagamento);
                }
                break;
            }
            case 4: {
                float nota1, nota2;
                system("cls");
                printf("LEMBRANDO QUE SAO NOTAS ATE 100 PONTOS!\n");
                printf("Digite a nota 1: ");
                scanf("%f", &nota1);
                printf("Digite a nota 2: ");
                scanf("%f", &nota2);
                AprovadoReprovado(nota1, nota2);
                break;
            }
            case 5: {
                int num_temperaturas;
                system("cls");
                printf("Digite o numero de temperaturas: ");
                scanf("%d", &num_temperaturas);
                getchar();
                float temperatura_c[MAX_ALUNOS], temperatura_f[MAX_ALUNOS];
                char unidade[MAX_ALUNOS];

                for (int i = 0; i < num_temperaturas; i++) {
                    printf("Digite a temperatura %d: ", i+1);
                    scanf("%f", &temperatura_c[i]);
                    getchar();
                    printf("Digite a unidade da temperatura %d ((C) CELSIUS OU (F) FAHRENHEIT): ", i+1);
                    scanf("%c", &unidade[i]);
                    getchar();
                }

                TemperaturaConversao(temperatura_c, temperatura_f, unidade, num_temperaturas);
                break;
            }
            default:
                printf("Opcao invalida!\n");
        }

        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &continuar);
        system("cls");

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
