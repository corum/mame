// license:BSD-3-Clause
// copyright-holders:Curt Coder, Mike Naberezny
/**********************************************************************

    SSE HardBox emulation

**********************************************************************/

#ifndef MAME_BUS_IEEE488_HARDBOX_H
#define MAME_BUS_IEEE488_HARDBOX_H

#pragma once

#include "ieee488.h"
#include "cpu/z80/z80.h"
#include "machine/i8251.h"
#include "machine/i8255.h"
#include "imagedev/harddriv.h"
#include "machine/corvushd.h"



//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

// ======================> hardbox_device

class hardbox_device :  public device_t,
						public device_ieee488_interface
{
public:
	// construction/destruction
	hardbox_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

protected:
	// device-level overrides
	virtual void device_start() override;
	virtual void device_reset_after_children() override;

	// optional information overrides
	virtual const tiny_rom_entry *device_rom_region() const override;
	virtual void device_add_mconfig(machine_config &config) override;
	virtual ioport_constructor device_input_ports() const override;

	// device_ieee488_interface overrides
	virtual void ieee488_ifc(int state) override;

private:
	DECLARE_READ8_MEMBER( ppi0_pa_r );
	DECLARE_WRITE8_MEMBER( ppi0_pb_w );
	DECLARE_READ8_MEMBER( ppi0_pc_r );

	DECLARE_READ8_MEMBER( ppi1_pa_r );
	DECLARE_WRITE8_MEMBER( ppi1_pb_w );
	DECLARE_READ8_MEMBER( ppi1_pc_r );
	DECLARE_WRITE8_MEMBER( ppi1_pc_w );

	enum
	{
		LED_A,
		LED_B,
		LED_READY
	};

	required_device<cpu_device> m_maincpu;
	required_device<corvus_hdc_device> m_hdc;

	int m_ifc;  // Tracks previous state of IEEE-488 IFC line
};

// device type definition
DECLARE_DEVICE_TYPE(HARDBOX, hardbox_device)


#endif // MAME_BUS_IEEE488_HARDBOX_H
