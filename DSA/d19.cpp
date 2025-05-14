/*A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
deleting keywords, updating values of any entry. Provide facility to display whole data
sorted in ascending/ Descending order. Also find how many maximum comparisons may
require for finding any keyword. Use Height balance tree and find the complexity for
finding a keyword*/

#include <iostream>
#include <string>

using namespace std;

// Structure for each node in the AVL tree
struct TreeNode {
    string keyword;
    string meaning;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string key, string mean) {
        keyword = key;
        meaning = mean;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

// Function to get the height of a node
int getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Function to update the height of a node
void updateHeight(TreeNode* node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to perform a right rotation
TreeNode* rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
TreeNode* rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to balance the tree after insertion or deletion
TreeNode* balanceTree(TreeNode* node) {
    updateHeight(node);

    int balanceFactor = getHeight(node->left) - getHeight(node->right);

    // Left Left Case
    if (balanceFactor > 1 && getHeight(node->left->left) >= getHeight(node->left->right)) {
        return rotateRight(node);
    }

    // Right Right Case
    if (balanceFactor < -1 && getHeight(node->right->right) >= getHeight(node->right->left)) {
        return rotateLeft(node);
    }

    // Left Right Case
    if (balanceFactor > 1 && getHeight(node->left->right) >= getHeight(node->left->left)) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balanceFactor < -1 && getHeight(node->right->left) >= getHeight(node->right->right)) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Function to insert a new node into the AVL tree
TreeNode* insertNode(TreeNode* node, string keyword, string meaning) {
    if (node == nullptr) {
        return new TreeNode(keyword, meaning);
    }

    if (keyword < node->keyword) {
        node->left = insertNode(node->left, keyword, meaning);
    } else if (keyword > node->keyword) {
        node->right = insertNode(node->right, keyword, meaning);
    } else {
        // If the keyword already exists, update its meaning
        node->meaning = meaning;
        return node;
    }

    return balanceTree(node);
}

// Function to find the minimum node in the AVL tree
TreeNode* findMinNode(TreeNode* node) {
    if (node == nullptr || node->left == nullptr) {
        return node;
    }
    return findMinNode(node->left);
}

// Function to delete a node from the AVL tree
TreeNode* deleteNode(TreeNode* node, string keyword) {
    if (node == nullptr) {
        return node;
    }
      // If the keyword is smaller, go to the left subtree
    if (keyword < node->keyword) {
        node->left = deleteNode(node->left, keyword);
    }
    // If the keyword is greater, go to the right subtree
    else if (keyword > node->keyword) {
        node->right = deleteNode(node->right, keyword);
    }
    // If the keyword is found
    else {
        // Node with only one child or no child
        if (node->left == nullptr || node->right == nullptr) {
            TreeNode* temp = node->left ? node->left : node->right;

            // No child case
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            }
            // One child case
            else {
                *node = *temp;  // Copy the child's data to the current node
            }

            delete temp;
        }
        // Node with two children
        else {
            // Find the inorder successor (smallest node in the right subtree)
            TreeNode* minRight = findMinNode(node->right);

            // Copy the inorder successor's data to the current node
            node->keyword = minRight->keyword;
            node->meaning = minRight->meaning;

            // Delete the inorder successor
            node->right = deleteNode(node->right, minRight->keyword);
        }
    }

    if (node != nullptr) {
        return balanceTree(node);
    }

    return node;
}

// Function to search for a node in the AVL tree
TreeNode* searchNode(TreeNode* node, string keyword) {
    if (node == nullptr || node->keyword == keyword) {
        return node;
    }

    if (keyword < node->keyword) {
        return searchNode(node->left, keyword);
    } else {
        return searchNode(node->right, keyword);
    }
}

// Function to display the AVL tree in ascending order
void displayAscending(TreeNode* node) {
    if (node != nullptr) {
        displayAscending(node->left);
        cout << node->keyword << " : " << node->meaning << endl;
        displayAscending(node->right);
    }
}

// Main function
int main() {
    TreeNode* root = nullptr;
    int choice;
    string keyword, meaning;

    while (true) {
        cout << "1. Add new keyword" << endl;
        cout << "2. Delete keyword" << endl;
        cout << "3. Update keyword" << endl;
        cout << "4. Display data in ascending order" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin >> meaning;
                root = insertNode(root, keyword, meaning);
                break;
            case 2:
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                root = deleteNode(root, keyword);
                break;
            case 3:
                cout << "Enter keyword to update: ";
                cin >> keyword;
                cout << "Enter new meaning: ";
                cin >> meaning;
                root = insertNode(root, keyword, meaning);
                break;
            case 4:
                cout << "Dictionary in ascending order:" << endl;
                displayAscending(root);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}
