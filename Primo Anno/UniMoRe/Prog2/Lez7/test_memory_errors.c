// Test file to demonstrate AddressSanitizer capabilities
// This file contains intentional memory errors for testing
#include <stdio.h>
#include <stdlib.h>

void test_buffer_overflow(void) {
    printf("🔍 Testing buffer overflow detection...\n");
    int *arr = malloc(5 * sizeof(int));
    if (arr == NULL) return;
    
    // Initialize array properly
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    
    // Intentional buffer overflow (accessing beyond allocated memory)
    printf("Accessing valid indices:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("⚠️  Now trying to access invalid index (buffer overflow):\n");
    printf("arr[5] = %d\n", arr[5]);  // This will trigger AddressSanitizer!
    
    free(arr);
}

void test_use_after_free(void) {
    printf("\n🔍 Testing use-after-free detection...\n");
    int *ptr = malloc(sizeof(int));
    if (ptr == NULL) return;
    
    *ptr = 42;
    printf("Value before free: %d\n", *ptr);
    
    free(ptr);
    printf("⚠️  Now trying to access freed memory:\n");
    printf("Value after free: %d\n", *ptr);  // This will trigger AddressSanitizer!
}

void test_double_free(void) {
    printf("\n🔍 Testing double-free detection...\n");
    int *ptr = malloc(sizeof(int));
    if (ptr == NULL) return;
    
    *ptr = 100;
    printf("Value: %d\n", *ptr);
    
    free(ptr);
    printf("First free completed\n");
    
    printf("⚠️  Now trying double free:\n");
    free(ptr);  // This will trigger AddressSanitizer!
}

int main(void) {
    printf("🧪 MEMORY ERROR TESTING WITH ADDRESSSANITIZER 🧪\n");
    printf("This program contains intentional memory errors to test detection\n\n");
    
    // Uncomment ONE test at a time to see different error types
    test_buffer_overflow();
    // test_use_after_free();
    // test_double_free();
    
    printf("\n✅ If you see this message, no memory errors were detected!\n");
    return 0;
}
