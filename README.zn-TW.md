# 使用函數指標模擬 C 語言中的 polymorphism 來實現堆疊

## 說明
* 使用陣列來實現堆疊。
* 堆疊使用函數指標來模擬 C 語言中的 polymorphism。
* 函數指標用於指向常見堆疊操作的實際實現，例如 [std::stack](https://cplusplus.com/reference/stack/stack/) 中的 push、pop 和 top 操作。
* 本專案默認支援 `int`、`char` 和 `string` 資料型別，但可以輕鬆擴展以支援其他資料型別，例如 `float`、`double` 等。

## 函數指標
* `void (*init)(struct Stack *s)`: 初始化堆疊。
* `void (*push)(struct Stack *s, void *element)`: 將元素壓入堆疊。
* `void* (*pop)(struct Stack *s)`: 從堆疊中彈出元素。
* `void* (*top)(struct Stack *s)`: 獲取堆疊頂部的元素。
* `bool (*isFull)(struct Stack *s)`: 檢查堆疊是否已滿。
* `bool (*isEmpty)(struct Stack *s)`: 檢查堆疊是否為空。
* `int (*size)(struct Stack *s)`: 獲取堆疊當前的大小。
* `void (*free)(struct Stack *s)`: 釋放堆疊佔用的記憶體。
* `void (*print)(struct Stack *s)`: 列印堆疊的資訊。

## 簡單用法
1. 將原始程式碼編譯為目標檔案。
    ```bash
    $ make test_stack
    $ gcc -c -o <your_program>.o <your_program>.c
    ```
2. 將目標檔案連結成可執行檔。
    ```bash
    $ gcc -Wall -o <your_program> <your_program>.o stack/stack.o stack/stack_char.o stack/stack_string.o stack/stack_int.o
    $ ./<your_program>
    ```
3. `int` 資料型別的堆疊範例。
    ```cpp
    #include "stack/stack.h"
    int main() {
        Stack *stack = createStack(INT);
        if (!stack->top(stack)) {
            printf("stack is empty\\n");
        }
        int i = 123;
        stack->push(stack, &i);
        int *poppedInt = (int *)stack->pop(stack);
        printf("Popped from int stack: %d\\n\\n", *poppedInt);
        return 0;
    }
    ```
4. `char` 資料型別的堆疊範例。
    ```cpp
    #include "stack/stack.h"
    int main() {
        Stack *stack = createStack(CHAR);
        if (*(char*)stack->top(stack) == '\0') {
            printf("stack is empty\n");
        }
        char c = 'a';
        stack->push(stack, &c);  // passed by reference
        char *poppedChar = (char *)stack->pop(stack);
        printf("Popped from char stack: %c\n\n", *poppedChar);
        stack->free(stack);
        return 0;
    }
    ```

## 重點說明
* 傳遞給 `createStack` 的參數是堆疊的類型，該類型可以是 `INT`、`CHAR` 或 `STRING`。你可以在 [`stack_float.h`](https://github.com/JeepWay/stack-C-polymorphism/blob/main/stack/stack.h) 中的 `struct StackType` 中查看支援的資料型別。
* 使用 `push` 時，您需要傳遞要壓入堆疊資料的記憶體位置，因為 `push` 的函數指標定義為 `void (*push)(struct Stack *s, void *element)`。
* 使用 `pop` 和 `top` 時，您需要將返回值轉型為正確的資料型別，這與 C 語言中使用 `malloc()` 類似，以避免 `incompatible pointer type` 的警告，因為返回值是一個 `void *` 指標。
* 當堆疊在 `pop` 和 `top` 操作中為空時：
    * 對於 `INT` 類型，`pop` 和 `top` 的返回值為 `NULL`。
    * 對於 `CHAR` 類型，`pop` 和 `top` 的返回值為 `"\0"`。
    * 對於 `STRING` 類型，`pop` 和 `top` 的返回值為 `"\0"`。

## 測試
* 測試具有 polymorphism 的堆疊
    ```bash
    make test TARGET=test_stack
    ```
* 測試 `int` 資料型別的堆疊
    ```bash
    make test TARGET=test_stack_int   
    ```
* 測試 `char` 資料型別的堆疊
    ```bash
    make test TARGET=test_stack_char   
    ```
* 測試 `string` 資料型別的堆疊
    ```bash
    make test TARGET=test_stack_string   
    ```

## 擴展
如果想擴展堆疊以支援其他資料型別，例如 `float`、`double`，可以按照以下步驟：
1. 在 `stack` 目錄中新增 `stack_float.c` 和 `stack_float.h` 檔案。
2. 在 `stack_float.c` 中實現堆疊功能，並在 `stack_float.h` 中聲明函數。
3. 在 `Makefile` 中新增規則以編譯新的堆疊檔案。
    ```makefile
    OBJS_STACK = stack/stack.o stack/stack_char.o stack/stack_string.o stack/stack_int.o stack/stack_float.o 
    ```
4. 在 `stack/stack.h` 中更新 `enum StackType` 以支援新資料型別。
5. 在 `stack/stack.c` 中更新以支援新資料型別。
    * 新增 `#include "stack_float.h"`
    * 在 `createStack` 函數中根據新資料型別新增 `switch case`。
6. 重新編譯源碼並將目標檔案連結成可執行檔。
    ```bash
    $ make test_stack
    $ gcc -c -o <your_program>.o <your_program>.c
    $ gcc -Wall -o <your_program> <your_program>.o stack/stack.o stack/stack_char.o stack/stack_string.o stack/stack_int.o stack/stack_float.o
    $ ./<your_program>
    ```
