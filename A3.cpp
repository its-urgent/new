#include <iostream>
#include <string>
using namespace std;

struct node {
    string label;
    int count;
    node* child[50];
};

class tree {
public:
    void create(node* root) {
        cout << "Enter name of the book: ";
        cin.ignore();
        getline(cin, root->label);
        cout << "Enter the number of chapters in the book: ";
        cin >> root->count;
        cin.ignore(); // Consume the newline character
        for (int i = 0; i < root->count; i++) {
            root->child[i] = new node;
            cout << "Enter the name of chapter " << i + 1 << ": ";
            getline(cin, root->child[i]->label);
            cout << "Enter the number of sections in chapter " << i + 1 << ": ";
            cin >> root->child[i]->count;
            cin.ignore(); // Consume the newline character
            for (int j = 0; j < root->child[i]->count; j++) {
                root->child[i]->child[j] = new node;
                cout << "Enter the name of section " << j + 1 << ": ";
                getline(cin, root->child[i]->child[j]->label);
            }
        }
    }

    void display(node* root, int depth = 0) {
        if (root != nullptr) {
            cout << string(depth, '\t') << root->label << endl;
            for (int i = 0; i < root->count; i++) {
                display(root->child[i], depth + 1);
            }
        }
    }
};

int main() {
    tree t;
    node* root = new node;
    t.create(root);
    cout << "\nBook structure:\n";
    t.display(root);
    return 0;
}
