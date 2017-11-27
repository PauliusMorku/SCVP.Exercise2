#include "systemc.h"
#include "nand.h"
#include "stim.h"
#include "exor.h"
#include "mon.h"
#include "gen.h"

int sc_main(int argc, char* argv[])
{
    clockGenerator g("clock_1GHz", sc_time(1,SC_NS));
    sc_signal<bool> clk, sigA, sigB, sigZ;

    g.clk.bind(clk);

    stim Stim1("Stimulus");
    Stim1.A(sigA);
    Stim1.B(sigB);
    Stim1.Clk(clk);

    exor DUT("exor");
    DUT.A(sigA);
    DUT.B(sigB);
    DUT.Z(sigZ);

    Monitor mon("Monitor");
    mon.A(sigA);
    mon.B(sigB);
    mon.Z(sigZ);
    mon.Clk(clk);


    sc_trace_file* Tf;
    Tf = sc_create_vcd_trace_file("traces");
    sc_trace(Tf, clk   , "clk");
    sc_trace(Tf, sigA  , "A" );
    sc_trace(Tf, sigB  , "B" );
    sc_trace(Tf, sigZ  , "Z" );

    sc_start();  // run forever
    //sc_close_vcd_trace_file(Tf);

    return 0;
}
