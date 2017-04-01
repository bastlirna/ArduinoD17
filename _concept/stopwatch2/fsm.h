#ifndef _FSM_H_
#define _FSM_H_


typedef void (*void_fn_t)(void);

class Machine
{
 public:
    // Create an instance of the bounce library
    Machine();

    unsigned long millis();

    void change(void_fn_t new_state);

    void loop();

 protected:
    unsigned long previous_millis;
    void_fn_t current_state;
};

#endif