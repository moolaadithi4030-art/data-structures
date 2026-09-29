#include <stdio.h>
#include <string.h>
char* reversePrefix(char* word, char ch) {
    char* target = strchr(word, ch);
    if (target != NULL) {
        int left = 0;
        int right = target - word;
        while (left < right) {
            char temp = word[left];
            word[left] = word[right];
            word[right] = temp;
            left++;
            right--;
        }
    }

    return word;
}

int main() {
    char word[251];
    char ch;
    printf("enter str: ");
    scanf("%250s", word);
    printf("enter ch: ");
    scanf(" %c", &ch);
    printf("Resulting string: %s\n", reversePrefix(word, ch));

    return 0;
}
