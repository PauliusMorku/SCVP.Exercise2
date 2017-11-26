#ifndef EXOR_H
#define EXOR_H

#include "systemc.h"
#include "nand.h"

// TODO: Insert your code here
SC_MODULE(exor)
{
    sc_in<bool> A, B;
    sc_out<bool> Z;


    nand nanda, nandb, nandc, nandd;

    sc_signal<bool> tempa, tempb, tempc;

    SC_CTOR(exor): A("A"), B("B"), Z("Z"), nanda("nanda"), nandb("nandb"), nandc("nandc"), nandd("nandd")
    {
        nanda.A.bind(A);
        nanda.B.bind(B);
        nanda.Z.bind(tempa);

        nandb.A.bind(tempa);
        nandb.B.bind(B);
        nandb.Z.bind(tempb);

        nandc.A.bind(A);
        nandc.B.bind(tempa);
        nandc.Z.bind(tempc);

        nandd.A.bind(tempa);
        nandd.B.bind(tempb);
        nandd.Z.bind(Z);

    }
};

#endif // EXOR_H
