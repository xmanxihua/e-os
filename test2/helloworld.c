int helloworld(unsigned int* uart,char* str) {
    while (*str) {
        *uart = (unsigned int)(*str);
        ++str;
    }
    return 0;
}