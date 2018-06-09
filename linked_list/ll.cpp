#include <iostream>
#include <memory>

static int nodes_created;
static int nodes_deleted;

/* Stack crash possible with large enough list?? */

/* consider move semantics as constructor param; nodes are created with the
 * intent of ownership*/
struct Node {
  std::unique_ptr<Node> next = nullptr;
  int data;
  explicit Node(int data) : data(data) { nodes_created++; }
  ~Node() {
    std::cout << "Node Destructor: Node with value: " << data << " deleted\n";
    nodes_deleted++;
  }
};

class LinkedList {
  int length;

 public:
  std::unique_ptr<Node> head;
  Node *tail;

  LinkedList() {
    this->length = 0;
    tail = nullptr;
  }

  ~LinkedList() = default;

  void pushBack(int data) {
    std::cout << "\ninserting " << data << " at back; ";
    if (this->tail != nullptr) {
      tail->next = std::make_unique<Node>(data);
      this->tail = tail->next.get();
    } else {
      this->head = std::make_unique<Node>(data);
      this->tail = head.get();
    }
    this->length++;
    std::cout << "length: " << this->length << '\n';
  }

  void insertNode(int position, int data) {
    std::cout << "\ninsert " << data << " at position[" << position << "]\n";
    if (position < 0 || position >= this->length) {
      std::cout << "invalid position\n";
      return;
    }

    if (position == this->length - 1) {
      pushBack(data);
      return;
    }

    auto *current = this->head.get();
    Node *previous;

    if (position == 0) {
      if (this->tail != nullptr) {
        auto link = std::make_unique<Node>(data);
        link->next = std::move(head);
        this->head = std::move(link);
      } else {
        this->head = std::make_unique<Node>(data);
        this->tail = head.get();
      }
      this->length++;
      return;
    }

    for (int i = 0; i < position; i++) {
      previous = current;
      current = current->next.get();
    }

    auto link = std::make_unique<Node>(data);
    link->next = std::move(previous->next);
    previous->next = std::move(link);
    this->length++;
  }

  void deleteNode(int position) {
    std::cout << "\ndelete at position[" << position << "]\n";
    if (position < 0 || position >= this->length) {
      std::cout << "invalid position\n";
      return;
    }

    auto *current = this->head.get();
    Node *previous;

    if (position == 0) {
      this->head = std::move(current->next);
      this->length--;
      if (this->length == 1) {
        this->tail = this->head.get();
      } else if (this->length == 0) {
        this->head.reset();
        this->tail = nullptr;
      }
      return;
    }

    for (int i = 0; i < position; i++) {
      previous = current;
      current = current->next.get();
    }

    if (current == this->tail) {
      previous->next.reset();
      this->tail = previous;
      this->length--;
      return;
    }

    previous->next = std::move(current->next);
    this->length--;
  }

  void deleteOdd() {
    std::cout << "\ndeleting odds\n";
    if (this->length <= 0) {
      std::cout << "list empty!\n";
      return;
    }

    auto *current = this->head.get();
    Node *previous;
    int count = 0;
    for (int i = 0; i < this->length; i++) {
      std::cout << "\nlist[" << i << "]: " << current->data;
      if (current->data % 2 != 0) {
        std::cout << " -odd\n";
        if (current == this->head.get()) {
          this->head = std::move(current->next);
          current = this->head.get();
          count++;
          continue;
        }

        if (current == this->tail) {
          previous->next.reset();
          this->tail = previous;
          count++;
          continue;
        }

        previous->next = std::move(current->next);
        current = previous->next.get();
        count++;
        continue;
      }
      std::cout << '\n';
      previous = current;
      current = current->next.get();
    }
    this->length -= count;
  }

  void print() {
    std::cout << "\nprinting list:\n";
    if (this->length <= 0) {
      std::cout << "list empty!\n";
      return;
    }

    int order = 0; /* alternative way to iterate */
    for (auto *current = this->head.get(); current != nullptr;
         current = current->next.get()) {
      std::cout << "list[" << order << "]: " << current->data << '\n';
      order++;
    }
  }

  void printLength() { std::cout << "\nlength: " << this->length << '\n'; }
};

int main() {
  LinkedList list;

  list.print();

  list.pushBack(1);
  list.print();
  list.deleteNode(0);
  list.print();

  list.pushBack(7);
  list.pushBack(5);
  list.pushBack(4);
  list.pushBack(7);

  list.print();

  list.deleteNode(3);
  list.print();
  list.pushBack(2);
  list.print();
  list.pushBack(11);

  list.print();

  list.insertNode(0, 15);
  list.insertNode(3, 20);

  list.print();

  list.deleteOdd();

  list.print();

  list.printLength();

  std::cout << "Nodes created: " << nodes_created << '\n';
  std::cout << "Nodes deleted: " << nodes_deleted << '\n';
  printf("Exiting...\n");
  return EXIT_SUCCESS;
}
