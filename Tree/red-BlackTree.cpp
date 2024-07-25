#include <iostream>
#include <memory>

enum class Color { RED, BLACK };

template<typename T>
class RedBlackTree {
private:
    struct Node {
        T data;
        Color color;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        Node* parent;

        Node(T value) : data(value), color(Color::RED), parent(nullptr) {}
    };

    std::unique_ptr<Node> root;

    void leftRotate(std::unique_ptr<Node>& x) {
        auto y = std::move(x->right);
        x->right = std::move(y->left);
        if (x->right)
            x->right->parent = x.get();
        y->parent = x->parent;
        auto xp = x->parent;
        if (!xp) {
            auto px = x.release();
            root = std::move(y);
            root->left = std::unique_ptr<Node>(px);
            root->left->parent = root.get();
        } else if (x == xp->left) {
            auto px = x.release();
            xp->left = std::move(y);
            xp->left->left = std::unique_ptr<Node>(px);
            xp->left->left->parent = xp->left.get();
        } else {
            auto px = x.release();
            xp->right = std::move(y);
            xp->right->left = std::unique_ptr<Node>(px);
            xp->right->left->parent = xp->right.get();
        }
    }

    void rightRotate(std::unique_ptr<Node>& y) {
        auto x = std::move(y->left);
        y->left = std::move(x->right);
        if (y->left)
            y->left->parent = y.get();
        x->parent = y->parent;
        auto yp = y->parent;
        if (!yp) {
            auto py = y.release();
            root = std::move(x);
            root->right = std::unique_ptr<Node>(py);
            root->right->parent = root.get();
        } else if (y == yp->left) {
            auto py = y.release();
            yp->left = std::move(x);
            yp->left->right = std::unique_ptr<Node>(py);
            yp->left->right->parent = yp->left.get();
        } else {
            auto py = y.release();
            yp->right = std::move(x);
            yp->right->right = std::unique_ptr<Node>(py);
            yp->right->right->parent = yp->right.get();
        }
    }

    void insertFixup(Node* z) {
        while (z->parent && z->parent->color == Color::RED) {
            if (z->parent == z->parent->parent->left.get()) {
                auto y = z->parent->parent->right.get();
                if (y && y->color == Color::RED) {
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right.get()) {
                        z = z->parent;
                        leftRotate(getUniquePtr(z));
                    }
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    rightRotate(getUniquePtr(z->parent->parent));
                }
            } else {
                auto y = z->parent->parent->left.get();
                if (y && y->color == Color::RED) {
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left.get()) {
                        z = z->parent;
                        rightRotate(getUniquePtr(z));
                    }
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    leftRotate(getUniquePtr(z->parent->parent));
                }
            }
        }
        root->color = Color::BLACK;
    }

    std::unique_ptr<Node>& getUniquePtr(Node* n) {
        if (!n->parent) return root;
        if (n == n->parent->left.get()) return n->parent->left;
        return n->parent->right;
    }

public:
    void insert(T value) {
        auto z = std::make_unique<Node>(value);
        Node* y = nullptr;
        Node* x = root.get();

        while (x) {
            y = x;
            if (z->data < x->data)
                x = x->left.get();
            else
                x = x->right.get();
        }

        z->parent = y;
        if (!y)
            root = std::move(z);
        else if (z->data < y->data)
            y->left = std::move(z);
        else
            y->right = std::move(z);

        insertFixup(getUniquePtr(z.get()).get());
    }

    bool search(T value) const {
        Node* current = root.get();
        while (current) {
            if (value == current->data)
                return true;
            else if (value < current->data)
                current = current->left.get();
            else
                current = current->right.get();
        }
        return false;
    }

    void inorderTraversal() const {
        inorderTraversalHelper(root.get());
        std::cout << std::endl;
    }

private:
    void inorderTraversalHelper(Node* node) const {
        if (node) {
            inorderTraversalHelper(node->left.get());
            std::cout << node->data << " ";
            inorderTraversalHelper(node->right.get());
        }
    }
};

int main() {
    RedBlackTree<int> rbt;

    rbt.insert(7);
    rbt.insert(3);
    rbt.insert(18);
    rbt.insert(10);
    rbt.insert(22);
    rbt.insert(8);
    rbt.insert(11);
    rbt.insert(26);

    std::cout << "Inorder traversal: ";
    rbt.inorderTraversal();

    std::cout << "Search for 10: " << (rbt.search(10) ? "Found" : "Not found") << std::endl;
    std::cout << "Search for 15: " << (rbt.search(15) ? "Found" : "Not found") << std::endl;

    return 0;
}