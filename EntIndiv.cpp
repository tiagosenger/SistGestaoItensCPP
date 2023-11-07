#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ItemSet {
private:
    vector<string> items;

public:

    void inserir(string s) {
        bool itemJaExiste = false;
        
        for (const string& item : items) {
            if (item == s) {
                itemJaExiste = true;
                break;
            }
        }

        if (!itemJaExiste) {
            items.push_back(s);
            cout << "Item '" << s << "' inserido com sucesso." << endl;
        } else {
            cout << "Item '" << s << "' já existe no conjunto." << endl;
        }
    }

    void excluir(string s) {
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i] == s) {
                items.erase(items.begin() + i);
                cout << "Item '" << s << "' excluído com sucesso." << endl;
                return; 
            }
        }

        cout << "Item '" << s << "' não encontrado no conjunto." << endl;
    }
};

int main() {
    ItemSet conjuntoDeItens;

    conjuntoDeItens.inserir("Item1");
    conjuntoDeItens.inserir("Item2");
    conjuntoDeItens.inserir("Item3");
    conjuntoDeItens.inserir("Item1"); 

    conjuntoDeItens.excluir("Item2");
    conjuntoDeItens.excluir("Item4"); 

    return 0;
}
