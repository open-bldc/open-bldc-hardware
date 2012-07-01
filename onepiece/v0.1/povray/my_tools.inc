#include "tools.inc"

#macro MY_TOOLS_AXIS(mac_x_ver,mac_y_ver,mac_z_ver,mac_x_rot,mac_y_rot,mac_z_rot)
object {
  union {
    union {
      cylinder{<0.,0.,0.><25.,0.,0.> 0.1}
      text { ttf "timrom.ttf" "X" 1, 0 scale <2,2,2> translate(<20, 0, 0>)}
      texture{ pigment{rgb<1,0,0>}}
    }   
    union {
      cylinder{<0.,0,0.><0.,25.,0.> 0.1}
      text { ttf "timrom.ttf" "Y" 1, 0 scale <2,2,2> translate(<0, 20, 0>)}
      texture{ pigment{rgb<0,1,0>}}
    }   
    union {
      cylinder{<0.,0,0.><0.,0.,25.> 0.1}
      text { ttf "timrom.ttf" "Z" 1, 0 scale <2,2,2> translate(<0, 0, 20>)}
      texture{ pigment{rgb<0,0,1>}}
    }   
  translate(<mac_x_ver,mac_y_ver,mac_z_ver>)
  rotate(<mac_x_rot,mac_y_rot,mac_z_rot>)	
  }
} 
#end

#macro MY_TOOLS_STANDOFF(_height)
union{
    intersection {
      #local M = 3;
      #local A = 5.5;
      #local B = 2.4;
      //3 boxes for hexagonal shape
      box {<-A/2, 0,-2*M>, <+A/2,_height,2*M> }
      box {<-A/2, 0,-2*M>, <+A/2,_height,2*M> rotate -60*y}
      box {<-A/2, 0,-2*M>, <+A/2,_height,2*M> rotate +60*y}
      pigment{rgb<0,0,1>}
    }
   cylinder{<0,0,0><0,_height,0> 0.25 pigment{rgb<0,0,1>}}
   object{ TOOLS_SCREW(3, 5, 1, Gray30 )  rotate z*180 translate y*-2 }
   object{ TOOLS_NUT (M, 1, rgb<0,0,1>)  translate(<0, _height, 0>)}
}
#end

#macro ROUNDED_TAB(W, HD)
 difference{
    box {<-W/2, 0,-W/2>, <0.7*W,2,W/2>}
    cylinder {<0, -0.1, 0>, <0,2.1,0> HD/2}
    difference{
      box {<-W/2-0.1, -0.1,-W/2-0.1>, <0,2.1,W/2+0.1>}
      cylinder {<0, -0.2, 0>, <0,2.2,0> W/2}
    }
  }
#end

#macro MY_TOOLS_NEW_STANDOFF()
union{
  #local W = 6;
  #local DX = 9.76;
  #local DY = 10.;
  #local HD = 3;
  #local a = atan2(DY,DX-1.2*W);
  #local l = sqrt((DX-1.2*W)*(DX-1.2*W)+DY*DY)+0.29*W; 	
  union {
    box {<0, 0,-W/2>, <l,2,W/2> rotate z*a*180/3.14 translate x*(0.7*W)}
    object{ROUNDED_TAB(W, HD)}
    object{ROUNDED_TAB(W, HD) rotate y*180 translate <DX, DY, 0>}
    pigment{rgb<1,0,0>}
  }
  object{ TOOLS_SCREW(3, 5, 1, Gray30 ) translate y*2 }
  object{ TOOLS_SCREW(2.5, 5, 1, Gray30 ) translate <DX, 2+DY+1.5,0> }
}
#end