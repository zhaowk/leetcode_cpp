#include "cl_test.h"
#include <iostream>

// 矢量输出
template<class T, int Size = sizeof(T), typename _ = decltype(T::s0)>
std::ostream& operator<<(std::ostream& out, T t) {
    out << t.s0 << "," << t.s1;
    if constexpr ( Size > sizeof t.s0 * 2) {
        out << "," << t.s2 << "," << t.s3;
    }

    if constexpr (Size > sizeof t.s0 * 4) {
        out     << "," << t.s4
                << "," << t.s5
                << "," << t.s6
                << "," << t.s7;
    }

    if constexpr (Size > sizeof t.s0 * 8) {
        out     << "," << t.s8
                << "," << t.s9
                << "," << t.sa
                << "," << t.sb
                << "," << t.sc
                << "," << t.sd
                << "," << t.se
                << "," << t.sf;
    }

    return out;
}

// 读取文件
std::string read_file(std::string_view filename) {
    std::string data;
    FILE * f = fopen(filename.data(), "rb");
    if (!f) {
        return data;
    }
    char buf[4096] = {};
    while (!feof(f)) {
        auto size = fread(buf, 1, 4096, f);
        data.append(buf, size);
    }
    return data;
}

int main() {
    // platform_id 指针
    cl_platform_id id;
    cl_int ret;
    cl_uint size;
    ret = clGetPlatformIDs(0, nullptr, &size);
    error_return(ret, "get platform count failed");

    ret = clGetPlatformIDs(size, &id, nullptr);
    error_return(ret, "get platform id failed");

    char buf[1024];
    size_t len = sizeof buf;
//    CL_PLATFORM_PROFILE; CL_PLATFORM_VERSION; CL_PLATFORM_NAME; CL_PLATFORM_VENDOR; CL_PLATFORM_EXTENSIONS;
    ret = clGetPlatformInfo(id, CL_PLATFORM_EXTENSIONS, len, buf, &len);
    std::cout << "get platform info, ret=" << ret << ", info=" << std::string_view(buf, len) << std::endl;

    cl_uint deviceNum = 0;
    ret = clGetDeviceIDs(id, CL_DEVICE_TYPE_GPU, 0, nullptr, &deviceNum);
    error_return(ret, "get device count failed");

    assert(deviceNum > 0);

    std::unique_ptr<cl_device_id> devices(new cl_device_id[deviceNum]);
    ret = clGetDeviceIDs(id, CL_DEVICE_TYPE_GPU, deviceNum, devices.get(), nullptr);
    error_return(ret, "get devices failed");

    // CL_DEVICE_NAME
    ret = clGetDeviceInfo(devices.get()[0], CL_DEVICE_NAME, sizeof(buf), buf, &len);
    std::cout << "get device name: " << ret << "," << std::string_view(buf, len) << std::endl;

    // create context
    std::unique_ptr<_cl_context, deleter> ctx(clCreateContext(nullptr, deviceNum, devices.get(), nullptr, nullptr, &ret));
    error_return(ret, "create context failed");

    std::unique_ptr<_cl_command_queue, deleter> queue(clCreateCommandQueue(ctx.get(), devices.get()[0], 0, &ret));
    error_return(ret, "create command queue failed");

    std::string src = read_file("test.cl");
    if (src.empty()) {
        src = _kernel_source;
    }

    const char* sources[] = {src.data()};
    size_t lengths[] = {src.size()};
    std::unique_ptr<_cl_program, deleter> program(clCreateProgramWithSource(ctx.get(), 1, sources, lengths, &ret));
    error_return(ret, "create program failed");

    // program 程序
    ret = clBuildProgram(program.get(), deviceNum, devices.get(), nullptr, nullptr, nullptr);
    error_return(ret, "build program failed");

    // kernel 可运行函数
    std::unique_ptr<_cl_kernel, deleter> kernel(clCreateKernel(program.get(), "adder", &ret));
    error_return(ret, "create kernel failed");

    cl_float4 a = {1,2,3,4};
    auto arg1 = clCreateBuffer(ctx.get(), CL_MEM_READ_ONLY| CL_MEM_COPY_HOST_PTR, sizeof(cl_float4), &a, &ret);
    error_return(ret, "create buffer arg1 failed");

    cl_float4 b = {2,3,4,5};
    auto arg2 = clCreateBuffer(ctx.get(), CL_MEM_READ_ONLY| CL_MEM_COPY_HOST_PTR, sizeof(cl_float4), &b, &ret);
    error_return(ret, "create buffer arg2 failed");

    cl_float4 r{};
    auto result = clCreateBuffer(ctx.get(), CL_MEM_WRITE_ONLY, sizeof(cl_float4), nullptr, &ret); // write memory
    error_return(ret, "create buffer arg3 failed");

    ret = clSetKernelArg(kernel.get(), 0, sizeof(cl_mem), &arg1);
    error_return(ret, "set kernel arg1 failed");
    ret = clSetKernelArg(kernel.get(), 1, sizeof(cl_mem), &arg2);
    error_return(ret, "set kernel arg2 failed");
    ret = clSetKernelArg(kernel.get(), 2, sizeof(cl_mem), &result);
    error_return(ret, "set kernel arg3 failed");

    // 并行计算执行
//    ret = clEnqueueNDRangeKernel(queue.get(), kernel.get(), 1, nullptr, nullptr, nullptr, 0, nullptr, nullptr);

    // 执行计算
    ret = clEnqueueTask(queue.get(), kernel.get(), 0, nullptr, nullptr);
    error_return(ret, "enqueue task failed");

    // 取值
    ret = clEnqueueReadBuffer(queue.get(), result, CL_BLOCKING, 0, sizeof r, &r, 0, nullptr, nullptr);
    error_return(ret, "enqueue read buffer failed");

    std::cout << r << std::endl;

    return 0;
}
