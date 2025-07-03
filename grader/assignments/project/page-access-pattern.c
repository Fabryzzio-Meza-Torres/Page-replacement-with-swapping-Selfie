int main() {
    int *pages[10];
    int i;
    
    i = 0;
    while (i < 10) {
        pages[i] = malloc(4096);
        *(pages[i]) = i * 1000;
        i = i + 1;
    }
    
    i = 0;
    while (i < 10) {
        *(pages[i]) = *(pages[i]) + 1;
        i = i + 1;
    }
    
    i = 0;
    while (i < 10) {
        if (i % 2 == 0) {
            *(pages[i]) = *(pages[i]) + 100;
        }
        i = i + 2;
    }
    
    i = 0;
    while (i < 50) {
        int *temp;
        temp = malloc(4096);
        if (temp != 0) {
            *temp = i + 9999;
        }
        i = i + 1;
    }
    
    printf("Page access pattern test completed\n");
    return 42;
}
