[numthreads(1, 1, 1)]
void unused_entry_point() {
  return;
}

void f() {
  {
    const int a_1 = 0;
    const int b = 0;
  }
  const int a_2 = 0;
  const int b = 0;
}
