#pragma once

#include "OpenCL/opencl.h"

static const char* _kernel_source = ""
                                    "__kernel void adder(__global float4 *restrict a, __global float4 *restrict b, __global float4 *restrict result) {\n"
                                    "  *result = *a + *b;\n"
                                    "}\n";

#define error_return(code, msg) do { \
        if((code) != CL_SUCCESS) { \
            std::cerr << (msg) << ", code:" << (code) << std::endl;    \
            return 1;                                                  \
        } \
    } while(0)

struct deleter {
    void operator() (cl_context ctx) {
        clReleaseContext(ctx);
    }

    void operator() (cl_command_queue queue) {
        clReleaseCommandQueue(queue);
    }

    void operator() (cl_program program) {
        clReleaseProgram(program);
    }

    void operator() (cl_kernel kernel) {
        clReleaseKernel(kernel);
    }
};
