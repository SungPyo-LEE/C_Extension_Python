  
#include <stdio.h>
#include <Python.h>

static PyObject* input_array_test(PyObject *self, PyObject *args){
	PyObject *pList;
	PyObject *pItem;
	Py_ssize_t n;
	int i;

	/*
	Store a Python object in a C object pointer. This is similar to O, but takes two C arguments: the first is the address of a Python type object, the second is the address of the C variable (of type PyObject*) into which the object pointer is stored. If the Python object does not have the required type, TypeError is raised.
	*/
	if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &pList)) {
		PyErr_SetString(PyExc_TypeError, "parameter must be a list.");
		return NULL;
	}

	n = PyList_Size(pList);
	for (i=0; i<n; i++) {
		pItem = PyList_GetItem(pList, i);
	}
	Py_RETURN_NONE;
}

static PyMethodDef input_arr[] = { 
	{"input_array_test", input_array_test, METH_VARARGS, "input_array_method_on_C"},
		{NULL}
};


static struct PyModuleDef arr_mod = {

		PyModuleDef_HEAD_INIT,

		"input_arr",					// 모듈의 이름

		"It is test module.",			// 모듈의 설명을 적는 부분, 모듈의 __doc__에 저장됨

		-1, input_arr

};

PyMODINIT_FUNC
PyInit_plus_mod(void)
{
	return PyModule_Create(&arr_mod);
}