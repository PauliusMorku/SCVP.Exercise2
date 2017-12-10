#include "systemc.h"
#include "nand.h"
#include "stim.h"
#include "exor.h"
#include "mon.h"

int sc_main(int argc, char* argv[])
{
    sc_clock clk("clk", sc_time(1,SC_NS));
    sc_signal<bool> sigA, sigB, sigZ;

    sc_trace_file* Tf;
    Tf = sc_create_vcd_trace_file("traces");
    Tf->set_time_unit(100, SC_PS);
    sc_trace(Tf, clk   , "clk");
    sc_trace(Tf, sigA  , "A" );
    sc_trace(Tf, sigB  , "B" );
    sc_trace(Tf, sigZ  , "Z" );

    stim Stim1("Stimulus");
    Stim1.A(sigA);
    Stim1.B(sigB);
    Stim1.clk(clk);

    exor DUT("exor");
    DUT.A(sigA);
    DUT.B(sigB);
    DUT.Z(sigZ);

    Monitor mon("Monitor");
    mon.A(sigA);
    mon.B(sigB);
    mon.Z(sigZ);
    mon.clk(clk);

    sc_start();  // run forever
    sc_close_vcd_trace_file(Tf);

    return 0;
}
