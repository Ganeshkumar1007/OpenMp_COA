#include<stdio.h>
#include<omp.h>
#include "helloworld_performance_analysis.h"
#include"ret_et_helloworld.h"
#include"ret_tid_helloworld.h"
int main() {

    ret_et_helloworld_srl();
    ret_et_helloworld_prl();
    fn_ret_tid_helloworld_srl();
    fn_ret_tid_helloworld_prl();
    fn_ret_tid_helloworld_srl();
    fn_ret_tid_helloworld_prl();

    return 0;
}
