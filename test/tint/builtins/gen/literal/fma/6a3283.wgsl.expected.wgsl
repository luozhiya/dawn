fn fma_6a3283() {
  var res : vec4<f32> = fma(vec4<f32>(), vec4<f32>(), vec4<f32>());
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  fma_6a3283();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  fma_6a3283();
}

@compute @workgroup_size(1)
fn compute_main() {
  fma_6a3283();
}
