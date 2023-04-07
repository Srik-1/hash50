#Hash Generator#
This program generates hashes for keys using different hash functions. You can choose from four different hash functions: Simple, Complex, Speller, and MurMur. You can also choose to generate hashes for a single key or multiple keys in one go with the same hash.

##Getting Started
Clone the repository or download the source code files.
Compile the program using a C compiler of your choice.
Run the compiled executable to start the program.
##Usage
Choose the mode of operation:
1 for Single Key mode: You can enter a single key and select a hash function to generate the hash for that key.
2 for Multiple Keys mode: You can enter the number of keys you want to generate hashes for and select a hash function to generate the hashes for those keys.
Enter the key(s) for which you want to generate hashes.
##Choose a hash function:
1 for Simple hash: Generates a hash using a simple hash function that calculates the sum of ASCII values of characters in the key.
2 for Complex hash: Generates a hash using a complex hash function that calculates the sum of ASCII values of characters squared and added to the sum of ASCII values of characters in the key.
3 for Speller hash: Generates a hash using a speller hash function that calculates the sum of ASCII values of characters in the key multiplied by a constant value.
4 for MurMur hash: Generates a hash using the MurMur hash function, a non-cryptographic hash function that takes a seed value as an additional parameter.
If you chose Simple, Complex, or Speller hash, you can optionally enter a range or maximum value for the hash (type 0 to leave it at the default).
The program will display the generated hash(es) for the key(s) based on the selected hash function.
Hash Functions
Simple Hash
The Simple hash function calculates the sum of ASCII values of characters in the key, multiplied by the position of the character in the key. If a range or maximum value is specified, the hash is calculated as the sum modulo the range or maximum value.

###Complex Hash
The Complex hash function calculates the sum of ASCII values of characters squared and added to the sum of ASCII values of characters in the key. If a range or maximum value is specified, the hash is calculated as the sum modulo the range or maximum value.

###Speller Hash
The Speller hash function calculates the sum of ASCII values of characters in the key multiplied by a constant value (33). If a range or maximum value is specified, the hash is calculated as the sum modulo the range or maximum value.

###MurMur Hash
The MurMur hash function is a non-cryptographic hash function that takes a seed value as an additional parameter. It calculates the hash using bitwise and arithmetic operations on the bytes of the key. The resulting hash is a 32-bit unsigned integer.

Contributing
If you would like to contribute to this project, you can fork the repository and submit a pull request with your changes.

License
-

Acknowledgements
This program uses the MurMur hash function implementation by Austin Appleby.
