#include <iostream>
using namespace std;

string encrypt(string message, int key) {
  string result = "";
  for (int i = 0; i < message.length(); i++) {
    char c = message[i];
    if (isalpha(c)) {
      c = toupper(c);
      c = ((c - 65) + key) % 26 + 65;
    }
    result += c;
  }
  return result;
}

string decrypt(string message, int key) {
  string result = "";
  for (int i = 0; i < message.length(); i++) {
    char c = message[i];
    if (isalpha(c)) {
      c = toupper(c);
      c = ((c - 65) - key + 26) % 26 + 65;
    }
    result += c;
  }
  return result;
}

int main() {
  string message, encrypted, decrypted;
  int key;
  
  cout << "請輸入要加密的字串: ";
  getline(cin, message);
  
  cout << "請輸入密鑰: ";
  cin >> key;
  
  encrypted = encrypt(message, key);
  decrypted = decrypt(encrypted, key);
  
  cout << "加密後的字串: " << encrypted << endl;
  cout << "解密後的字串: " << decrypted << endl;
  
  return 0;
}
