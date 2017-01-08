//I am frustrated
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(string a);
bool acceptable(int c, string b);
string key;
string message;





int main(int argc, string argv[]) {
     if (acceptable (argc, key)) {
         key = (argv[1]);
         message = GetString();
     }
     
     else {
         printf("Please give me a valid keyword next time\n");
         return 1;  
     }

      encrypt(message);
      printf("\n");
}

bool acceptable(int c, string b) {
     int t = 0;
     int f = 0;
     for (int i = 0, n = strlen(b); i < n; i++) {
         if (c == 2 && isalpha(b[i])) {
             t++;
         }
         
         else {
             f++;
         }
     }
     
     if (t == strlen(b)) {
         return true;
     }
     
     else {
         return false;
     }
}

void encrypt (string a) {
     
     int alphabet;
     int encrypted;
     int change;
     int j = 0;
   
      for (int i = 0, n = strlen(a); i < n; i++) {
             if((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122)) {
                 if (isupper(a[i])) {
                     alphabet = a[i] - 65;
                 }
         
                 else {
                     alphabet = a[i] - 97;
                 }
                 
                 int tracker = (j % (strlen(key)));    
                 if (isupper(key[tracker])) {
                     change = key[tracker] - 65;
                 }
         
                 else {
                     change = key[tracker] - 97;
                 }
                 j++;
                     
                 encrypted = (alphabet + change) % 26;
         
                 if (isupper(a[i])) {
                     printf("%c", encrypted + 65);
                 }
         
                 else {
                     printf("%c", encrypted + 97);
                 }
             }
             else {
                 printf("%c", a[i]);
             }
         }
}
