// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	if(destination == NULL){
		return NULL;
	}

	char *ptr = destination;

	while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

	*destination = '\0';
	return ptr;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *dest = destination;

    /* Copiem caractere din sursă în destinație până când ajungem 
    la lungimea specificată sau la sfârșitul șirului sursă. */
    while (*source != '\0' && len > 0) {
        *dest = *source;
        dest++;
        source++;
        len--;
    }

    // Completați destinația cu caractere nule până când se atinge lungimea specificată.
    while (len > 0) {
        *dest = '\0';
        dest++;
        len--;
    }

    return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char* ptr = destination + strlen(destination);

	while (*source != '\0') {
        *ptr++ = *source++;
    }

	*ptr = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char* ptr = destination + strlen(destination);

	 while (*source != '\0' && len--) {
        *ptr++ = *source++;
    }

	*ptr = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1)
	{
		if(*str1 != *str2){
			break;
		}
		str1++;
		str2++;
	}
	return *(const unsigned char*)str1 - *(const unsigned char*)str2;
	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (len > 0 && *str1 != '\0' && *str2 != '\0' && *str1 == *str2)
    {
        str1++;
        str2++;
        len--;
    }
    if (len == 0) return 0;
    return *(unsigned char*)str1 - *(unsigned char*)str2;
	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while (*str != '\0')
    {
        if (*str == (char)c)
            return (char *)str;

        str++;
    }

    return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *last = NULL; // Variabilă pentru a ține ultimul pointer la caracter găsit.

    while (*str != '\0')
    {
        if (*str == (char)c)
            last = (char *)str; // Actualizăm pointerul la ultimul caracter găsit.

        str++;
    }

    if (last != NULL)
        return last; // Returnăm pointerul la ultimul caracter găsit.
    else
        return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (*needle == '\0') {
        return (char *)haystack; // Dacă șirul needle este gol, returnăm haystack.
    }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack; // S-a găsit o potrivire pentru needle.
        }

        haystack++; // Trecem la următoarea poziție din haystack.
    }

    return NULL; // Nu s-a găsit șirul needle în haystack.
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if (*needle == '\0') {
        return (char *)haystack; // Dacă șirul needle este gol, returnăm haystack.
    }

    const char *last = NULL; // Variabilă pentru a ține ultimul pointer la șirul needle.

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            last = haystack; // S-a găsit o potrivire pentru needle.
        }

        haystack++; // Trecem la următoarea poziție din haystack.
    }

    if (last != NULL) {
        return (char *)last; // Returnăm pointerul la ultima apariție a needle în haystack.
    }

    return NULL; // Nu s-a găsit șirul needle în haystack.
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	unsigned char *dest = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;

    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	unsigned char *dest = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;

    if (dest > src && dest < src + num) {
        // Caz de suprapunere în care dest este după src.
        // Copiem de la sfârșit către început pentru a evita suprapunerea.
        dest += num;
        src += num;
        while (num--) {
            *(--dest) = *(--src);
        }
    } else {
        // Altfel, copiem de la început către sfârșit.
        while (num--) {
            *dest++ = *src++;
        }
    }

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
            return -1;  // ptr1 este mai mic decât ptr2
        } else if (p1[i] > p2[i]) {
            return 1;   // ptr1 este mai mare decât ptr2
        }
    }

    return 0; // ptr1 este egal cu ptr2
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	 unsigned char *s = (unsigned char *)source;
    unsigned char v = (unsigned char)value;

    for (size_t i = 0; i < num; i++) {
        s[i] = v;
    }

	return source;
}

//Surse:
	/*https://stackoverflow.com/
    https://www.gnu.org/software/libc/manual/html_mono/libc.html
    https://chat.openai.com/chat
    https://www.techiedelight.com/*/
