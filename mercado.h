#ifndef SUPERMERCADO_MERCADO_H
#define SUPERMERCADO_MERCADO_H

#define MAX_ITENS 100  // Constante para limitar o tamanho dos vetores
#define MAX_NOME 50   // Definindo o tamanho máximo do nome

/** Definição da estrutura do Produto */

typedef struct {
    int id;                        // Identificador único do produto
    char nome[MAX_NOME];          // Nome do produto
    float preco;                 // Preço do produto
    int quantidadeEstoque;      // Quantidade disponível em estoque
} Produto;


/** Protótipos das funções */


void exibirMenu(int primeiraVez);// Função Menu inicial
void adicionarProduto(Produto* produtos, int* totalProdutos);// Função adicionar produto
void alterarPreco(Produto* produtos, int totalProdutos);// Função alterar preço
void checarEstoque(Produto* produtos, int totalProdutos);// Função checar estoque
void listarProdutos(Produto* produtos, int totalProdutos);// Função Lista de produtos
void excluirProduto(Produto* produtos, int* totalProdutos); // Função excluir produto
void salvarDados(Produto* produtos, int totalProdutos);// Função salvar dados do estoque
void carregarDados(Produto* produtos, int* totalProdutos);// Função carregar dados do estoque
void excluirDados();// Função excluir dados do estoque
void excluirTodosDados(Produto* produtos, int* totalProdutos); //Função para excluir o Estoque Atual
void encontrarProdutoPorNome(Produto* produtos, int totalProdutos);// Localizar Produtos pelo nome
void ordenarPorID(Produto* produtos, int totalProdutos);// Ordenar produtos Pelo ID



#endif //SUPERMERCADO_MERCADO_H
