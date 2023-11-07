#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ItemSet {
private:
    vector<string> items;

public:
    ItemSet() {}

    ItemSet(const ItemSet& other) {
        items = other.items;
    }

    ItemSet& operator=(const ItemSet& other) {
        if (this != &other) {
            items = other.items;
        }
        return *this;
    }

    ItemSet operator+(const ItemSet& other) const {
        ItemSet result = *this;
        for (const string& item : other.items) {
            result.inserir(item);
        }
        return result;
    }

    ItemSet operator*(const ItemSet& other) const {
        ItemSet result;
        for (const string& item : items) {
            if (other.contem(item)) {
                result.inserir(item);
            }
        }
        return result;
    }

    ItemSet operator-(const ItemSet& other) const {
        ItemSet result = *this;
        for (const string& item : other.items) {
            result.excluir(item);
        }
        return result;
    }

    ItemSet operator<>(const ItemSet& other) const {
        ItemSet result = *this + other;
        for (const string& item : items) {
            if (other.contem(item)) {
                result.excluir(item);
            }
        }
        return result;
    }

    bool operator==(const ItemSet& other) const {
        return is_permutation(items.begin(), items.end(), other.items.begin(), other.items.end());
    }

    void inserir(const string& s) {
        if (!contem(s)) {
            items.push_back(s);
        }
    }

    void excluir(const string& s) {
        items.erase(remove(items.begin(), items.end(), s), items.end());
    }

    bool contem(const string& s) const {
        return find(items.begin(), items.end(), s) != items.end();
    }

    void mostrar() const {
        for (const string& item : items) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    ItemSet A, B, C;

    A.inserir("Item1");
    A.inserir("Item2");
    A.inserir("Item3");

    B.inserir("Item2");
    B.inserir("Item3");
    B.inserir("Item4");

    C.inserir("Item3");
    C.inserir("Item4");
    C.inserir("Item5");

    ItemSet D = B + C; 
    D.mostrar();

    ItemSet E = B * C;
    E.mostrar();

    ItemSet F = B - C; 
    F.mostrar();

    ItemSet G = B <> C; 
    G.mostrar();

    if (A == B) {
        cout << "A e B são iguais." << endl;
    } else {
        cout << "A e B não são iguais." << endl;
    }

    return 0;
}
