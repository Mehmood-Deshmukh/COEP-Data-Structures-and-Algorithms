#include <stdio.h>
#include <wchar.h>

// Wide characters are a form of character representation about processing a more comprehensive set of characters than the standard single-byte character, usually  char  in C. They come in very handy during the processes of internationalization and providing support to different languages and symbols that cannot be represented using one byte only.

// Characteristics of Wide Characters :
// Size: The wide characters are mostly represented by more than one byte. The size usually varies depending on a system and specific type of wide character used. Example:
//  
// In most of the implementations, wchar_t– the most commonly used wide character type– is 2 bytes on some systems, for example, Windows, and it is 4 bytes on other systems, like most of the Unix-like systems.
// How wide character is encoding: The encoding of wide character may vary. Example:
// On Windows, wchar_t is mostly, encoded as UTF-16.
// In most Unix-like systems, wchar_t is usually encoded in UTF-32.
// Standard Library Support: The standard library of C supports wide characters through several functions and types defined in <wchar.h>, for example:
// Type wchar_t to represent wide characters.
// Functions wprintf(), wscanf(), wcslen(), wcscmp() etc. for I/O and manipulation of wide characters.
// Use Cases:
// These are used to deal with languages/symbols where more than one byte is required per character.
// They are very useful in rendering great assistance to Unicode since it contains many characters and symbols from most of the written alphabets.

int main() {
    wchar_t str1[] = L"Hello";
    wchar_t str2[] = L"World";

    int result = wcscmp(str1, str2);

    if (result == 0) {
        wprintf(L"The strings are equal.\n");
    } else if (result < 0) {
        wprintf(L"The first string is less than the second string.\n");
    } else {
        wprintf(L"The first string is greater than the second string.\n");
    }

    return 0;
}
