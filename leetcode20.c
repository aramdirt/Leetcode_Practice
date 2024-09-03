bool isValid(char* s) {
    bool result = true;
    int i;
    int flag = -1;
    char char_arr[strlen(s)];

    for (i = 0; i < strlen(s); i++)
    {
        switch(s[i])
        {
            case '{':
            case '[':
            case '(':
                char_arr[++flag] = s[i];
                break;

            case '}':
                if (flag < 0)
                {
                    result = false;
                    break;
                }
                if (char_arr[flag--] != '{')
                    result = false;

                break;

            case ']':
                if (flag < 0)
                {
                    result = false;
                    break;
                }
                if (char_arr[flag--] != '[')
                    result = false;

                break;

            case ')':
                if (flag < 0)
                {
                    result = false;
                    break;
                }
                if (char_arr[flag--] != '(')
                    result = false;

                break;
        }

        if (!result)
            break;
    }

    if (flag > 0)
        result = false;

    return result;
}