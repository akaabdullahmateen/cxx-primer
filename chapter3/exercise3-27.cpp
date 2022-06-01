// Exercise 3.27: Assuming txt_size is a function that takes no arguments and returns an int value
// Which of the following definitions are illegal? Explain why.

constexpr int txt_size()
{
    return 4u;
}

int main()
{
    constexpr unsigned buf_size = 1024;

    int ia[buf_size];
    int ib[4 * 7 - 14];
    int ic[txt_size()];

    // error: initializer-string for ‘char [11]’ is too long
    char st[12] = "fundamental";

    return 0;
}