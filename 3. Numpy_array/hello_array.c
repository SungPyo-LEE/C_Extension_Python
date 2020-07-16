#include <Python.h>
#include <numpy/arrayobject.h>


static PyObject* array_n(PyObject *self, PyObject *args) 
{
    double *vector;
    npy_intp dims[1] = {5};
    npy_intp k;
	
	int n;
	if(!PyArg_ParseTuple(args, "i", &n))
		return NULL;
	
    PyObject *ret = PyArray_SimpleNew(1, dims, NPY_DOUBLE);
    vector = (double *) PyArray_DATA(ret);
    /*
     *  NOTE: Treating PyArray_DATA(ret) as if it were a contiguous one-dimensional C
     *  array is safe, because we just created it with PyArray_SimpleNew, so we know
     *  that it is, in fact, a one-dimensional contiguous array.
     */
    for (k = 0; k < dims[0]; ++k) {
        vector[k] = 1.0 + k+n;
    }
    return ret;
}

static PyMethodDef hello_array_methods[] = { 
	{"array_n", array_n, METH_VARARGS},
		{NULL, NULL, 0}
};

static struct PyModuleDef hello_array_mods = {

		PyModuleDef_HEAD_INIT,

		"hello_array",					// 모듈의 이름

		"It is test module.",			// 모듈의 설명을 적는 부분, 모듈의 __doc__에 저장됨

		-1, hello_array_methods

};

PyMODINIT_FUNC PyInit_hello_array(void)
{
    PyObject *module;
    module = PyModule_Create(&hello_array_mods);
    if(module==NULL) return NULL;
    /* IMPORTANT: this must be called */
    import_array();
    if (PyErr_Occurred()) return NULL;
    return module;
}