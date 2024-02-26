#include <iostream>
#include <list>
#include <string>

const int MAX_ITEMS = 100;

class Produto {
public:
    int codigo;
    std::string descricao;
    float preco;

    Produto() : codigo(-1), descricao(""), preco(0.0) {}
    Produto(int cod, std::string desc, float pre) : codigo(cod), descricao(desc), preco(pre) {}

    int getCodigo() const { return codigo; }
    std::string getDescricao() const { return descricao; }
    float getPreco() const { return preco; }
};

class HashTable {
private:
    std::list<Produto> items[MAX_ITEMS];
    int getHash(int codigo) { return codigo % MAX_ITEMS; }

public:
    HashTable() {}
    void insertItem(const Produto& produto) {
        int index = getHash(produto.getCodigo());
        items[index].push_back(produto);
    }
    void deleteItem(int codigo) {
        int index = getHash(codigo);
        items[index].remove_if([codigo](const Produto& p) { return p.getCodigo() == codigo; });
    }
    bool findItem(int codigo) {
        int index = getHash(codigo);
        for (const auto& item : items[index]) {
            if (item.getCodigo() == codigo) {
                return true;
            }
        }
        return false;
    }
    void print() const {
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (!items[i].empty()) {
                std::cout << "Posição " << i << ": ";
                for (const auto& produto : items[i]) {
                    std::cout << "Código: " << produto.getCodigo()
                              << ", Descrição: " << produto.getDescricao()
                              << ", Preço: R$" << produto.getPreco() << " | ";
                }
                std::cout << std::endl;
            }
        }
    }
};

void runTests() {
    std::cout << "Iniciando os testes...\n\n";
    HashTable tabela;

    std::cout << "Teste 1: Inserção de Itens\n";
    tabela.insertItem(Produto(1, "Caneta Azul", 1.50));
    tabela.insertItem(Produto(2, "Lápis Grafite", 0.75));
    tabela.insertItem(Produto(3, "Borracha Branca", 0.50));
    std::cout << "Após inserir Caneta Azul, Lápis Grafite e Borracha Branca:\n";
    tabela.print();

    std::cout << "\nTeste 2: Tratamento de Colisões\n";
    tabela.insertItem(Produto(1, "Caneta Vermelha", 1.75)); 
    std::cout << "Após inserir Caneta Vermelha (mesmo código que Caneta Azul):\n";
    tabela.print();

    std::cout << "\nTeste 3: Remoção de Itens\n";
    tabela.deleteItem(1); 
    std::cout << "Após remover produtos com código 1 (Canetas):\n";
    tabela.print();

    std::cout << "\nTeste 4: Busca de Itens\n";
    bool found = tabela.findItem(2);  
    std::cout << "Busca por Produto com código 2 (deve ser encontrado): " << (found ? "Sucesso" : "Falha") << "\n";
    found = tabela.findItem(1); 
    std::cout << "Busca por Produto com código 1 após remoção (não deve ser encontrado): " << (found ? "Falha" : "Sucesso") << "\n";

    std::cout << "\nTeste 5: Testando a capacidade\n";

    std::cout << "Tabela após tentar exceder a capacidade:\n";
    tabela.print();
}

int main() {
    runTests();
    return 0;
}
