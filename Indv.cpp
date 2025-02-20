#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ItemNode {
public:
    string name;
    float price;
    ItemNode* aft;
    ItemNode* bef;

    ItemNode(string name = "", float price = 0) {
        this->name = name;
        this->price = price;
        this->aft = nullptr;
        this->bef = nullptr;
    }
};

class List {
public:
    ItemNode* head;
    ItemNode* tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void task1(ItemNode* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
    }

    void task2(ItemNode* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->aft = head;
            head->bef = newNode;
            head = newNode;
        }
    }

    void task3() {
        ItemNode* current = tail;
        while (current != nullptr) {
            cout << "[" << setw(10) << current->name << setw(4) << current->price << "]  ";
            current = current->bef;
        }
        cout << endl;
    }

    void task4(ItemNode* newNode, int position) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (head == nullptr && position == 1) {
            task1(newNode);
            return;
        }

        ItemNode* current = head;
        int index = 1;

        while (current != nullptr && index < position) {
            current = current->aft;
            index++;
        }

        if (current == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        if (current == head) {
            newNode->aft = head;
            head->bef = newNode;
            head = newNode;
        } else {
            newNode->bef = current->bef;
            newNode->aft = current;
            if (current->bef != nullptr) {
                current->bef->aft = newNode;
            }
            current->bef = newNode;
        }
    }

    void task5(int position) {
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        ItemNode* current = head;
        int index = 1;

        while (current != nullptr && index < position) {
            current = current->aft;
            index++;
        }

        if (current == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        if (current == head) {
            head = current->aft;
            if (head != nullptr) {
                head->bef = nullptr;
            }
        } else if (current == tail) {
            tail = current->bef;
            if (tail != nullptr) {
                tail->aft = nullptr;
            }
        } else {
            current->bef->aft = current->aft;
            current->aft->bef = current->bef;
        }

        delete current;
    }

    void task6() {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        ItemNode* current = tail;

        if (tail == head) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->bef;
            tail->aft = nullptr;
        }

        delete current;
    }

    // Other tasks will be defined here as needed
};

int main() {
    List ItemList;
    ItemNode* n1 = new ItemNode("Book", 9.59);
    ItemNode* n2 = new ItemNode("Ruler", 3.45);
    ItemNode* n3 = new ItemNode("Pen", 5.69);
    ItemNode* n4 = new ItemNode("Eraser", 2.25);

    cout << "Print backward:" << endl;
    cout << fixed << setprecision(2) << left;
    ItemList.task1(n1);      // Insert first item
    ItemList.task2(n2);      // Insert second item at the front
    ItemList.task3();        // Print list backward

    cout << "\nPrint backward:" << endl;
    cout << fixed << setprecision(2) << left;
    ItemList.task4(n3, 2);   // Insert item at position 2
    ItemList.task4(n4, 2);   // Insert another item at position 2
    ItemList.task3();        // Print list backward

    cout << "\nPrint backward:" << endl;
    cout << fixed << setprecision(2) << left;
    ItemList.task5(3);       // Delete item at position 3
    ItemList.task3();        // Print list backward

    cout << "\nPrint backward:" << endl;
    cout << fixed << setprecision(2) << left;
    ItemList.task6();        // Delete last item
    ItemList.task3();        // Print list backward

    return 0;
}


