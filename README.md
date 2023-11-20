# Encryption-Tool

This is an encryption and decryption tool that can convert a message into a secret-code consisting of just **0s and 1s**.

## Features
- This tool encrypts a message **in the shortest way possible** using the *Huffman Coding Algorithm*, which enhances its memory efficiency.
- The tool also has a **decryptor**, which makes it possible to decrypt a secret-code with its appropriate key data.
- Cross-platform and no extra library is used

## Process
The tool contains two compilable C++ files, one for encryption and the other for decryption. 
- You can compile the C++ files using c++17 or a newer standard. No additional flag is needed.
1. Compiled and run in a terminal, the *encrypt.cpp* file produces two output files - *encrypted_message.txt* and *key.txt* according to the input message it takes.
2. Compiled and run in a terminal, the *encrypt.cpp* file takes two standard inputs - the encrypted message (secret-code) and the key of it. After that, it outputs the original message in stdout. 

#### Time complexity:
- Encryptor: O(klogk), except the reading and writing processes (k is the number of different characters in the given message)
- Decryptor: O(n) (n is the length of the secret-code)

#### Memory complexity:
- Encryptor: *[will be specified later]*
- Decryptor: O(n) (n is the length of the secret-code)
