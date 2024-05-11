#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <fstream>
#include "../node/Node.h"

template <typename T>
class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        LinkedList() {
            head = nullptr; 
            tail = nullptr;
        }

        ~LinkedList() {
            while (head != nullptr) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
        }

        void append(T data) {
            Node<T>* newNode = new Node<T>(data);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } 
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void display() const {
            Node<T>* temp = head;
            while (temp != nullptr) {
                std::cout << temp->data << std::endl;
                temp = temp->next;
            }
        }

        void displayRolls() const {
            Node<T>* temp = head;
            while (temp != nullptr) {
                std::cout << temp->data << " + ";
                temp = temp->next;
                std::cout << temp->data << " = ";
                temp = temp->next;
                std::cout << temp->data << std::endl;
                temp = temp->next;
            }
        }

        void outputTHToFile () const {
            Node<T>* temp = head;
            std::ofstream outFile;

            outFile.open("../transactionhistory.txt");

            if (!outFile.is_open()) {
                std::cerr << "Error! Unable to open file: transactionhistory.txt";
            }

            outFile << "Transaction history:\n";

            while (temp != nullptr) {
                outFile << temp->data << std::endl;
                temp = temp->next;
            }

            outFile.close();    
        }

        void outputRHToFile () const {
            Node<T>* temp = head;
            std::ofstream outFile;

            outFile.open("../rollhistory.txt");

            if (!outFile.is_open()) {
                std::cerr << "Error! Unable to open file: rollhistory.txt";
            }

            outFile << "Roll history:\n";

            while (temp != nullptr) {
                outFile << temp->data << " + ";
                temp = temp->next;
                outFile << temp->data << " = ";
                temp = temp->next;
                outFile << temp->data << std::endl;
                temp = temp->next;
            }

            outFile.close();    
        }
};

#endif