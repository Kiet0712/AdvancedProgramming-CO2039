#include <iostream>

template <typename T>
class Node {
public:
  T data;
  Node* next;

  Node(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
public:
  LinkedList() : head(nullptr) {}

  void append(const T& data) {
    Node<T>* new_node = new Node<T>(data);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    Node<T>* last_node = head;
    while (last_node->next) {
      last_node = last_node->next;
    }
    last_node->next = new_node;
  }

  // Iterator class nested within LinkedList
  class ListIterator {
  public:
    ListIterator(Node<T>* head) : current(head) {}

    // Dereference operator to access data
    T& operator*() { return current->data; }

    // Increment operator to move to next node
    ListIterator& operator++() {
      current = current->next;
      return *this;
    }

    // Check if iterator is at the end (current is nullptr)
    bool operator!=(const ListIterator& other) const {
      return current != other.current;
    }

    // Move-to-next operator (similar to pre-increment)
    ListIterator operator++(int) {
      ListIterator temp = *this;
      ++(*this);
      return temp;
    }

  private:
    Node<T>* current;
  };

  // Begin iterator to start iterating from the head
  ListIterator begin() { return ListIterator(head); }

  // End iterator to mark the end (nullptr)
  ListIterator end() { return ListIterator(nullptr); }

private:
  Node<T>* head;
};

int main() {
  LinkedList<int> my_list;
  my_list.append(1);
  my_list.append(2);
  my_list.append(3);

  // Using for loop with iterator
  for (auto it = my_list.begin(); it != my_list.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}
