from distutils.core import setup, Extension
import numpy

source_mod = Extension('input_arr', sources = ['input_array.c'], include_dirs=[numpy.get_include()])

setup(name = "input_arr",
      version = "1.0",
      description = "A input array method extension module",
      ext_modules = [source_mod],

)