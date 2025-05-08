    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm> // for sort
    using namespace std;

    string encrypt(string key, string plain_text) {
        int key_len = key.length();
        int pt_len = plain_text.length();

        // Step 1: Count rows correctly
        int rows = (pt_len + key_len - 1) / key_len + 1;

        // Step 2: Create grid (including key row)
        vector<string> grid(rows, string(key_len, ' '));

        // First row is the key
        grid[0] = key;

        // Step 3: Fill the grid with plain text
        int index = 0;
        for (int r = 1; r < rows; r++) {
            for (int c = 0; c < key_len && index < pt_len; c++) {
                grid[r][c] = plain_text[index++];
            }
        }

        // Step 4: Sort the key to decide column order
        string sorted_key = key;
        sort(sorted_key.begin(), sorted_key.end());

        // Step 5: Generate Cipher Text
        string cipher;
        for (char ch : sorted_key) {
            // Important: Use a loop in case of repeated characters in key
            for (int i = 0; i < key_len; i++) {
                if (key[i] == ch) {
                    for (int r = 1; r < rows; r++) {
                        cipher += grid[r][i];
                    }
                    // Mark column used to avoid duplicate usage if character repeats
                    key[i] = '\0';
                    break;
                }
            }
        }
        cout<<"Printing MAtrix : "<<endl ;
        for(auto i : grid){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<endl ;
        }

        return cipher;
    }

    string decrypt(string key,string cipher){
        int key_len = key.length() ;
        int cipher_len = cipher.length() ;
        
        int rows = (key_len + cipher_len -1)/key_len + 1 ;
        
        vector<string>grid(rows,string(key_len,' ')) ;
        
        string sorted_key = key ;
        
        sort(sorted_key.begin(),sorted_key.end()) ;
        int index = 0 ; 
        for(char ch : sorted_key){
            for(int i = 0 ; i < key_len ; i++){
                if(key[i] == ch){
                    for(int r = 1 ; r < rows && index < cipher_len; r++){
                        grid[r][i] = cipher[index++] ;
                    }
                    key[i] = '\0' ;
                    break ;
                }
            }
        }
        string plain_text  ;
        for(int r = 1 ; r < rows ; r++ ){
            for(int c = 0 ; c < key_len ; c++)
            {
                plain_text += grid[r][c] ;
            }
        }
        return plain_text ;
    }

    int main() {
        string key = "MEGABUCK";
        string plain_text = "please transfer one million dollars to my swiss bank account six two two four";

        cout << "KEY : " << key << endl;
        cout << "Plain Text : " << plain_text << endl;

        string encrypted_text = encrypt(key, plain_text);
        cout << "Encrypted Text : " << encrypted_text << endl;
        string decrypted_text = decrypt(key,encrypted_text) ;
        cout<<"Decrypted Text : "<<decrypted_text<<endl ;
        return 0;
    }
