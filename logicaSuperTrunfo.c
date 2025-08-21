#include <stdio.h>
#include <string.h>

#define BILHAO 1000000000.0f  // Constante simbólica para escala do PIB

int main() {
    // Dados da Carta 1
    char estado1[3];
    char codigo1[5];
    char nomeCidade1[30];
    int populacao1, pontosTuristicos1;
    float area1, pib1;

    // Dados da Carta 2
    char estado2[3];
    char codigo2[5];
    char nomeCidade2[30];
    int populacao2, pontosTuristicos2;
    float area2, pib2;

    // === Entrada dos dados da Carta 1 ===
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (sigla, ex: SP): ");
    scanf("%2s", estado1);
    getchar(); // limpa buffer

    printf("Codigo da carta (ex: A01): ");
    scanf("%4s", codigo1);
    getchar();

    printf("Nome da cidade: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0'; // remove '\n'

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area (km2): ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // === Entrada dos dados da Carta 2 ===
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (sigla, ex: RJ): ");
    scanf("%2s", estado2);
    getchar();

    printf("Codigo da carta (ex: B02): ");
    scanf("%4s", codigo2);
    getchar();

    printf("Nome da cidade: ");
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area (km2): ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // === Cálculos automáticos ===
    float densidade1 = (area1 != 0) ? (populacao1 / area1) : 0.0f;
    float densidade2 = (area2 != 0) ? (populacao2 / area2) : 0.0f;

    float pibPerCapita1 = (populacao1 != 0) ? ((pib1 * BILHAO) / populacao1) : 0.0f;
    float pibPerCapita2 = (populacao2 != 0) ? ((pib2 * BILHAO) / populacao2) : 0.0f;

    // === Comparação de um atributo pré-definido ===
    // Aqui você escolhe QUAL atributo será comparado (fixo no código)
    // Exemplo: vamos comparar POPULACAO
    char atributoComparado[30] = "Populacao";
    int vencedor = 0; // 1 = Carta1, 2 = Carta2, 0 = Empate

    if (populacao1 > populacao2) {
        vencedor = 1;
    } else if (populacao2 > populacao1) {
        vencedor = 2;
    } else {
        vencedor = 0;
    }

    // === Exibição dos resultados ===
    printf("\n=== Comparacao de cartas (Atributo: %s) ===\n", atributoComparado);
    printf("Carta 1 - %s (%s-%s): %d\n", nomeCidade1, estado1, codigo1, populacao1);
    printf("Carta 2 - %s (%s-%s): %d\n", nomeCidade2, estado2, codigo2, populacao2);

    if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (vencedor == 2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}

