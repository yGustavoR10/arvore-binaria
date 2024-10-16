#include <iostream>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    void ArvoreBinariaBusca_Imprimir_Por_Nivel(int nivel) {
        if (nivel < 0) {
            std::cout << "Nível inválido." << std::endl;
            return;
        }

        std::queue<Node*> q;
        q.push(root);
        int currentLevel = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            if (currentLevel == nivel) {
                for (int i = 0; i < levelSize; ++i) {
                    Node* node = q.front();
                    q.pop();
                    if (node) {
                        std::cout << node->data << " ";
                    }
                }
                std::cout << std::endl;
                return;
            }

            for (int i = 0; i < levelSize; ++i) {
                Node* node = q.front();
                q.pop();
                if (node) {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            currentLevel++;
        }

        std::cout << "Nivel nao encontrado." << std::endl;
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }
};

int main() {
    BinarySearchTree bst;
    int elements[] = {10, 5, 15, 3, 7, 12, 18, 2, 6, 4};

    for (int value : elements) {
        bst.insert(value);
    }

    int nivel;
    std::cout << "Digite o nivel que deseja imprimir: ";
    std::cin >> nivel;

    std::cout << "Nodos no nivel " << nivel << ": ";
    bst.ArvoreBinariaBusca_Imprimir_Por_Nivel(nivel);

    return 0;
}
