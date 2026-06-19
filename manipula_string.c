int tamanho_strring(char *string)
{
    int tamanho = 0;
    while (*string != '\0')
    {
        tamanho++;
        string++;
    }
    return tamanho;
}