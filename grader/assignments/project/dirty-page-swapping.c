int main() {
    int *pages[50];
    int i;
    int expected_values[50];
    int j, k;
    int errors;
    
    printf("Testing dirty page preservation\n");
    
    i = 0;
    while (i < 50) {
        pages[i] = malloc(4096);
        if (pages[i] == 0) break;
        
        expected_values[i] = i * 7777 + 12345;
        *(pages[i]) = expected_values[i];
        *(pages[i] + 1) = expected_values[i] + 1;
        
        printf("Created dirty page %d\n", i);
        i = i + 1;
    }
    
    j = 0;
    while (j < 100) {
        int *temp;
        temp = malloc(4096);
        if (temp != 0) {
            *temp = j + 50000;
        }
        j = j + 1;
    }
    
    printf("Verifying data integrity\n");
    k = 0;
    errors = 0;
    while (k < i) {
        if (*(pages[k]) != expected_values[k] || *(pages[k] + 1) != expected_values[k] + 1) {
            printf("Data corruption in page %d\n", k);
            errors = errors + 1;
        }
        k = k + 1;
    }
    
    if (errors == 0) {
        printf("All dirty pages preserved correctly\n");
        return 42;
    } else {
        printf("Found %d corrupted pages\n", errors);
        return 1;
    }
}
