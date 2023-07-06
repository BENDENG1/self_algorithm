#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    char c;
    char left;
    char right;
};

void preOrder(const vector<Node>& v, char node);
void inOrder(const vector<Node>& v, char node);
void postOrder(const vector<Node>& v, char node);

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<Node> v(n + 1);

    for (int i = 0; i < n; i++) {
        char root, leftChild, rightChild;
        cin >> root >> leftChild >> rightChild;
        v[root - 'A'].c = root;
        v[root - 'A'].left = leftChild;
        v[root - 'A'].right = rightChild;
    }

    preOrder(v, 'A');
    cout << "\n";
    inOrder(v, 'A');
    cout << "\n";
    postOrder(v, 'A');
}

void preOrder(const vector<Node>& v, char node) {
    if (node == '.')
        return;

    cout << node;
    preOrder(v, v[node - 'A'].left);
    preOrder(v, v[node - 'A'].right);
}

void inOrder(const vector<Node>& v, char node) {
    if (node == '.')
        return;

    inOrder(v, v[node - 'A'].left);
    cout << node;
    inOrder(v, v[node - 'A'].right);
}

void postOrder(const vector<Node>& v, char node) {
    if (node == '.')
        return;

    postOrder(v, v[node - 'A'].left);
    postOrder(v, v[node - 'A'].right);
    cout << node;
}
