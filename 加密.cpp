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
  
  cout << "�п�J�n�[�K���r��: ";
  getline(cin, message);
  
  cout << "�п�J�K�_: ";
  cin >> key;
  
  encrypted = encrypt(message, key);
  decrypted = decrypt(encrypted, key);
  
  cout << "�[�K�᪺�r��: " << encrypted << endl;
  cout << "�ѱK�᪺�r��: " << decrypted << endl;
  
  return 0;
}
