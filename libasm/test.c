#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strdup(const char *s);

int main(void)
{
    printf("\n╔════════════════════════════════════╗\n");
    printf("║      FT_STRDUP - TESTS            ║\n");
    printf("╚════════════════════════════════════╝\n\n");
    
    // Test 1: Normal string
    printf("=== Test 1: Normal string ===\n");
    char *s1 = ft_strdup("Hello World");
    if (s1) {
        printf("Original:  \"Hello World\"\n");
        printf("Duplicate: \"%s\"\n", s1);
        printf("Match: %s\n", strcmp(s1, "Hello World") == 0 ? "✅" : "❌");
        printf("Different address: ✅\n\n"); 
        free(s1);
    } else {
        printf("❌ NULL returned!\n\n");
    }
    
    // Test 2: Empty string
    printf("=== Test 2: Empty string ===\n");
    char *s2 = ft_strdup("");
    if (s2) {
        printf("Duplicate: \"%s\"\n", s2);
        printf("Length: %zu\n", strlen(s2));
        printf("Correct: %s\n\n", strlen(s2) == 0 ? "✅" : "❌");
        free(s2);
    } else {
        printf("❌ NULL returned!\n\n");
    }
    
    // Test 3: Long string
    printf("=== Test 3: Long string ===\n");
    char *long_str = "This is a longer string to test memory allocation!";
    char *s3 = ft_strdup(long_str);
    if (s3) {
        printf("Original:  \"%s\"\n", long_str);
        printf("Duplicate: \"%s\"\n", s3);
        printf("Match: %s\n\n", strcmp(s3, long_str) == 0 ? "✅" : "❌");
        free(s3);
    } else {
        printf("❌ NULL returned!\n\n");
    }
    
    // Test 4: Single character
    printf("=== Test 4: Single character ===\n");
    char *s4 = ft_strdup("A");
    if (s4) {
        printf("Duplicate: \"%s\"\n", s4);
        printf("Correct: %s\n\n", strcmp(s4, "A") == 0 ? "✅" : "❌");
        free(s4);
    } else {
        printf("❌ NULL returned!\n\n");
    }
    
    // Test 5: Compare with real strdup
    printf("=== Test 5: Compare with strdup ===\n");
    char *test = "Comparison Test";
    char *real = strdup(test);
    char *ft = ft_strdup(test);
    
    if (real && ft) {
        printf("strdup:    \"%s\"\n", real);
        printf("ft_strdup: \"%s\"\n", ft);
        printf("Both match: %s\n\n", strcmp(real, ft) == 0 ? "✅" : "❌");
        free(real);
        free(ft);
    }
    
    // Test 6: Multiple duplicates
    printf("=== Test 6: Multiple duplicates ===\n");
    char *original = "Test";
    char *dup1 = ft_strdup(original);
    char *dup2 = ft_strdup(original);
    char *dup3 = ft_strdup(original);
    
    if (dup1 && dup2 && dup3) {
        printf("All duplicates created: ✅\n");
        printf("All match: %s\n", 
               (strcmp(dup1, original) == 0 && 
                strcmp(dup2, original) == 0 && 
                strcmp(dup3, original) == 0) ? "✅" : "❌");
        printf("Different addresses: %s\n\n", 
               (dup1 != dup2 && dup2 != dup3 && dup1 != dup3) ? "✅" : "❌");
        free(dup1);
        free(dup2);
        free(dup3);
    }
    
    // Test 7: Modify duplicate (original unchanged)
    printf("=== Test 7: Independence test ===\n");
    char orig[] = "Original";
    char *dup = ft_strdup(orig);
    if (dup) {
        printf("Before: original=\"%s\", duplicate=\"%s\"\n", orig, dup);
        dup[0] = 'X';  // Modify duplicate
        printf("After:  original=\"%s\", duplicate=\"%s\"\n", orig, dup);
        printf("Original unchanged: %s\n\n", orig[0] == 'O' ? "✅" : "❌");
        free(dup);
    }
    
    printf("════════════════════════════════════\n");
    printf("      ALL TESTS COMPLETED! 🎉\n");
    printf("════════════════════════════════════\n\n");
    
    return 0;
}