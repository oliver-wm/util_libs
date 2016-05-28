/*
 * Copyright 2016, Data61 CSIRO
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(D61_BSD)
 */
#include <platsupport/i2c.h>

#include "../../arch/arm/clock.h"
#include "../../services.h"
#include <assert.h>
#include <string.h>
#include <utils/util.h>


static struct clock master_clk = { CLK_OPS_DEFAULT(MASTER) };

int
clock_sys_init(ps_io_ops_t* o, clock_sys_t* clock_sys)
{
    clock_sys->priv = (void*)0xdeadbeef;
    clock_sys->get_clock = &ps_get_clock;
    clock_sys->gate_enable = NULL;
    return 0;
}

void
clk_print_clock_tree(clock_sys_t* sys)
{
    clk_t *clk = clk_get_clock(sys, CLK_MASTER);
    clk_print_tree(clk, "");
}


clk_t* ps_clocks[] = {
    [CLK_MASTER]   = &master_clk,
};

/* These frequencies are NOT the recommended
 * frequencies. They are to be used when we
 * need to make assumptions about what u-boot
 * has left us with. */
freq_t ps_freq_default[] = {
    [CLK_MASTER]   =  0 * MHZ,
};