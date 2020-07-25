#include <numpy/arrayobject.h>  
#include <stdio.h>
#include <Python.h>

static PyObject* arr_size(PyObject *self, PyObject *args){
	
    PyArrayObject *X;

    PyArg_ParseTuple(args, "O!", &PyArray_Type, &X);
    npy_intp N = PyArray_SIZE(X);
	printf("%li", N);
    Py_RETURN_NONE;
}

static PyObject* list_size(PyObject *self, PyObject *args){
	
    PyObject *pList;

    PyArg_ParseTuple(args, "O!", &PyList_Type, &pList);
    int N = PyList_Size(pList);
	printf("%d", N);
	
    Py_RETURN_NONE;
}

static PyMethodDef input_arr[] = { 
	{"arr_size", arr_size, METH_VARARGS, "array_size_method_on_C"},
	{"list_size", list_size, METH_VARARGS, "list_size_method_on_C"},
		{NULL}
};


static struct PyModuleDef arr_mod = {

		PyModuleDef_HEAD_INIT,

		"input_arr",					// 모듈의 이름

		"It is test module.",			// 모듈의 설명을 적는 부분, 모듈의 __doc__에 저장됨

		-1, input_arr

};

PyMODINIT_FUNC PyInit_input_arr(void)
{
	PyObject *module;
	module = PyModule_Create(&arr_mod);
	if(module==NULL) return NULL;
	import_array();
	if (PyErr_Occurred()) return NULL;
	return module;
}