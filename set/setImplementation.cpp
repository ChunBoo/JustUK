
#include <iostream>
#include <memory>
#include <algorithm>

template<typename T>
class Set {
private:
    struct Node {
        T value;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        Node* parent;
        bool is_black;

        Node(const T& val) : value(val), parent(nullptr), is_black(false) {}
    };

    std::unique_ptr<Node> root;
    size_t size_;

    void rotateLeft(Node* x) {
        Node* y = x->right.get();
        x->right = std::move(y->left);
        if (x->right)
            x->right->parent = x;
        y->parent = x->parent;
        Node* x_parent = x->parent;
        if (!x_parent) {
            root = std::move(x->parent->right);
            root->parent = nullptr;
        } else if (x == x_parent->left.get()) {
            x_parent->left = std::move(x->parent->right);
            x_parent->left->parent = x_parent;
        } else {
            x_parent->right = std::move(x->parent->right);
            x_parent->right->parent = x_parent;
        }
        y->left = std::unique_ptr<Node>(x);
        x->parent = y;
    }

    void rotateRight(Node* y) {
        Node* x = y->left.get();
        y->left = std::move(x->right);
        if (y->left)
            y->left->parent = y;
        x->parent = y->parent;
        Node* y_parent = y->parent;
        if (!y_parent) {
            root = std::move(y->parent->left);
            root->parent = nullptr;
        } else if (y == y_parent->right.get()) {
            y_parent->right = std::move(y->parent->left);
            y_parent->right->parent = y_parent;
        } else {
            y_parent->left = std::move(y->parent->left);
            y_parent->left->parent = y_parent;
        }
        x->right = std::unique_ptr<Node>(y);
        y->parent = x;
    }

    void insertFixup(Node* z) {
        while (z->parent && !z->parent->is_black) {
            if (z->parent == z->parent->parent->left.get()) {
                Node* y = z->parent->parent->right.get();
                if (y && !y->is_black) {
                    z->parent->is_black = true;
                    y->is_black = true;
                    z->parent->parent->is_black = false;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right.get()) {
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->is_black = true;
                    z->parent->parent->is_black = false;
                    rotateRight(z->parent->parent);
                }
            } else {
                // Symmetric case
                Node* y = z->parent->parent->left.get();
                if (y && !y->is_black) {
                    z->parent->is_black = true;
                    y->is_black = true;
                    z->parent->parent->is_black = false;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left.get()) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->is_black = true;
                    z->parent->parent->is_black = false;
                    rotateLeft(z->parent->parent);
                }
            }
        }
        root->is_black = true;
    }

public:
    Set() : size_(0) {}

    void insert(const T& value) {
        Node* z = new Node(value);
        Node* y = nullptr;
        Node* x = root.get();

        while (x) {
            y = x;
            if (value < x->value)
                x = x->left.get();
            else if (value > x->value)
                x = x->right.get();
            else
                return; // Value already exists
        }

        z->parent = y;
        if (!y)
            root = std::unique_ptr<Node>(z);
        else if (value < y->value)
            y->left = std::unique_ptr<Node>(z);
        else
            y->right = std::unique_ptr<Node>(z);

        insertFixup(z);
        size_++;
    }

    bool contains(const T& value) const {
        Node* current = root.get();
        while (current) {
            if (value == current->value)
                return true;
            else if (value < current->value)
                current = current->left.get();
            else
                current = current->right.get();
        }
        return false;
    }

    size_t size() const {
        return size_;
    }

    // Other methods like erase, clear, etc. would be implemented here
};

int main() {
    Set<int> mySet;

    mySet.insert(5);
    mySet.insert(3);
    mySet.insert(7);
    mySet.insert(1);

    std::cout << "Set size: " << mySet.size() << std::endl;
    std::cout << "Contains 3: " << (mySet.contains(3) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 4: " << (mySet.contains(4) ? "Yes" : "No") << std::endl;

    return 0;
}