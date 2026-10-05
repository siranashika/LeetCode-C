#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char* s) {
    int len = strlen(s);
    if (len <= 1) return false;

    char doubled[20005];
    strcpy(doubled, s);
    strcat(doubled, s);

    char* match = strstr(doubled + 1, s);

    if (match != NULL && (match - doubled) < len) {
        return true;
    }

    return false;
}
