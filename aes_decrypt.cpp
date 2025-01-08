#include <iostream>  
#include <iomanip>  
#include <string>  
#include <cryptopp/aes.h>  
#include <cryptopp/modes.h>  
#include <cryptopp/filters.h>  
  
using namespace CryptoPP;  
using namespace std;  
  
int main() {  
 // Key and IV for AES (same as used for encryption)  
 byte key[AES::DEFAULT_KEYLENGTH] = {'k', 'e', 'y', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '0', '1', '1'};  
 byte iv[AES::BLOCKSIZE] = {'i', 'v', '1', '2', '3', '4', '5', '6', '7', '8', '9', '1', '0', '1', '1', '1'};  
  
 // Encrypted message  
 string cipherText = "2BA45BB007A68005E481D46BBD64EFE8";  
 
  
 // Decrypt using AES in CBC mode  
 CBC_Mode<AES>::Decryption decryptor(key, sizeof(key), iv);  
 StringSource(cipherText, true, new HexDecoder(new StreamTransformationFilter(decryptor, new StringSink(plainText))));  
  
 // Display the decrypted message  
 cout << "Decrypted Text: " << plainText << endl;  
  
 return 0;  
}  