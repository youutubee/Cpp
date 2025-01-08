#include <iostream>  
#include <iomanip>  
#include <string>  
#include <cryptopp/aes.h>  
#include <cryptopp/modes.h>  
#include <cryptopp/filters.h>  
#include <cryptopp/hex.h>   // For HexEncoder

using namespace CryptoPP;  
using namespace std;  

int main() {  
    // Key and IV (Initialization Vector) for AES  
    byte key[AES::DEFAULT_KEYLENGTH] = {'k', 'e', 'y', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '0', '1', '1'};  
    byte iv[AES::BLOCKSIZE] = {'i', 'v', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '0', '1', '1', '1'};  
    
    // Message to be encrypted  
    string plainText = "Hello, AES!";  
    string cipherText;  // Declare cipherText as an empty string
    
    // Encrypt using AES in CBC mode  
    CBC_Mode<AES>::Encryption encryptor(key, sizeof(key), iv);  
    StringSource(plainText, true,  
        new StreamTransformationFilter(encryptor,  
            new StringSink(cipherText)  // Store the result in cipherText
        )
    );  
    
    // Display the encrypted message in hexadecimal format  
    cout << "Encrypted Text: ";  
    string encoded;  // This will hold the encoded ciphertext
    StringSource(cipherText, true,  
        new HexEncoder(  
            new StringSink(encoded)  // Store the hexadecimal result in a string
        )
    );  
    cout << encoded << endl;  // Print the encoded (hex) output to the console

    return 0;  
}
