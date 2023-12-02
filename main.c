#include <stdio.h>
#include "mercado.h"

/** Função principal */
int main() {
    Produto produtos[MAX_ITENS]; //Vetor do numero de Produtos
    int totalProdutos = 0;
    int escolha;
    int primeiraVez = 1;  // Variável de controle para verificar a primeira execução

    carregarDados(produtos, &totalProdutos); // Carrega os dados de um Estoque salvo

/** Loop para continuar exibindo o menu até que o usuario finalize o sistema */
    do {
        exibirMenu(primeiraVez);
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: // Adicionando a opção de Adicionar Produtos ao Estoque
                adicionarProduto(produtos, &totalProdutos);
                break;
            case 2:// Adicionando a opção de Alterar preços do Produto
                alterarPreco(produtos, totalProdutos);
                break;
            case 3: // Adicionando a opção de Checar o Estoque de um Produto
                checarEstoque(produtos, totalProdutos);
                break;
            case 4: // Adicionando a opção de Exbir todos os produtos e caracteristicas
                listarProdutos(produtos, totalProdutos);
                break;
            case 5: // Adicionando a opção de Excluir um Produto
                excluirProduto(produtos, &totalProdutos);
                break;
            case 6: // Adicionando a opção de Salvar Dados do Estoque
                salvarDados(produtos, totalProdutos);
                break;
            case 7: // Adicionando a opção de Excluir Dados do Estoque
                excluirDados();
                break;
            case 8: // Adicionando a opção de Excluir Dados do Estoque Atual
                excluirTodosDados(produtos, &totalProdutos);
                break;
            case 9: // Adicionando a opção de Encontrar Produto pelo nome
                encontrarProdutoPorNome(produtos, totalProdutos);
                break;
            case 0: // Adicionando a opção de Finalizar o Programa
                printf("Sistema Finalizado!\n");
                break;
            default: // Opção caso Nenhuma escolha do menu seja feita
                printf("Opcao invalida. Tente novamente.\n");
        }

        primeiraVez = 0;  // Marcando que não é mais a primeira execução
    } while (escolha != 0);

    return 0;
}
