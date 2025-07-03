int main() {
    int *ptrs[200];
    int i;
    int size;
    
    i = 0;
    size = 4096;
    
    while (i < 200) {
        ptrs[i] = malloc(size);
        
        if (ptrs[i] == 0) {
            printf("Allocation failed at %d\n", i);
            return 1;
        }
        
        *(ptrs[i]) = i + 1000;
        
        if (i % 50 == 0) {
            printf("Allocated page %d\n", i);
        }
        
        i = i + 1;
    }
    
    printf("Memory stress test completed\n");
    return 42;
}
