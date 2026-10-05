#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool matchesPattern(char* word, char* pattern) {
    char wToP[26] = {0}; 
    char pToW[26] = {0}; 
    int len = strlen(pattern);
    
    for (int i = 0; i < len; i++) {
        int wChar = word[i] - 'a';
        int pChar = pattern[i] - 'a';
        
        if (wToP[wChar] == 0 && pToW[pChar] == 0) {
            wToP[wChar] = pattern[i];
            pToW[pChar] = word[i];
        } 
        else if (wToP[wChar] != pattern[i] || pToW[pChar] != word[i]) {
            return false;
        }
    }
    return true;
}

char** findAndReplacePattern(char** words, int wordsSize, char* pattern, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    int count = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        if (matchesPattern(words[i], pattern)) {
            result[count++] = words[i];
        }
    }
    
    *returnSize = count;
    return result;
}
