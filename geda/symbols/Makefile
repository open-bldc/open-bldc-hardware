##
## Open-BLDC - Open BrushLess DC Motor Controller
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

GENERATED_SYMBOLS = \
	ir2101.sym acs712.sym lp2992.sym st662a.sym stm32f103xx_lqfp48.sym \
	jtag_10pin.sym tinyconn10.sym tinyconn3.sym

all: $(GENERATED_SYMBOLS)

%.sym: %.src
	@tragesym $< $@

clean:
	@rm -f $(GENERATED_SYMBOLS)

