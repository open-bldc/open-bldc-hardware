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

SCH = open-bldc
BOARD = board

GEDADIR = $(HOME)/geda
SCHEMEDIR = $(GEDADIR)/share/gEDA/scheme

# all: symbols sch-ps sch-pdf pcb-gerber pcb-ps pcb-png
all: symbols sch-ps sch-pdf

symbols:
	$(MAKE) -C symbols

sch-ps:
	@# This must be done in an X11 session, doesn't work on console.
	gschem -p -o $(SCH).ps -s $(SCHEMEDIR)/print.scm $(SCH).sch

sch-pdf:
	ps2pdf -sPAPERSIZE=a4 $(SCH).ps

pcb-gerber:
	pcb -x gerber --gerberfile $(BOARD) $(BOARD).pcb

pcb-ps:
	pcb -x ps --psfile $(BOARD).ps $(BOARD).pcb

pcb-png:
	pcb -x png --dpi 300 --only-visible --outfile $(BOARD).png $(BOARD).pcb

drc: $(SCH).sch
	# gnetlist -g drc2 $(SCH).sch -o $(SCH).drc
	gnetlist -g drc2 $(SCH).sch -o -
	@# Use the following line to ignore DRC errors.
	@# gnetlist -g drc2 -o - $(SCH).sch -O ignore-warnings-in-return-value

bom:
	gnetlist -g partslist3 -o $(SCH).bom $(SCH).sch 
	@# The below 'bom2' also needs an 'attribs' file as input.
	@# gnetlist -g bom2 -o $(SCH).bom $(SCH).sch 

clean:
	$(MAKE) -C symbols clean
	@rm -f $(SCH).sch~ $(SCH).ps $(SCH).pdf
	@rm -f $(BOARD).net $(BOARD).cmd $(BOARD).fab.gbr $(BOARD).ps
	@rm -f $(BOARD).new.pcb
	@rm -f $(SCH).drc
	@rm -f $(SCH).bom

.PHONY: symbols

