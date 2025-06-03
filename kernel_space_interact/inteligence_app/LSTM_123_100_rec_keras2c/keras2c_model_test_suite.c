#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include "./include/k2c_include.h" 
#include "keras2c_model.h" 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2);
struct timeval GetTimeStamp(); 
 
float test1_input_layer_14_input_array[9] = {
+4.45824556e-01f,+3.47760898e-01f,-3.68790376e-01f,-1.65872213e+00f,+8.41368968e-01f,
+7.18464815e-01f,+1.93664738e+00f,+1.16511561e-02f,-5.59145101e-01f,}; 
k2c_tensor test1_input_layer_14_input = {&test1_input_layer_14_input_array[0],2,9,{3,3,1,1,1}}; 
float keras_keras_tensor_9_test1_array[1] = {
+1.19966606e-03f,}; 
k2c_tensor keras_keras_tensor_9_test1 = {&keras_keras_tensor_9_test1_array[0],1,1,{1,1,1,1,1}}; 
float c_keras_tensor_9_test1_array[1] = {0}; 
k2c_tensor c_keras_tensor_9_test1 = {&c_keras_tensor_9_test1_array[0],1,1,{1,1,1,1,1}}; 
float test2_input_layer_14_input_array[9] = {
-4.33596775e-01f,+1.16041994e+00f,-6.85700367e-02f,+1.82594272e+00f,-1.26777001e+00f,
+1.12440723e+00f,-1.47557082e+00f,+2.61482273e-01f,-1.71805925e+00f,}; 
k2c_tensor test2_input_layer_14_input = {&test2_input_layer_14_input_array[0],2,9,{3,3,1,1,1}}; 
float keras_keras_tensor_9_test2_array[1] = {
+4.01160896e-01f,}; 
k2c_tensor keras_keras_tensor_9_test2 = {&keras_keras_tensor_9_test2_array[0],1,1,{1,1,1,1,1}}; 
float c_keras_tensor_9_test2_array[1] = {0}; 
k2c_tensor c_keras_tensor_9_test2 = {&c_keras_tensor_9_test2_array[0],1,1,{1,1,1,1,1}}; 
float test3_input_layer_14_input_array[9] = {
-8.81873749e-01f,-3.48717477e-01f,+1.78451913e+00f,+1.46233156e-01f,-1.01879036e+00f,
-1.39837587e+00f,-7.76627258e-01f,+7.05223434e-02f,+1.16463691e-01f,}; 
k2c_tensor test3_input_layer_14_input = {&test3_input_layer_14_input_array[0],2,9,{3,3,1,1,1}}; 
float keras_keras_tensor_9_test3_array[1] = {
+9.44852854e-06f,}; 
k2c_tensor keras_keras_tensor_9_test3 = {&keras_keras_tensor_9_test3_array[0],1,1,{1,1,1,1,1}}; 
float c_keras_tensor_9_test3_array[1] = {0}; 
k2c_tensor c_keras_tensor_9_test3 = {&c_keras_tensor_9_test3_array[0],1,1,{1,1,1,1,1}}; 
float test4_input_layer_14_input_array[9] = {
-4.73586904e-01f,-9.84479984e-01f,+1.92191315e+00f,+1.08994595e+00f,-1.05205823e+00f,
+9.41562654e-01f,-2.96050990e-01f,+4.95262898e-03f,-1.22897894e+00f,}; 
k2c_tensor test4_input_layer_14_input = {&test4_input_layer_14_input_array[0],2,9,{3,3,1,1,1}}; 
float keras_keras_tensor_9_test4_array[1] = {
+1.30276196e-04f,}; 
k2c_tensor keras_keras_tensor_9_test4 = {&keras_keras_tensor_9_test4_array[0],1,1,{1,1,1,1,1}}; 
float c_keras_tensor_9_test4_array[1] = {0}; 
k2c_tensor c_keras_tensor_9_test4 = {&c_keras_tensor_9_test4_array[0],1,1,{1,1,1,1,1}}; 
float test5_input_layer_14_input_array[9] = {
+1.16746803e+00f,+1.02944704e+00f,-6.16326355e-01f,+1.58692237e+00f,+1.14323470e+00f,
-9.43418878e-01f,-1.84245097e+00f,+1.22747835e+00f,+5.13603341e-01f,}; 
k2c_tensor test5_input_layer_14_input = {&test5_input_layer_14_input_array[0],2,9,{3,3,1,1,1}}; 
float keras_keras_tensor_9_test5_array[1] = {
+2.35602143e-04f,}; 
k2c_tensor keras_keras_tensor_9_test5 = {&keras_keras_tensor_9_test5_array[0],1,1,{1,1,1,1,1}}; 
float c_keras_tensor_9_test5_array[1] = {0}; 
k2c_tensor c_keras_tensor_9_test5 = {&c_keras_tensor_9_test5_array[0],1,1,{1,1,1,1,1}}; 
float test6_input_layer_14_input_array[9] = {
+5.45069652e-01f,+1.88684334e+00f,+8.61897606e-01f,+7.07632113e-01f,+1.51791436e+00f,
+1.39220307e+00f,+8.18035972e-01f,+8.05509389e-01f,+2.55581887e-01f,}; 
k2c_tensor test6_input_layer_14_input = {&test6_input_layer_14_input_array[0],2,9,{3,3,1,1,1}}; 
float keras_keras_tensor_9_test6_array[1] = {
+5.36328088e-03f,}; 
k2c_tensor keras_keras_tensor_9_test6 = {&keras_keras_tensor_9_test6_array[0],1,1,{1,1,1,1,1}}; 
float c_keras_tensor_9_test6_array[1] = {0}; 
k2c_tensor c_keras_tensor_9_test6 = {&c_keras_tensor_9_test6_array[0],1,1,{1,1,1,1,1}}; 
float test7_input_layer_14_input_array[9] = {
+8.33116831e-01f,-1.59790195e+00f,+1.31315260e+00f,+6.44916371e-01f,+3.81437857e-02f,
+1.56557682e+00f,-1.33467311e+00f,+1.41532238e+00f,-6.50728714e-01f,}; 
k2c_tensor test7_input_layer_14_input = {&test7_input_layer_14_input_array[0],2,9,{3,3,1,1,1}}; 
float keras_keras_tensor_9_test7_array[1] = {
+7.70336483e-04f,}; 
k2c_tensor keras_keras_tensor_9_test7 = {&keras_keras_tensor_9_test7_array[0],1,1,{1,1,1,1,1}}; 
float c_keras_tensor_9_test7_array[1] = {0}; 
k2c_tensor c_keras_tensor_9_test7 = {&c_keras_tensor_9_test7_array[0],1,1,{1,1,1,1,1}}; 
float test8_input_layer_14_input_array[9] = {
-5.04108164e-01f,-7.09494611e-01f,+4.61949393e-02f,-7.89397398e-01f,+1.36542921e+00f,
+1.54455450e+00f,+6.41727256e-01f,-1.63815742e+00f,+8.28912173e-01f,}; 
k2c_tensor test8_input_layer_14_input = {&test8_input_layer_14_input_array[0],2,9,{3,3,1,1,1}}; 
float keras_keras_tensor_9_test8_array[1] = {
+1.89607545e-05f,}; 
k2c_tensor keras_keras_tensor_9_test8 = {&keras_keras_tensor_9_test8_array[0],1,1,{1,1,1,1,1}}; 
float c_keras_tensor_9_test8_array[1] = {0}; 
k2c_tensor c_keras_tensor_9_test8 = {&c_keras_tensor_9_test8_array[0],1,1,{1,1,1,1,1}}; 
float test9_input_layer_14_input_array[9] = {
-8.65311750e-02f,+1.83219508e+00f,-1.44654854e+00f,+1.89087914e+00f,-1.03304238e+00f,
-6.17868822e-02f,+1.27000936e+00f,-6.14321092e-01f,+1.79871431e+00f,}; 
k2c_tensor test9_input_layer_14_input = {&test9_input_layer_14_input_array[0],2,9,{3,3,1,1,1}}; 
float keras_keras_tensor_9_test9_array[1] = {
+9.38555241e-01f,}; 
k2c_tensor keras_keras_tensor_9_test9 = {&keras_keras_tensor_9_test9_array[0],1,1,{1,1,1,1,1}}; 
float c_keras_tensor_9_test9_array[1] = {0}; 
k2c_tensor c_keras_tensor_9_test9 = {&c_keras_tensor_9_test9_array[0],1,1,{1,1,1,1,1}}; 
float test10_input_layer_14_input_array[9] = {
-1.19939252e+00f,+1.28754899e+00f,+5.94354676e-01f,-1.06750338e+00f,+3.41485309e-02f,
-4.70968451e-01f,-4.71469103e-01f,-1.77637859e+00f,-1.86556860e+00f,}; 
k2c_tensor test10_input_layer_14_input = {&test10_input_layer_14_input_array[0],2,9,{3,3,1,1,1}}; 
float keras_keras_tensor_9_test10_array[1] = {
+1.03091998e-02f,}; 
k2c_tensor keras_keras_tensor_9_test10 = {&keras_keras_tensor_9_test10_array[0],1,1,{1,1,1,1,1}}; 
float c_keras_tensor_9_test10_array[1] = {0}; 
k2c_tensor c_keras_tensor_9_test10 = {&c_keras_tensor_9_test10_array[0],1,1,{1,1,1,1,1}}; 
int main(){
 float errors[10];
 size_t num_tests = 10; 
size_t num_outputs = 1; 
keras2c_model_initialize(); 
clock_t t0 = clock(); 
keras2c_model(&test1_input_layer_14_input,&c_keras_tensor_9_test1); 
keras2c_model(&test2_input_layer_14_input,&c_keras_tensor_9_test2); 
keras2c_model(&test3_input_layer_14_input,&c_keras_tensor_9_test3); 
keras2c_model(&test4_input_layer_14_input,&c_keras_tensor_9_test4); 
keras2c_model(&test5_input_layer_14_input,&c_keras_tensor_9_test5); 
keras2c_model(&test6_input_layer_14_input,&c_keras_tensor_9_test6); 
keras2c_model(&test7_input_layer_14_input,&c_keras_tensor_9_test7); 
keras2c_model(&test8_input_layer_14_input,&c_keras_tensor_9_test8); 
keras2c_model(&test9_input_layer_14_input,&c_keras_tensor_9_test9); 
keras2c_model(&test10_input_layer_14_input,&c_keras_tensor_9_test10); 

clock_t t1 = clock(); 
printf("Average time over 10 tests: %e s \n", 
 ((double)t1-t0)/(double)CLOCKS_PER_SEC/(double)10); 
errors[0] = maxabs(&keras_keras_tensor_9_test1,&c_keras_tensor_9_test1); 
errors[1] = maxabs(&keras_keras_tensor_9_test2,&c_keras_tensor_9_test2); 
errors[2] = maxabs(&keras_keras_tensor_9_test3,&c_keras_tensor_9_test3); 
errors[3] = maxabs(&keras_keras_tensor_9_test4,&c_keras_tensor_9_test4); 
errors[4] = maxabs(&keras_keras_tensor_9_test5,&c_keras_tensor_9_test5); 
errors[5] = maxabs(&keras_keras_tensor_9_test6,&c_keras_tensor_9_test6); 
errors[6] = maxabs(&keras_keras_tensor_9_test7,&c_keras_tensor_9_test7); 
errors[7] = maxabs(&keras_keras_tensor_9_test8,&c_keras_tensor_9_test8); 
errors[8] = maxabs(&keras_keras_tensor_9_test9,&c_keras_tensor_9_test9); 
errors[9] = maxabs(&keras_keras_tensor_9_test10,&c_keras_tensor_9_test10); 
float maxerror = errors[0]; 
for(size_t i=1; i< num_tests*num_outputs;i++){ 
if (errors[i] > maxerror) { 
maxerror = errors[i];}} 
printf("Max absolute error for 10 tests: %e \n", maxerror);
keras2c_model_terminate(); 
if (maxerror > 1e-05) { 
return 1;} 
return 0;
} 

float maxabs(k2c_tensor *tensor1, k2c_tensor *tensor2){ 

    float x = 0; 

    float y = 0; 

    for(size_t i=0; i<tensor1->numel; i++){

    y = fabsf(tensor1->array[i]-tensor2->array[i]);
    if (y>x) {x=y;}}
    return x;}

