@group(1) @binding(0) var arg_0 : texture_2d<f32>;

@group(1) @binding(1) var arg_1 : sampler;

fn textureSampleLevel_c6aca6() {
  var arg_2 = vec2<f32>();
  var arg_3 = 1.0;
  var res : vec4<f32> = textureSampleLevel(arg_0, arg_1, arg_2, arg_3);
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  textureSampleLevel_c6aca6();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  textureSampleLevel_c6aca6();
}

@compute @workgroup_size(1)
fn compute_main() {
  textureSampleLevel_c6aca6();
}
