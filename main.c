#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse Code alphabet
char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Define the binary tree structure
typedef struct tree{
   char letter;
   struct tree *dot;
   struct tree *dash;
}Tree;

// Create a new node in the binary tree
Tree *create_node(char letter) {
   Tree new_node = (Tree)malloc(sizeof(Tree));
   new_node->letter = letter;
   new_node->dot = NULL;
   new_node->dash = NULL;
   return new_node;
}

// Insert a new letter into the binary tree
void insert_letter(Tree *root, char letter, char *code) {
   int i;
   for (i = 0; i < strlen(code); i++) {
       if (code[i] == '.') {
           if (root->dot == NULL) {
               root->dot = create_node('\0');
           }
           root = root->dot;
       } else if (code[i] == '-') {
           if (root->dash == NULL) {
               root->dash = create_node('\0');
           }
           root = root->dash;
       }
   }
   root->letter = letter;
}

// Search for a letter in the binary tree using Morse Code
char search_letter(Tree *root, char *code) {
   int i;
   for (i = 0; i < strlen(code); i++) {
       if (code[i] == '.') {
           if (root->dot == NULL) {
               return '\0';
           }
           root = root->dot;
       } else if (code[i] == '-') {
           if (root->dash == NULL) {
               return '\0';
           }
           root = root->dash;
       }
   }
   return root->letter;
}

// Create the binary tree using the Morse Code alphabet
void create_tree(Tree *root) {
   int i;
   for (i = 0; i < 26; i++) {
       insert_letter(root, 'A' + i, morse[i]);
   }
}

int main() {
   Tree *root = create_node('\0');
   create_tree(root);
   char input[100];
   printf("Enter morse code letter by letter: ");

   while(strcmp(input,"END")!=0)
   {
    scanf("%s", input);
    printf("%c", search_letter(root, input));
   }
   return 0;
}
