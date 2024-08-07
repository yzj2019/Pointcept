#include <vector>
#include <torch/serialize/tensor.h>
#include <ATen/cuda/CUDAContext.h>
#include "sampling_cuda_kernel.h"


void farthest_point_sampling_cuda(int b, int n, at::Tensor xyz_tensor, at::Tensor offset_tensor, at::Tensor new_offset_tensor, at::Tensor tmp_tensor, at::Tensor idx_tensor)
{
    const float *xyz = xyz_tensor.data_ptr<float>();
    const int *offset = offset_tensor.data_ptr<int>();
    const int *new_offset = new_offset_tensor.data_ptr<int>();
    float *tmp = tmp_tensor.data_ptr<float>();
    int *idx = idx_tensor.data_ptr<int>();
    farthest_point_sampling_cuda_launcher(b, n, xyz, offset, new_offset, tmp, idx);
}


void farthest_point_sampling_with_dist_cuda(int b, int n_max, int n_all, at::Tensor distance_tensor, at::Tensor offset_tensor, at::Tensor new_offset_tensor, at::Tensor tmp_tensor, at::Tensor idx_tensor)
{
    const float *distance = distance_tensor.data_ptr<float>();
    const int *offset = offset_tensor.data_ptr<int>();
    const int *new_offset = new_offset_tensor.data_ptr<int>();
    float *tmp = tmp_tensor.data_ptr<float>();
    int *idx = idx_tensor.data_ptr<int>();
    farthest_point_sampling_with_dist_cuda_launcher(b, n_max, n_all, distance, offset, new_offset, tmp, idx);
}