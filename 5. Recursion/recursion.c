#include <stdio.h>
#include <Python.h>

int recursiveSum(int n);
int recursiveFibo(int n);
// Module method definitions Int 값을 Input 받아 Int 값을 리턴한다.
static PyObject* recursion_sum(PyObject *self, PyObject *args) 
{
    int n;
	if(!PyArg_ParseTuple(args, "i", &n))
		return NULL;
	int sum = 0;
	sum = recursiveSum(n);
	
	return Py_BuildValue("i", sum);
}

static PyObject* sum(PyObject *self, PyObject *args) 
{
    int n;
	if(!PyArg_ParseTuple(args, "i", &n))
		return NULL;
	int sum = 0;
	for (int i = 0; i <= n; i++){
		sum = sum + i;
	}
	return Py_BuildValue("i", sum);
}

static PyObject* fiboSum(PyObject *self, PyObject *args) 
{
    int n;
	if(!PyArg_ParseTuple(args, "i", &n))
		return NULL;
	int ret = 0;
	ret = recursiveFibo(n);
	return Py_BuildValue("i", ret);
}

static PyMethodDef recursion_methods[] = { 
	{"recursion_sum", recursion_sum, METH_VARARGS, "recursion_on_C"},
	{"sum", sum, METH_VARARGS, "SUM_on_C"},
	{"fiboSum", fiboSum, METH_VARARGS, "fibonacci sum by recursion"},

		{NULL}
};


static struct PyModuleDef recur_module = {

		PyModuleDef_HEAD_INIT,

		"recursion",					// 모듈의 이름

		"It is test module.",			// 모듈의 설명을 적는 부분, 모듈의 __doc__에 저장됨

		-1, recursion_methods

};

PyMODINIT_FUNC
PyInit_recursion(void)
{
	return PyModule_Create(&recur_module);
}

int recursiveSum(int n){
	if (n ==1) return 1;
	return n + recursiveSum(n-1);
}

int recursiveFibo(int n){
	printf("Level %d, address of variable n = %p\n", n &n);
	if (n<=2)
		return 1;
	else
		return recursiveFibo(n-1)+recursiveFibo(n-2);
}