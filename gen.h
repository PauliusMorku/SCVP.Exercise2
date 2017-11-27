#ifndef GEN_H
#define GEN_H

#include "systemc.h"
#endif // GEN_H

SC_MODULE(clockGenerator){
    public:
    sc_out<bool> clk;
    bool value;
    sc_time period;

    SC_HAS_PROCESS(clockGenerator);
    clockGenerator(const sc_module_name &name, sc_time period) :
        sc_module(name), period(period), value(true)
    {
        SC_THREAD(generation);

    }

    void generation(){
        while (true){
            value = !value;
            clk.write(value);
            wait(period/2);
        }
    }

};
