#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define SUIT_SPADES 0
#define SUIT_CLUBS 1
#define SUIT_DIAMONDS 2
#define SUIT_HEARTS 3

const wchar_t *suit_name(const int i)
{
    switch (i) {
    case SUIT_SPADES: return L"ø";
    case SUIT_CLUBS: return L"å";
    case SUIT_DIAMONDS: return L"æ";
    case SUIT_HEARTS: return L"Ø";
    default: return L"";
    }
}

int main(void)
{
    /* Let's use the locale the user wants to. */
    setlocale(LC_ALL, "");

    /* Let's also use wide standard output. */
    fwide(stdout, 1);

    wprintf(L"Hearts is %ls, clubs %ls, diamonds %ls, and spades %ls.\n",
           suit_name(SUIT_HEARTS), suit_name(SUIT_CLUBS),
           suit_name(SUIT_DIAMONDS), suit_name(SUIT_SPADES));

    return EXIT_SUCCESS;
}
