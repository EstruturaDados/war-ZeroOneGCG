// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

#include <stdio.h>
#include <string.h>

// Definição da estrutura para representar um território

typedef struct Territorio {
    char nome[50];
    char cor[10];
    int tropas;
};

// Comaço do Script

int main() {

    // Cadastro de territórios

    printf("Iniciando Cadastro dos Territórios...\n");

    struct Territorio t1;

    // Contato com o usuário para obter os dados do território

    printf("\nDigite o nome do primeiro território: ");

    // fgets é melhor para strings com espaços. Sizeof para dar o tamanho
    // correto(50). E stdin para ler somente o inoput do usuário e não do
    // arquivo.

    fgets(t1.nome, sizeof(t1.nome), stdin);

    // Remover o caractere de nova linha adicionado pelo fgets

    t1.nome[strcspn(t1.nome, "\n")] = '\0';

    printf("\n---------------------------------------\n");

    printf("\nDigite a cor do primeiro território: ");
    fgets(t1.cor, sizeof(t1.cor), stdin);
    t1.cor[strcspn(t1.cor, "\n")] = '\0';

    printf("\n---------------------------------------\n");

    printf("\nDigite o número de tropas no primeiro território: ");

    // Uso de %d porque será número inteiro
    scanf("%d", &t1.tropas);

    // Limpar o buffer após scanf
    while (getchar() != '\n')
	;

    printf("\n\n\nIniciando Cadastro do Segundo Território...\n");

    struct Territorio t2;

    printf("\nDigite o nome do segundo território: ");
    fgets(t2.nome, sizeof(t2.nome), stdin);
    t2.nome[strcspn(t2.nome, "\n")] = '\0';

    printf("\n---------------------------------------\n");

    printf("\nDigite a cor do segundo território: ");
    fgets(t2.cor, sizeof(t2.cor), stdin);
    t2.cor[strcspn(t2.cor, "\n")] = '\0';

    printf("\n---------------------------------------\n");

    printf("\nDigite o número de tropas no segundo território: ");
    scanf("%d", &t2.tropas);

    // Limpar o buffer após scanf
    while (getchar() != '\n')
	;

    printf("\n\n\nIniciando Cadastro do Terceiro Território...\n");

    struct Territorio t3;

    printf("\nDigite o nome do terceiro território; ");
    fgets(t3.nome, sizeof(t3.nome), stdin);
    t3.nome[strcspn(t3.nome, "\n")] = '\0';

    printf("\n---------------------------------------\n");

    printf("\nDigite a cor do terceiro território: ");
    fgets(t3.cor, sizeof(t3.cor), stdin);
    t3.cor[strcspn(t3.cor, "\n")] = '\0';

    printf("\n---------------------------------------\n");

    printf("\nDigite o número de tropas no terceiro território: ");
    scanf("%d", &t3.tropas);

    // Limpar o buffer após scanf
    while (getchar() != '\n')
	;

    printf("\n\n\nIniciando Cadastro do Quarto Território...\n");

    struct Territorio t4;

    printf("\nDigite o nome do quarto território; ");
    fgets(t4.nome, sizeof(t4.nome), stdin);
    t4.nome[strcspn(t4.nome, "\n")] = '\0';

    printf("\n---------------------------------------\n");

    printf("\nDigite a cor do quarto território: ");
    fgets(t4.cor, sizeof(t4.cor), stdin);
    t4.cor[strcspn(t4.cor, "\n")] = '\0';

    printf("\n---------------------------------------\n");

    printf("\nDigite o número de tropas no quarto território: ");
    scanf("%d", &t4.tropas);

    // Limpar o buffer após scanf
    while (getchar() != '\n')
	;

    printf("\n\n\nIniciando Cadastro do Quinto Território...\n");

    struct Territorio t5;

    printf("\nDigite o nome do quinto território; ");
    fgets(t5.nome, sizeof(t5.nome), stdin);
    t5.nome[strcspn(t5.nome, "\n")] = '\0';

    printf("\n---------------------------------------\n");

    printf("\nDigite a cor do quinto território: ");
    fgets(t5.cor, sizeof(t5.cor), stdin);
    t5.cor[strcspn(t5.cor, "\n")] = '\0';

    printf("\n---------------------------------------\n");

    printf("\nDigite o número de tropas no quinto território: ");
    scanf("%d", &t5.tropas);

    // Limpar o buffer após scanf
    while (getchar() != '\n')
	;

    printf("\n\n\nCadastro concluído!\n");

    // Exibição dos territórios cadastrados

    printf("\n\nExibindo os territórios cadastrados:\n");

    printf("\nTerritório 1 :\n\nNome: %s\n\nCor: %s\n\nNúmero de Tropas: %d\n", t1.nome,
           t1.cor, t1.tropas);
    printf("\nTerritório 2 :\n\nNome: %s\n\nCor: %s\n\nNúmero de Tropas: %d\n", t2.nome,
           t2.cor, t2.tropas);
    printf("\nTerritório 3 :\n\nNome: %s\n\nCor: %s\n\nNúmero de Tropas: %d\n", t3.nome,
           t3.cor, t3.tropas);
    printf("\n Território 4 :\n\nNome: %s\n\nCor: %s\n\nNúmero de Tropas: %d\n", t4.nome,
           t4.cor, t4.tropas);
    printf("\nTerritório 5 :\n\nNome: %s\n\nCor: %s\n\nNúmero de Tropas: %d\n", t5.nome,
           t5.cor, t5.tropas);

    printf("\n---------------------------------------");

    return 0;
}
    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    // - Define a cor do jogador e sorteia sua missão secreta.

    // 2. Laço Principal do Jogo (Game Loop):
    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    // - A cada iteração, exibe o mapa, a missão e o menu de ações.
    // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
    //   - Opção 1: Inicia a fase de ataque.
    //   - Opção 2: Verifica se a condição de vitória foi alcançada e informa o jogador.
    //   - Opção 0: Encerra o jogo.
    // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
