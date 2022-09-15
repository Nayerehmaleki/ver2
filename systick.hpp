

#include "inc.hpp"
struct task_t{
    void (*task)(void);
    //task_t* task;
    int interval;
    char name_flag;
    bool flag;
    int exe_time;
};

class systick_t {
public:
    void add_task (void(*task)(void),int interval,bool flag);
    static systick_t* get_instance();
    void systick_handler(void);
    void systick_isr(void);
    void tick(void);
private:
    systick_t();
    int tick_counter;
    vector <task_t*> task;
};
