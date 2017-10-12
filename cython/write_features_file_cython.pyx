import numpy as np
cimport numpy as np

def values2str(np.ndarray[np.float64_t, ndim=1] A):
    cdef Py_ssize_t i
    cdef str result_str = ""
    for i in range(A.shape[0]):
        result_str += str(A[i])
    return result_str
