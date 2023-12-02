#include "mercado.h"
#include <stdio.h>
#include <string.h>

/** Função para exibir o menu de opções */
void exibirMenu(int primeiraVez) {

/**
 * @brief Exibe o menu do sistema de registro de produtos de supermercado.
 * primeiraVez Indica se esta é a primeira vez que o menu está sendo exibido.
 * Se verdadeiro (1), exibe uma mensagem adicional.
 */

    if (primeiraVez) {
        printf("\n*** Sistema de Registro de Produtos de Supermercado ***\n");
    }
    printf("1. Adicionar Produto\n");
    printf("2. Alterar Preco\n");
    printf("3. Checar Estoque\n");
    printf("4. Listar Produtos\n");
    printf("5. Excluir Produtos\n");
    printf("6. Salvar Dados do Estoque\n");
    printf("7. Excluir Dados do Estoque\n");
    printf("8. Excluir Dados do Estoque atual\n");
    printf("9. Buscar Produto\n");
    printf("Digite 0 ou insira um caractere para SAIR.\n");
}

/** Função para adicionar um novo produto ao estoque */
void adicionarProduto(Produto* produtos, int* totalProdutos) {

/**
 * @brief Adiciona um novo produto ao estoque.
 * Esta função solicita ao usuário informações sobre um novo produto, como ID, nome, preço e quantidade em estoque.
 * Verifica se o ID inserido já existe e, se existir, solicita um novo ID. Após a entrada bem-sucedida, o novo produto
 * é adicionado ao array de produtos e o total de produtos é incrementado. O array de produtos é então ordenado pelo ID.
 * @param produtos é  um array de produtos para armazenar os dados do estoque.
 * @param totalProdutos é um ponteiro para o número total de produtos no array.
 */

    printf("Adicionar Produto:\n");

    int novoID;
    int idExistente;
    int leituraValida;  // Adiciona uma variável para verificar a validade da leitura

    do {
        novoID = 0;  // Reinicializa o novoID antes do loop

        printf("ID do produto: ");
        if ((leituraValida = scanf("%d", &novoID)) != 1) {
            printf("Entrada invalida para o ID. Insira um valor numerico.\n");
            // Limpar o buffer de entrada
            while (getchar() != '\n');
        }

        // Verificar se o ID já existe
        idExistente = 0;
        for (int i = 0; i < *totalProdutos; i++) {
            if (produtos[i].id == novoID) {
                printf("\nID ja cadastrado, insira uma nova identificacao.\n");
                idExistente = 1;
                break;
            }

        }

    } while (idExistente || !leituraValida);

    produtos[*totalProdutos].id = novoID;

    // Verifica se o nome já existe no estoque (ignorando maiúsculas e minúsculas)
    int nomeExistente;
    int leitValida;

    do {
        nomeExistente = 0;  // Reinicializa o nomeExistente antes do loop

        printf("Nome do produto: ");
        leitValida = scanf("%s", produtos[*totalProdutos].nome);

        for (int i = 0; i < *totalProdutos; i++) {
            // Usando a função strcasecmp para comparar strings sem diferenciar maiúsculas e minúsculas
            if (strcasecmp(produtos[i].nome, produtos[*totalProdutos].nome) == 0) {
                printf("Nome do produto ja existe no estoque. Insira um nome unico.\n");
                nomeExistente = 1;
                break;  // Encerra o loop se o nome já existir
            }
        }

        // Limpar o buffer de entrada se a leitura não for válida
        if (!leitValida) {
            printf("Entrada invalida para o nome. Tente novamente.\n");
            while (getchar() != '\n');
        }

    } while (nomeExistente || !leitValida);

        // Verificação para o preço
        printf("Preco do produto: ");
        while (scanf("%f", &produtos[*totalProdutos].preco) != 1) {
            printf("Entrada invalida para o preco. Insira um valor numerico.\n");

            // Limpar o buffer de entrada
            while (getchar() != '\n');
            printf("Preco do produto: ");
        }

        // Verificação para o estoque
        printf("Quantidade em estoque: ");
        while (scanf("%d", &produtos[*totalProdutos].quantidadeEstoque) != 1) {
            printf("Entrada invalida para o estoque. Insira um valor numerico.\n");

            // Limpar o buffer de entrada
            while (getchar() != '\n');
            printf("Quantidade em estoque: ");
        }

        (*totalProdutos)++;

        // Ordena os produtos pelo ID após a inserção
        ordenarPorID(produtos, *totalProdutos);
    }

/** Função para ordenar os produtos pelo ID */
    void ordenarPorID(Produto *produtos, int totalProdutos) {

/**
 * @brief Ordena um array de produtos pelo ID usando o algoritmo de ordenação Bubble Sort (o mesmo principio de uma matriz).
 * Esta função recebe um array de produtos e o número total de produtos no array.
 * Ela utiliza o algoritmo de ordenação Bubble Sort para ordenar os produtos com base no campo ID.
 * A ordenação é realizada in-place, modificando diretamente o array de produtos.
 * @param produtos é um array de produtos a ser ordenado.
 * @param totalProdutos é o número total de produtos no array.
 */

        // Algoritmo de ordenação
        for (int i = 0; i < totalProdutos - 1; i++) {
            for (int j = i + 1; j < totalProdutos; j++) {
                if (produtos[i].id > produtos[j].id) {
                    // Troca os produtos de posição
                    Produto temp = produtos[i];
                    produtos[i] = produtos[j];
                    produtos[j] = temp;
                }
            }
        }
    }

/** Função para alterar o preço de um produto existente */
    void alterarPreco(Produto *produtos, int totalProdutos) {

        /**
         * @brief Altera o preço de um produto existente no array de produtos.
         * Solicita ao usuário o ID do produto a ser modificado e o novo preço desejado.
         * Procura pelo produto com o ID correspondente no array e, se encontrado, altera o preço do produto.
         * Caso o produto não seja encontrado ou o ID fornecido não for válido, exibe uma mensagem apropriada.
         * @param produtos é umm array de produtos a ser modificado.
         * @param totalProdutos é o número total de produtos no array.
         */

        int id;
        float novoPreco;

        printf("Alterar Preco:\n");

        // Solicitar o ID do produto
        printf("Digite o ID do produto: ");
        while (scanf("%d", &id) != 1 || id <= 0 || id > MAX_ITENS) {
            printf("ID invalido. Insira um ID valido: ");
            // Limpar o buffer de entrada
            while (getchar() != '\n');
        }

        // Verificar se o ID fornecido corresponde a um produto existente
        int produtoEncontrado = 0;
        for (int i = 0; i < totalProdutos; i++) {
            if (produtos[i].id == id) {
                printf("Novo preco do produto %s: ", produtos[i].nome);
                while (scanf("%f", &novoPreco) != 1) {
                    printf("Entrada invalida para o preco. Insira um valor numerico: ");
                    // Limpar o buffer de entrada
                    while (getchar() != '\n');
                }

                produtos[i].preco = novoPreco;
                printf("Preco alterado com sucesso!\n");
                produtoEncontrado = 1;
                break;
            }
        }

        if (!produtoEncontrado) {
            printf("Produto nao encontrado ou ID invalido.\n");
        }
    }

/** Função para checar o estoque de todos os produtos */
    void checarEstoque(Produto *produtos, int totalProdutos) {

/**
 * @brief Exibe o estoque atual, mostrando o nome e a quantidade em estoque de cada produto.
 * Esta função percorre o array de produtos e imprime na tela o nome e a quantidade em estoque de cada produto.
 * É uma função de leitura, não altera os dados dos produtos.
 * @param produtos é um array de produtos contendo informações sobre o estoque.
 * @param totalProdutos é o número total de produtos no array.
 */

        // Verifica se o estoque está vazio
        if (totalProdutos == 0) {
            printf("O estoque esta vazio.\n");
            return;
        }
        printf("Checar Estoque:\n");

        for (int i = 0; i < totalProdutos; i++) {
            printf("\nProduto: %s, Estoque: %d %s\n", produtos[i].nome, produtos[i].quantidadeEstoque,
                   (produtos[i].quantidadeEstoque == 1) ? "unidade"
                                                        : "unidades");// Exibe a quantidade em estoque com a palavra "unidade" no singular
            // ou "unidades" no plural, dependendo se a quantidade é igual a 1 ou não.
        }
    }

/** Função para listar todos os produtos e suas informações */
    void listarProdutos(Produto *produtos, int totalProdutos) {

/**
 * @brief Exibe uma lista detalhada de produtos, incluindo ID, nome, preço e quantidade em estoque.
 * Esta função percorre o array de produtos e imprime na tela informações detalhadas sobre cada produto,
 * incluindo o ID, nome, preço e quantidade em estoque. A quantidade em estoque é exibida com a palavra
 * "unidade" no singular ou "unidades" no plural, dependendo se a quantidade é igual a 1 ou não.
 * @param produtos é um array de produtos contendo informações sobre o estoque.
 * @param totalProdutos é o número total de produtos no array.
 */
        // Verifica se o estoque está vazio
        if (totalProdutos == 0) {
            printf("O estoque esta vazio.\n");
            return;
        }
        printf("\nLista de Produtos:\n");


        for (int i = 0; i < totalProdutos; i++) {
            printf("ID: %d, Nome: %s, Preco: RS:%.2f, Estoque: %d %s\n\n",
                   produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidadeEstoque,
                   (produtos[i].quantidadeEstoque == 1) ? "unidade"
                                                        : "unidades");// Exibe a quantidade em estoque com a palavra "unidade" no singular
            // ou "unidades" no plural, dependendo se a quantidade é igual a 1 ou não.
        }
    }

/** Função para excluir um produto do estoque */
    void excluirProduto(Produto *produtos, int *totalProdutos) {

        /**
         * @brief Exclui um produto do array de produtos com base no ID fornecido.
         * Esta função solicita ao usuário o ID do produto a ser excluído. Em seguida, procura pelo produto com o
         * ID correspondente no array e, se encontrado, o exclui, deslocando os produtos restantes para preencher a lacuna.
         * Após a exclusão, o total de produtos é decrementado, e os IDs dos produtos restantes são atualizados para manter
         * uma sequência contínua de IDs começando a partir de 1.
         * @param produtos é um array de produtos contendo informações sobre o estoque.
         * @param totalProdutos é um ponteiro para o número total de produtos no array.
         */

        int id;

        printf("Excluir Produto:\n");

        // Solicitar o ID do produto
        printf("Digite o ID do produto a ser excluido: ");
        while (scanf("%d", &id) != 1 || id <= 0 || id > MAX_ITENS) {
            printf("ID invalido. Insira um ID valido: ");
            // Limpar o buffer de entrada
            while (getchar() != '\n');
        }

        int indice = -1; // Inicializa como -1 para indicar que o produto não foi encontrado

        // Encontrar o índice do produto com o ID fornecido
        for (int i = 0; i < *totalProdutos; i++) {
            if (produtos[i].id == id) {
                indice = i;
                break;
            }
        }

        if (indice != -1) {
            // Deslocar os produtos para preencher a lacuna deixada pelo produto excluído
            for (int i = indice; i < *totalProdutos - 1; i++) {
                produtos[i] = produtos[i + 1];
            }

            (*totalProdutos)--;
            printf("Produto excluido com sucesso!\n");

            // Atualizar os IDs dos produtos restantes
            for (int i = 0; i < *totalProdutos; i++) {
                produtos[i].id = i + 1; // Os IDs começam a partir de 1
            }
        } else {
            printf("Produto nao encontrado ou ID invalido.\n");
        }
    }

/** Função para salvar dados do estoque em um arquivo */
    void salvarDados(Produto *produtos, int totalProdutos) {

/**
 * @brief Salva os dados do estoque atual em um arquivo binário para uso futuro.
 * Esta função cria ou sobrescreve um arquivo binário chamado "estoque.dat" para armazenar os dados
 * do estoque atual. Os dados incluem o número total de produtos e as informações individuais de cada produto.
 * @param produtos é um array de produtos contendo informações sobre o estoque.
 * @param totalProdutos é o número total de produtos no array.
 */

        FILE *arquivo = fopen("estoque.dat", "wb");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo para salvar.\n");
            return;
        }
        /** Esta função permite salvar os  dados do estoque atual e utiliza-lo em um estoque futuro se necessário
         */

        // Escreve o número total de produtos no arquivo
        fwrite(&totalProdutos, sizeof(int), 1, arquivo);

        // Escreve os produtos no arquivo
        fwrite(produtos, sizeof(Produto), totalProdutos, arquivo);

        fclose(arquivo);
        printf("Dados salvos com sucesso.\n");
    }

/** Função para carregar dados do estoque de um arquivo */
    void carregarDados(Produto *produtos, int *totalProdutos) {

/**
 * @brief Carrega os dados do estoque a partir de um arquivo binário.
 * Esta função tenta abrir um arquivo binário chamado "estoque.dat". Se o arquivo não for encontrado,
 * exibe uma mensagem informativa e retorna imediatamente. Se o arquivo for encontrado, lê o número total
 * de produtos e as informações individuais de cada produto do arquivo, atualizando o array de produtos.
 * @param produtos é um array de produtos para armazenar as informações do estoque.
 * @param totalProdutos é um ponteiro para o número total de produtos a ser atualizado.
 */

        FILE *arquivo = fopen("estoque.dat", "rb");
        if (arquivo == NULL) {
            printf("\nArquivo de dados nao encontrado. Inicializando novo estoque.\n");
            return;  // Retorna imediatamente se o arquivo não for encontrado
        }

        // Lê o número total de produtos do arquivo
        fread(totalProdutos, sizeof(int), 1, arquivo);

        // Lê os produtos do arquivo
        fread(produtos, sizeof(Produto), *totalProdutos, arquivo);

        fclose(arquivo);
        printf("Dados carregados com sucesso.\n");
    }

/** Função para excluir os dados do arquivo */
    void excluirDados() {

/**
 * @brief Exclui o arquivo que armazena os dados do estoque.
 * Esta função tenta excluir o arquivo binário chamado "estoque.dat". Se a exclusão for bem-sucedida,
 * exibe uma mensagem informando que os dados foram excluídos com sucesso. Caso contrário, exibe uma mensagem
 * de erro indicando que ocorreu um problema ao excluir os dados.
 */

        if (remove("estoque.dat") == 0) {
            printf("Dados excluidos com sucesso.\n");
        } else {
            printf("Erro ao excluir os dados.\n");
        }
    }

/** Função para excluir todos os itens do estoque */
    void excluirTodosDados(Produto *produtos, int *totalProdutos) {

/**
 * @brief Exclui todos os dados do estoque, resetando os valores dos produtos e atualizando o número total de produtos.
 * Esta função percorre o array de produtos e redefine os valores de cada produto para seus estados iniciais:
 * - ID é definido como 0.
 * - Nome é definido como uma string vazia.
 * - Quantidade em estoque é definida como 0.
 * - Preço é definido como 0.0.
 * Em seguida, atualiza o número total de produtos para 0 e reorganiza os IDs dos produtos restantes.
 * @param produtos é um array de produtos a ser modificado.
 * @param totalProdutos é um ponteiro para a variável que armazena o número total de produtos.
 */

        for (int i = 0; i < *totalProdutos; i++) {
            produtos[i].id = 0;
            produtos[i].nome[0] = '\0';
            produtos[i].quantidadeEstoque = 0;
            produtos[i].preco = 0.0;
        }
        *totalProdutos = 0; // Atualiza o número total de produtos
        printf("Todos os itens do estoque foram excluidos.\n");

        // Atualizar os IDs dos produtos restantes
        for (int i = 0; i < *totalProdutos; i++) {
            produtos[i].id = i + 1; // Os IDs começam a partir de 1
        }
    }

/** Função para encontrar um produto pelo nome e exibir */
    void encontrarProdutoPorNome(Produto *produtos, int totalProdutos) {

/**
 * @brief Encontra um produto no estoque com base no nome fornecido.
 * Solicita ao usuário o nome do produto a ser encontrado. Percorre o array de produtos e utiliza
 * a função `strncasecmp` para comparar strings sem diferenciar maiúsculas e minúsculas, permitindo que
 * o usuário encontre o produto mesmo digitando o nome de maneiras diferentes. Se o produto for encontrado,
 * exibe informações detalhadas sobre ele. Caso contrário, exibe uma mensagem indicando que o produto não foi encontrado.
 * @param produtos é um array de produtos contendo informações sobre o estoque.
 * @param totalProdutos é o número total de produtos no array.
 */

        printf("Digite o nome do produto para encontrar: ");
        char nomeBusca[MAX_NOME];
        scanf("%s", nomeBusca);

        for (int i = 0; i < totalProdutos; i++) {

            /** Usando a função strncasecmp para comparar strings sem diferenciar maiúsculas e minúsculas,
             * dessa maneira o usuario pode encontrar o produto escrevendo de qualquer maneira no inicio da frase.
             */

            if (strncasecmp(produtos[i].nome, nomeBusca, MAX_NOME) == 0) {
                printf("Produto encontrado!\n");
                printf("ID: %d, Nome: %s, Preco: RS:%.2f, Estoque: %d %s\n",
                       produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidadeEstoque,
                       (produtos[i].quantidadeEstoque == 1) ? "unidade"
                                                            : "unidades");// Exibe a quantidade em estoque com
                // a palavra "unidade" no singular
                // ou "unidades" no plural, dependendo se a quantidade é igual a 1 ou não.
                return; // Encerra a função após encontrar o produto
            }
        }

        printf("Produto nao encontrado.\n");
    }
