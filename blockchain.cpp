#include <iostream>
#include <sstream>
#include <ctime>
#include <cstring>
#include <vector>
#include <iomanip>
#include <openssl/sha.h>
#include <unistd.h>

using namespace std;

// Get current timestamp
string getTimestamp() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    stringstream ss;
    ss << put_time(ltm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// Hash function using SHA-256
string calculateHash(const string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input.c_str(), input.length(), hash);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    return ss.str();
}

// Block class
class Block {
public:
    int index;
    string timestamp;
    string data;
    string previousHash;
    string hash;
    Block* next;

    Block(int idx, const string& data, const string& prevHash) {
        this->index = idx;
        this->data = data;
        this->previousHash = prevHash;
        this->timestamp = getTimestamp();
        this->hash = calculateHash(toString());
        this->next = nullptr;
    }

    string toString() const {
        stringstream ss;
        ss << index << timestamp << data << previousHash;
        return ss.str();
    }

    void print() const {
        cout << "Index: " << index << endl;
        cout << "Timestamp: " << timestamp << endl;
        cout << "Data: " << data << endl;
        cout << "Previous Hash: " << previousHash << endl;
        cout << "Hash: " << hash << endl;
        cout << "-------------------------------" << endl;
    }
};

// Blockchain class
class Blockchain {
private:
    Block* head;
    Block* tail;
    int size;

public:
    Blockchain() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void addBlock(const string& data) {
        if (head == nullptr) {
            head = new Block(0, data, "0");
            tail = head;
        } else {
            Block* newBlock = new Block(size, data, tail->hash);
            tail->next = newBlock;
            tail = newBlock;
        }
        size++;
    }

    void printChain() const {
        Block* current = head;
        while (current != nullptr) {
            current->print();
            current = current->next;
        }
    }

    bool validateChain() const {
        Block* current = head;
        while (current && current->next) {
            if (current->next->previousHash != current->hash) {
                cout << "Chain broken at index: " << current->index << endl;
                return false;
            }
            if (current->hash != calculateHash(current->toString())) {
                cout << "Hash mismatch at index: " << current->index << endl;
                return false;
            }
            current = current->next;
        }
        return true;
    }

    ~Blockchain() {
        Block* current = head;
        while (current != nullptr) {
            Block* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Interactive CLI
int main() {
    Blockchain chain;
    string input;

    cout << "Welcome to BlockchainRxn" << endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add New Block\n";
        cout << "2. Print Blockchain\n";
        cout << "3. Validate Blockchain\n";
        cout << "4. Exit\n";
        cout << "Choose an option (1-4): ";
        getline(cin, input);

        if (input.empty()) {
            cout << "Invalid option, try again.\n";
            continue;
        }

        char choice = input[0];

        switch (choice) {
            case '1': {
                cout << "Enter transaction data: ";
                string data;
                getline(cin, data);
                chain.addBlock(data);
                cout << "Block added.\n";
                break;
            }
            case '2': {
                cout << "Blockchain:\n";
                chain.printChain();
                break;
            }
            case '3': {
                cout << "Validating chain...\n";
                if (chain.validateChain()) {
                    cout << "Blockchain is valid.\n";
                } else {
                    cout << "Blockchain is INVALID.\n";
                }
                break;
            }
            case '4': {
                cout << "Exiting...\n";
                return 0;
            }
            default: {
                cout << "Invalid option, try again.\n";
                break;
            }
        }
    }

    return 0;
}
