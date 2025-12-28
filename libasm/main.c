#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

size_t      ft_strlen(const char *s);
char        *ft_strcpy(char *dest, const char *src);
int         ft_strcmp(const char *s1, const char *s2);
ssize_t     ft_write(int fd, const void *buf, size_t count);
ssize_t     ft_read(int fd, void *buf, size_t count);
char        *ft_strdup(const char *s);

#define PASS "✅"
#define FAIL "❌"

int main(void)
{
    printf("\n╔═══════════════════════════════════╗\n");
    printf("║         LIBASM - MAIN TEST        ║\n");
    printf("╚═══════════════════════════════════╝\n\n");

    // ========== FT_STRLEN ==========
    printf("========== FT_STRLEN ==========\n");
    
    // Empty string
    printf("Empty string: %s\n", ft_strlen("") == 0 ? PASS : FAIL);
    
    // Very long string
    char long_str[1000];
    memset(long_str, 'A', 999);
    long_str[999] = '\0';
    printf("Very long string (999 chars): %s\n", 
           ft_strlen(long_str) == 999 ? PASS : FAIL);
    printf("\n");

    // ========== FT_STRCPY ==========
    printf("========== FT_STRCPY ==========\n");
    char buf[1000];
    
    // Empty string
    ft_strcpy(buf, "");
    printf("Empty string: %s\n", strcmp(buf, "") == 0 ? PASS : FAIL);
    
    // Very long string
    ft_strcpy(buf, long_str);
    printf("Very long string: %s\n", strcmp(buf, long_str) == 0 ? PASS : FAIL);
    printf("\n");

    // ========== FT_STRCMP ==========
    printf("========== FT_STRCMP ==========\n");
    
    // 2 empty strings
    printf("Two empty strings: %s\n", 
           ft_strcmp("", "") == 0 ? PASS : FAIL);
    
    // Empty as first arg
    printf("Empty first arg: %s\n", 
           ft_strcmp("", "abc") < 0 ? PASS : FAIL);
    
    // Empty as second arg
    printf("Empty second arg: %s\n", 
           ft_strcmp("abc", "") > 0 ? PASS : FAIL);
    
    // Multiple strings
    printf("Equal strings: %s\n", 
           ft_strcmp("test", "test") == 0 ? PASS : FAIL);
    printf("Different strings (first < second): %s\n", 
           ft_strcmp("abc", "abd") < 0 ? PASS : FAIL);
    printf("Different strings (first > second): %s\n", 
           ft_strcmp("abd", "abc") > 0 ? PASS : FAIL);
    printf("\n");

    // ========== FT_WRITE ==========
    printf("========== FT_WRITE ==========\n");
    
    // stdout
    printf("Write to stdout: ");
    ssize_t ret = ft_write(1, "Test\n", 5);
    printf("Return value: %s\n", ret == 5 ? PASS : FAIL);
    
    // File open
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    ret = ft_write(fd, "Hello", 5);
    close(fd);
    printf("Write to file: %s (return: %zd)\n", ret == 5 ? PASS : FAIL, ret);
    unlink("test.txt");
    
    // Wrong fd
    errno = 0;
    ret = ft_write(-1, "test", 4);
    printf("Wrong fd: %s (return: %zd, errno: %d)\n", 
           ret == -1 && errno != 0 ? PASS : FAIL, ret, errno);
    printf("\n");

    // ========== FT_READ ==========
    printf("========== FT_READ ==========\n");
    
    // stdin (skip - requires user input)
    printf("stdin test: (skipped - requires input)\n");
    
    // Open file
    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, "TestData", 8);
    close(fd);
    
    fd = open("test.txt", O_RDONLY);
    char read_buf[100] = {0};
    ret = ft_read(fd, read_buf, 8);
    close(fd);
    printf("Read from file: %s (return: %zd, data: %s)\n", 
           ret == 8 && strcmp(read_buf, "TestData") == 0 ? PASS : FAIL, 
           ret, read_buf);
    unlink("test.txt");
    
    // Wrong fd
    errno = 0;
    ret = ft_read(-1, read_buf, 10);
    printf("Wrong fd: %s (return: %zd, errno: %d)\n", 
           ret == -1 && errno != 0 ? PASS : FAIL, ret, errno);
    printf("\n");

    // ========== FT_STRDUP ==========
    printf("========== FT_STRDUP ==========\n");
    
    // Empty string
    char *dup = ft_strdup("");
    printf("Empty string: %s\n", 
           dup && strcmp(dup, "") == 0 ? PASS : FAIL);
    free(dup);
    
    // Very long string
    dup = ft_strdup(long_str);
    printf("Very long string: %s\n", 
           dup && strcmp(dup, long_str) == 0 ? PASS : FAIL);
    free(dup);
    printf("\n");

    printf("═══════════════════════════════════\n");
    printf("       ALL TESTS COMPLETED\n");
    printf("═══════════════════════════════════\n\n");

    return 0;
}