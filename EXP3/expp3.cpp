#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string encryption(string Name, int key)
{
for(int i=0;i<Name.length();i++)
{
Name[i] += key;
}
return Name;
}
string decryption(string Name, int key)
{
for(int i=0;i<Name.length();i++)
{
Name[i] -= key;
}
return Name;
}
string Caesar_encryption(string Name, int key)
{
for(int i=0;i<Name.length();i++)
{
int num = Name[i] -'a';
num = (num+key)%26 +'a';
Name[i] = char(num);
}
return Name;
}
string Caesar_decryption(string Name, int key)
{
for(int i=0;i<Name.length();i++)
{
int num = Name[i] -'a';
num = (num-key)%26 +'a';
Name[i] = char(num);
}
return Name;
}
int main() {
 ifstream file("Data.txt"); // Open the file
 if (!file.is_open()) {
 cerr << "Failed to open the file." << endl;
 return 1; // Exit if file cannot be opened
 }
 string sentence;
 getline(file, sentence); // Read the first sentence/line from the file
 //cout << "The sentence is: " << sentence << endl;

 int key;
 cout<<"Enter Key";
 cin>>key;
cout << "The Original Text is: " << sentence << endl;
 string encrypted = Caesar_encryption(sentence,key);
cout<<"The Encrypted Text is : "<<encrypted<< endl;
string decrypted = Caesar_decryption(encrypted,key);
cout<<"The Encrypted Text is : "<<decrypted<< endl;
 file.close(); // Close the file
 return 0;
}