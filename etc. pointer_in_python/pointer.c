  
#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

static PyObject* dynamic_memory(PyObject *self, PyObject *args) 
{
    int n;
	if(!PyArg_ParseTuple(args, "i", &n))
		return NULL;
    double* ptr = NULL;
    ptr = (double*)malloc(n * sizeof(double));
    if (ptr != NULL)
    {
        for (int i = 0; i<n; ++i)
            printf("%f ", ptr[i]);
        printf("\n");

        for (int i = 0; i<n; ++i)
            * (ptr + i) = (double)3 * i;

        for (int i = 0; i<n; ++i)
            printf("%f ", ptr[i]);
        printf("\n");
    }
    free(ptr);
    ptr = NULL; // free하게 만들어주고 NULL 값을 넣어주는 것이 좋다!
	
	return Py_BuildValue("d", &ptr);
}

static PyMethodDef pointer_methods[] = { 
	{"dynamic_memory", dynamic_memory, METH_VARARGS, "dynamic memory"},

		{NULL}
};

static struct PyModuleDef pointer_mod = {

		PyModuleDef_HEAD_INIT,

		"python_pointer",					// 모듈의 이름

		"It is test module.",			// 모듈의 설명을 적는 부분, 모듈의 __doc__에 저장됨

		-1, pointer_methods

};

PyMODINIT_FUNC
PyInit_python_pointer(void)
{
	return PyModule_Create(&pointer_mod);
}