#include <stdio.h>
#include <Python.h>


// Module method definitions Int 값을 Input 받아 Int 값을 리턴한다.
static PyObject* plus(PyObject *self, PyObject *args) 
{
    int a;
	int b;
	if(!PyArg_ParseTuple(args, "ii", &a, &b))
		return NULL;
	int c;
	c = a+b;
	return Py_BuildValue("i", c);
}

// 단순한 기능을 추가해보자. 반복적으로 숫자를 받아 덧셈
static PyObject* plus_repeat(PyObject *self, PyObject *args) 
{
    int a;
	int b;
	if(!PyArg_ParseTuple(args, "ii", &a, &b))
		return NULL;
	int c=0;
	for (int i = 0; i<b; i++){
		c = a+c;
	}
	return Py_BuildValue("i", c);
}

static PyMethodDef plus_methods[] = { 
	{"plus", plus, METH_VARARGS, "plus_method_on_C"},
	{"plus_repeat", plus_repeat, METH_VARARGS, "plus_repeat_method_on_C"},
		{NULL}
};


static struct PyModuleDef plusmodule = {

		PyModuleDef_HEAD_INIT,

		"plus_mod",					// 모듈의 이름

		"It is test module.",			// 모듈의 설명을 적는 부분, 모듈의 __doc__에 저장됨

		-1, plus_methods

};

PyMODINIT_FUNC
PyInit_plus_mod(void)
{
	return PyModule_Create(&plusmodule);
}