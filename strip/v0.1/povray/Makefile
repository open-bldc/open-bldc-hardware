
#EAGLE3D_HOME=/home/poine/work/eagle3d/eagle3d/
EAGLE3D_HOME=/Applications/eagle3d/

POVLIB=+L$(EAGLE3D_HOME)/povray  +L/usr/share/fonts/truetype/msttcorefonts +L/Applications/eagle3d/msttfonts

strip_small:
	povray -Istrip_scene.pov $(POVLIB) +W800 +H600 +Ostrip.png

strip_big:
	povray -Istrip_scene.pov $(POVLIB)  +W1600 +H1200 +Q9 +A0.3 +R5 +Ostrip_big.png

clean:
	rm *~
