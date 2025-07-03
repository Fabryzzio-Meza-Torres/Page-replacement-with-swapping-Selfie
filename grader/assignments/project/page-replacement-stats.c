int main() {
    int *pages[100];
    int i;
    
    printf("Starting page replacement statistics test\n");
    
    i = 0;
    while (i < 100) {
        pages[i] = malloc(4096);
        if (pages[i] == 0) break;
        
        *(pages[i]) = i * 999;
        
        if (i % 25 == 0) {
            printf("Allocated %d pages so far\n", i + 1);
        }
        
        i = i + 1;
    }
    
    printf("Page replacement statistics test completed\n");
    return 42;
}
