#ifndef STIMULUS_H
#define STIMULUS_H

#include "systemc.h"
SC_MODULE(stim)
{
    sc_out<bool> A, B;
    sc_in<bool> Clk;



    void StimGen()
    {
        wait(SC_ZERO_TIME);
        wait(Clk.negedge_event());
        A.write(false);
        B.write(false);
        wait(Clk.posedge_event());
        wait(Clk.negedge_event());
        A.write(false);
        B.write(true);
        wait(Clk.posedge_event());
        wait(Clk.negedge_event());
        A.write(true);
        B.write(false);
        wait(Clk.posedge_event());
        wait(Clk.negedge_event());
        A.write(true);
        B.write(true);
        wait(Clk.posedge_event());
        wait(Clk.negedge_event());
        A.write(false);
        B.write(false);
        sc_stop();
    }
    SC_CTOR(stim)
    {
        SC_THREAD(StimGen);
        sensitive << Clk;
    }
};

#endif
