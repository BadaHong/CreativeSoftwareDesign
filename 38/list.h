#include <iostream>

using namespace std;

template <class T>
class Node
{
        public:
                T data;
                Node<T>* next;
};

template <class T>
class List {
        private:
                Node<T> *head;
        public:
                List() : head(NULL) {};
                ~List(){
                        Node<T> *n = head;
                        while(n != NULL){
                                Node<T> *temp = n;
                                n = n->next;
                                delete temp;
                        }
                }

                List(T* arr, int n_nodes){
                        head = new Node<T>();
                        head->data = arr[0];
                        head->next = NULL;

                        Node<T> *n = head;
                        for(int i = 1; i < n_nodes; i++){
                                Node<T> *nn = new Node<T>();
                                nn->data = arr[i];
                                nn->next = NULL;
                                n->next = nn;
                                n = n->next;
                        }
                }

                void insert_at(int idx, const T& data){
                        if(idx == 0){
                                push_front(data);
                        }
                        else{
                                Node<T> *n = head;
                                int count = 0;
                                while(n != NULL){
                                        count++;
                                        if(count == idx){
                                                Node<T> *nn = new Node<T>();
                                                nn->data = data;
                                                nn->next = n->next;
                                                n->next = nn;
                                                break;
                                        }
                                        n = n->next;
                                }
                        }
                }

                void remove_at(int idx){
                        if(idx == 0){
                                pop_front();
                        }
                        else{
                                Node<T> *n = head;
                                int count = 0;
                                while(n != NULL){
                                        count++;
                                        if(count == idx){
                                                Node<T> *temp = n->next;
                                                Node<T> *nn = temp->next;
                                                n->next = nn;
                                                delete temp;
                                                break;
                                        }
                                        n = n->next;
                                }
                        }
                }
                void pop_back(){
                        Node<T> *n = head;
                        while(n != NULL){
                                Node<T> *nn = n->next;
                                if(nn->next == NULL){
                                        n->next = NULL;
                                        delete nn;
                                        break;
                                }
                                n = n->next;
                        }
                }

                void push_back(const T& val){
                        Node<T> *n = head;
                        while(n != NULL){
                                if(n->next == NULL){
                                        Node<T> *nn = new Node<T>();
                                        nn->data = val;
                                        nn->next = NULL;
                                        n->next = nn;
                                        break;
                                }
                                n = n->next;
                        }
                }

                void pop_front(){
                        Node<T> *n = head;
                        head = n->next;
                        delete n;
                }

                void push_front(const T& val){
                        Node<T> *n = head;
                        Node<T> *nn = new Node<T>();
                        nn->data = val;
                        nn->next = n;
                        head = nn;
                }

                friend ostream& operator<<(ostream& out, List& rhs){
                        Node<T> *n = rhs.head;
                        while(n != NULL){
                                if(n->next == NULL){
                                        out << n->data;
                                }
                                else{
                                        out << n->data << ",";
                                }
                                n = n->next;
                        }
                        return out;
                }
};

