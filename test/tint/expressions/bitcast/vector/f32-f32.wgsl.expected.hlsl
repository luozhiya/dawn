[numthreads(1, 1, 1)]
void f() {
  const float3 a = float3(1.0f, 2.0f, 3.0f);
  const float3 b = asfloat(float3(1.0f, 2.0f, 3.0f));
  return;
}
