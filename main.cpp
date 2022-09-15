
#include "inc.hpp"
#include "systick.hpp"

bool flag_a = false;
bool flag_b = false;


void task_a(){
    //flag_a = true;
}

void task_b(){
   // flag_b = true;
}


//void task_A(){
    //flag_a = false;
    //cout<< "task A!"<< endl;
//}
//void task_B(){
    //flag_b = false;
    //cout<< "task B!"<< endl;
//}
int main(void){
    //cout << systick_t::get_instance <<endl;
    //cout << systick_t::get_instance <<endl;
    cout<<"Hello"<<endl;

    systick_t::get_instance()->add_task(task_a,10,true);
    systick_t::get_instance()->add_task(task_b,14,true);
    while(1){
        systick_t::get_instance()->systick_handler();
        //if(flag_a){
            //task_A();
        //}
        //if(flag_b){
            //task_B();
        //}
    }




    return 0;
}
