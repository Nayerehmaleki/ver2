#include "systick.hpp"

systick_t ::systick_t(){
tick_counter=0;
}
void systick_t :: add_task (void(*task)(void),int interval,bool flag){
    cout <<"new task"<<endl;
    task_t* new_task = new task_t();
    new_task->interval = interval;
    new_task->task = task;
    cout << "--------"<<new_task->task <<endl;
    new_task->exe_time = new_task -> interval+ this->tick_counter;
    //new_task->name_flag = name_flag;
    new_task->flag = flag;
    this->task.push_back(new_task);

}

systick_t* systick_t:: get_instance(void){
    static systick_t* instance;
    if (instance == NULL){
            instance = new systick_t();
    }
    return instance;
}

void systick_t:: systick_handler(void){
    static int timer = 0;
    if (++timer >= 1000 ){
        timer = 0;
        systick_isr();
    }

}

void systick_t::systick_isr(void){
    tick();
    for(int i = 0 ;i<task.size() ; i++ ){
            if((task[i]->exe_time == tick_counter )&& (task[i]->flag == true )){
                task[i]->task();
                task[i]->exe_time = task[i]->interval + tick_counter;
                cout <<"flag "<<task[i]->task<< endl;
                //task[i]->name_flag;
            }
    }
}

void systick_t::tick(void){
    cout <<"tick_counter :"<<tick_counter <<endl;
    this -> tick_counter++;
}
