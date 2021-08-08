#include <Python.h>

/* Will come from go */
PyObject* forward(PyObject* , PyObject*);

/*
To shim go's missing variadic function support.

Ref https://docs.python.org/3/c-api/arg.html
*/
int PyArg_ParseTuple_ssll(PyObject* args, char** a, char** b, int* c, int* d) {
    return PyArg_ParseTuple(args, "ssii", a, b, c, d);
}

static struct PyMethodDef methods[] = {
    {"forward", (PyCFunction)forward, METH_VARARGS, "Connects to a Pod and tunnels traffic from a local port to this pod"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "portforward",
    "Kubernetes Port-Forward Go-Edition For Python",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_portforward(void) {
    return PyModule_Create(&module);
}