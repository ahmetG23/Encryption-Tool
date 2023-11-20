#include<bits/stdc++.h>
using namespace std;

struct Node {
    char c;
    bool is_char;
    Node *left, *right;

    Node() : left(nullptr), right(nullptr), is_char(false) {}
    
    void add_code(const char& ch, const string& code, int iter = 0) {
        if(iter == code.size()) {
            c = ch;
            is_char = true;
        } else {
            if(code[iter] == '0') {
                if(left == nullptr) left = new Node();
                left->add_code(ch, code, iter+1);
            }
            else {
                if(right == nullptr) right = new Node();
                right->add_code(ch, code, iter+1);
            }
        }
    }
    pair<char, int> find_char(const string& message, int iter) {
        if(is_char) {
            return {c, iter};
        } else {
            if(message[iter] == '0') {
                if(left == nullptr) {
                    cout << "The message or key has been given uncorrectly. Please try again later.";
                    exit(0);    
                }
                return left->find_char(message, iter+1); cerr << "Going left!\n";
            }else {
                if(right == nullptr) {
                    cout << "The message or key has been given uncorrectly. Please try again later.";
                    exit(0);    
                }
                return right->find_char(message, iter+1); cerr << "Going right!\n";
            }
        }
    }
};

int main() {
    Node *root = new Node();
    string encrypted_message;

    cout << "Enter the encrypted message first:" << endl;
    cin >> encrypted_message;

    cout << "Enter the required key with the suitable form please:" << endl;

    int data_num;
    cin >> data_num;

    for(int i = 0; i < data_num; i++) {
        int ch; 
        string code;
        cin >> ch >> code;
        root->add_code((char)ch, code);
    }

    string decrypted_message;
    int idx = 0;
    while(idx < encrypted_message.length()) {
        auto p = root->find_char(encrypted_message, idx);
        decrypted_message += p.first;
        idx = p.second;
    }

    cout << "Decrypted message is:" << endl << decrypted_message;
    return 0;
}
