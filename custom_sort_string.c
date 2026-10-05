#include <string.h>
#include <stdlib.h>

char* customSortString(char* order, char* s) {
    int count[26] = {0};
    int sLen = strlen(s);
    int oLen = strlen(order);
    
    for (int i = 0; i < sLen; i++) {
        count[s[i] - 'a']++;
    }
    
    char* result = (char*)malloc(sizeof(char) * (sLen + 1));
    int idx = 0;
    
    for (int i = 0; i < oLen; i++) {
        int charIdx = order[i] - 'a';
        while (count[charIdx] > 0) {
            result[idx++] = order[i];
            count[charIdx]--;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            result[idx++] = i + 'a';
            count[i]--;
        }
    }
    
    result[idx] = '\0';
    return result;
}
