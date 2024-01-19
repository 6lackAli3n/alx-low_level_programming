#include <stdio.h>
/**
 * add - add two integers
 * @a: first int
 * @b: second int
 * Return: addition
 */
int add(int a, int b) {
    return a + b;
}

/**
 * sub - subtract two integers
 * @a: fist int
 * @b: second int
 * Return: subtraction
 */
int sub(int a, int b) {
    return a - b;
}
/**
 * multiply - multiply two integers
 * @a: fist int
 * @b: second int
 * Return: multiplication
 */
int mul(int a, int b) {
    return a * b;
}

/**
 * Division - divide two integers
 * @a: fist int
 * @b: second int
 * Return: division
 */
int div(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}
/**
 * modulo - mod two integers
 * @a: fist int
 * @b: second int
 * Return: modulo
 */
int mod(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Error: Modulo by zero\n");
        return 0;
    }
}
