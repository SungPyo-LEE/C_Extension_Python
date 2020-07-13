#include <stdio.h>
#include <Python.h>

// Module method definitions Python에서 사용하게 될 메소드
static PyObject* hello_world(PyObject *self, PyObject *args) {
    printf("Hello, world!\n");
    Py_RETURN_NONE;
}

//PyArg_ParseTuple를 통해 Python Input 값을 받을 수 있다.
// https://docs.python.org/3/c-api/arg.html 공식문서 참조.
static PyObject* hello(PyObject *self, PyObject *args) {
    const char* name;
    if (!PyArg_ParseTuple(args, "s", &name)) {
        return NULL;
    }

    printf("Hello, %s!\n", name);
    Py_RETURN_NONE;
}

// Python 에서 사용하게 될 Method Name
// C Method Name
static PyMethodDef hello_methods[] = { 
    {   
        "hello_world", hello_world, METH_NOARGS,
        "Print 'hello world' from a method defined in a C extension."
    },  
    {   
        "hello", hello, METH_VARARGS,
        "Print 'hello xxx' from a method defined in a C extension."
    },  
    {NULL, NULL, 0, NULL}
};

// import 하게 될 Module Name
static struct PyModuleDef hello_definition = { 
    PyModuleDef_HEAD_INIT,
    "hello",
    "A Python module that prints 'hello world' from C code.",
    -1, 
    hello_methods
};

// Module initialization
// Python calls this function when importing your extension. It is important
// that this function is named PyInit_[[your_module_name]] exactly, and matches
// the name keyword argument in setup.py's setup() call.
PyMODINIT_FUNC PyInit_hello(void) {
    Py_Initialize();
    return PyModule_Create(&hello_definition);
}