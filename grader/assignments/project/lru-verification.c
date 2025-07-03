int main() {
    int *page1, *page2, *page3;
    int i;
    
    printf("Testing LRU algorithm\n");
    
    page1 = malloc(4096);
    page2 = malloc(4096);
    page3 = malloc(4096);
    
    *page1 = 111;
    *page2 = 222;
    *page3 = 333;
    
    *page1 = 1111;
    
    i = 0;
    while (i < 100) {
        int *temp;
        temp = malloc(4096);
        if (temp != 0) {
            *temp = i;
        }
        i = i + 1;
    }
    
    if (*page1 == 1111) {
        printf("LRU working correctly\n");
        return 42;
    } else {
        printf("LRU failed\n");
        return 1;
    }
}
