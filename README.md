# Secret-Message-Project

This is a encryption and decryption tool that can convert a message into a secret-code consisting of just **0s and 1s**.

## Features
- This tool encrypts a message **in the shortest way possible** using *Huffman Coding Algorithm*, which enhances its memory efficiency.
- The tool also has a **decryptor**, which makes it possible to decrypt a secret-code with its appropriate key data.

#### Time complexity:
- Encryptor: O(klogk), except the reading and writing processes (k is the number of different characters in the given message)
- Decryptor: O(n) (n is the length of the secret-code)

#### Memory complexity:
- Encryptor: *[will be specicified later]*
- Decryptor: O(n) (n is the length of the secret-code)
