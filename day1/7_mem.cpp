#include <iostream>
#include <vector>

int global_initialized = 42;
int global_uninitialized;

static int static_global = 100;

void function_demo()
{
    int local_stack = 10;                 // stack
    static int static_local = 20;         // static storage
    int* heap_var = new int(30);          // heap
    const char* literal = "Hello World";  // read-only segment

    std::cout << "\n--- Inside function_demo ---\n";

    std::cout << "Address of local_stack (stack):          " << &local_stack << "\n";
    std::cout << "Address of static_local (static):        " << &static_local << "\n";
    std::cout << "Address of heap_var pointer (stack):     " << &heap_var << "\n";
    std::cout << "Address heap_var points to (heap):       " << heap_var << "\n";
    std::cout << "Address of string literal (RO memory):   " << static_cast<const void*>(literal) << "\n";

    delete heap_var;
}

int main()
{
    int main_local = 5;          // stack
    int* heap_main = new int(50); // heap

    std::cout << "--- Global / Static ---\n";
    std::cout << "Address of global_initialized:           " << &global_initialized << "\n";
    std::cout << "Address of global_uninitialized:         " << &global_uninitialized << "\n";
    std::cout << "Address of static_global:                " << &static_global << "\n";

    std::cout << "\n--- Stack / Heap in main ---\n";
    std::cout << "Address of main_local (stack):           " << &main_local << "\n";
    std::cout << "Address of heap_main pointer (stack):    " << &heap_main << "\n";
    std::cout << "Address heap_main points to (heap):      " << heap_main << "\n";

    function_demo();

    std::cout << "\n--- Code Segment ---\n";
    std::cout << "Address of main function:                " << (void*)&main << "\n";
    std::cout << "Address of function_demo:                " << (void*)&function_demo << "\n";

    delete heap_main;

    return 0;
}