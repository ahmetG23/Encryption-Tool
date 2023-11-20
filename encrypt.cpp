#include<bits/stdc++.h>
using namespace std;

struct Node {
    char c;
    bool is_char;
    unsigned cnt;
    Node *left, *right;
    
    Node(unsigned _cnt) : cnt(_cnt), is_char(false) {}  
    Node(char _c, unsigned _cnt) : c(_c), cnt(_cnt), is_char(true) {}  
};

struct Comparator {
    bool operator () (Node* a, Node* b) {
        return a->cnt > b->cnt;
    } 
};

map<char, int> get_freq(const string& message) {
    map<char, int> freq;
    
    for(const char c : message)
        freq[c]++;
    
    return freq;
}

Node* build_tree(priority_queue<Node*, vector<Node*>, Comparator> order) {
    while(order.size() > 1) {
        Node* left = order.top();
        order.pop();

        Node* right = order.top();
        order.pop();

        Node* parent = new Node(left->cnt + right->cnt);
        parent->left = left;
        parent->right = right;

        order.push(parent);
    }
    return order.top();
}

void dfs(Node* cur, string str, map<char, string>& codes) {
    if(!cur) 
        return;

    if(cur->is_char) 
        codes[cur->c] = str;
    
    dfs(cur->left, str + "0", codes);
    dfs(cur->right, str + "1", codes);
}

void print_message(const string& message, const map<char, string>& codes) {
    ofstream out;
    out.open("encrypted_message.txt");

    for(const char c: message) {
        out << codes.at(c);
    }
    out.close();
}

void print_key(const map<char, string>& codes) {
    ofstream out;
    out.open("key.txt");

    out << codes.size() << endl;
    for(auto [c, str]: codes)
        out << (int)c << ' ' << str << endl;
    
    out.close();
}

int main() {
    cout << "Enter your message to encrypt:" << endl;
    
    string message;
    getline(cin, message);

    auto freq = get_freq(message);
    
    priority_queue<Node*, vector<Node*>, Comparator> order;

    for(auto [c, cnt]: freq)
        order.push(new Node(c, cnt));
    
    Node* root = build_tree(order);

    map<char, string> codes;
    dfs(root, "", codes);

    print_message(message, codes);
    print_key(codes);
}
