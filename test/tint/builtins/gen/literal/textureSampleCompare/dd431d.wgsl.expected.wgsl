@group(1) @binding(0) var arg_0 : texture_depth_2d_array;

@group(1) @binding(1) var arg_1 : sampler_comparison;

fn textureSampleCompare_dd431d() {
  var res : f32 = textureSampleCompare(arg_0, arg_1, vec2<f32>(), 1, 1.0);
}

@fragment
fn fragment_main() {
  textureSampleCompare_dd431d();
}
