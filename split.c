#include "pipex.h"

static size_t count_words(const char *s, char d)
{
    size_t i = 0, count = 0;

    if (!s)
        return 0;
    while (s[i])
    {
        while (s[i] && s[i] == d)
            i++;
        if (s[i] && s[i] != d)
        {
            count++;
            while (s[i] && s[i] != d)
                i++;
        }
    }
    return count;
}

static char *substr_dup(const char *s, size_t start, size_t len)
{
    char *out = (char *)malloc(len + 1);
    size_t i;

    if (!out)
        return NULL;
    for (i = 0; i < len; i++)
        out[i] = s[start + i];
    out[len] = '\0';
    return out;
}

char **ft_split(const char *s, char d)
{
    size_t  i = 0, j = 0, start, words;
    char    **arr;

    words = count_words(s, d);
    arr = (char **)malloc(sizeof(char *) * (words + 1));
    if (!arr)
        return NULL;
    while (s && s[i])
    {
        while (s[i] && s[i] == d)
            i++;
        if (!s[i])
            break;
        start = i;
        while (s[i] && s[i] != d)
            i++;
        arr[j] = substr_dup(s, start, i - start);
        if (!arr[j])
        {
            free_strarray(arr);
            return NULL;
        }
        j++;
    }
    arr[j] = NULL;
    return arr;
}

void free_strarray(char **arr)
{
    size_t i = 0;

    if (!arr)
        return;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}