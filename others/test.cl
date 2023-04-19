__kernel void adder(__global float4 *restrict a, __global float4 *restrict b, __global float4 *restrict result) {
    *result = *a + *b;
}
