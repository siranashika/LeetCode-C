#include <stdbool.h>

bool isMatch(char* s, char* p) {
    int sIdx = 0, pIdx = 0;
    int sStar = -1, pStar = -1;

    while (s[sIdx] != '\0') {
        if (p[pIdx] == s[sIdx] || p[pIdx] == '?') {
            sIdx++;
            pIdx++;
        } 
        else if (p[pIdx] == '*') {
            pStar = pIdx;
            sStar = sIdx;
            pIdx++;
        } 
        else if (pStar != -1) {
            pIdx = pStar + 1;
            sStar++;
            sIdx = sStar;
        } 
        else {
            return false;
        }
    }

    while (p[pIdx] == '*') {
        pIdx++;
    }

    return p[pIdx] == '\0';
}
