#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char* s, char* t) {
    int sToT[256] = {0};
    int tToS[256] = {0};
    
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        unsigned char sChar = (unsigned char)s[i];
        unsigned char tChar = (unsigned char)t[i];
        
        if (sToT[sChar] == 0 && tToS[tChar] == 0) {
            sToT[sChar] = tChar;
            tToS[tChar] = sChar;
        } 
        else if (sToT[sChar] != tChar || tToS[tChar] != sChar) {
            return false;
        }
    }
    
    return true;
}
