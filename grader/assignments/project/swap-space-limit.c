int main() {
    int *pages[500];
    int i;
    int successful_allocs;
    
    printf("Testing swap space limits\n");
    
    i = 0;
    successful_allocs = 0;
    
    while (i < 500) {
        pages[i] = malloc(4096);
        
        if (pages[i] == 0) {
            printf("Allocation failed at page %d\n", i);
            break;
        }
        
        *(pages[i]) = i * 12345;
        *(pages[i] + 511) = i * 54321;
        
        successful_allocs = successful_allocs + 1;
        
        if (i % 100 == 0) {
            printf("Allocated %d pages\n", i + 1);
        }
        
        i = i + 1;
    }
    
    printf("Successfully allocated %d pages\n", successful_allocs);
    
    if (successful_allocs > 100) {
        return 42;
    } else {
        return 1;
    }
}
