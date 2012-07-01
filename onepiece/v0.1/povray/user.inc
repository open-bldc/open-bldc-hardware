/********************************************************************************************************************************************
// Molex 53398 ( 1.25 pitch, vertical feeding, SMD )
********************************************************************************************************************************************/
#macro USER_CON_SMD_MOLEX_53398_GND(n)
union{
        #local L = n * 1.25 + 1.75;
        #local h = 4.7;
        #local l = 3.7;

        #local pin =
        union{
          box{<-0.18, 0.01 ,-0.35><0.18, 3.65, 0.35> translate<0, 0, -1.65>}
          cylinder {<0, 0, -0.35> <0, 0, 0.35> 0.18  scale < 1, 2, 1> translate <0, 3.65, -1.65>}
	  box{<-0.18,0.2,1.0><0.18,0.8,-1.8> }
	  box{<-0.18,0.0,1.0><0.18,0.8,1.5> }
        }

        //Pins
        union{
          #local i = 0;
          #while(i<n)
	  object{pin translate<-(n-1)*1.25/2+i*1.25,0,0>}
          #local i = i + 1;
          #end
	  object{ TOOLS_RECT_BOGEN(0.5,90,0.25,2.2,1.2,1) rotate<0,180,0> translate<-L/2+0.15,0.125,-1.7> } // solder tabs
          object{ TOOLS_RECT_BOGEN(0.5,90,0.25,2.2,1.2,1) rotate<0,0,0>   translate< L/2-0.15,0.125,-1.7> } // 
	  texture{col_silver}
        }
	//	box{<-5.075, 0.01, 0><5.075,0.02, -3>       texture{pigment{Gray30}}} // helper aka pcboard pattern
        #if (1)
        object{
	  difference{  
	    box{<-(L+3)/2, 0.01, 0><(L+3)/2,4.7, -3.7>}        // body bounding
	    box{<  (L)/2, 2.4, 0.1>< (L+4)/2,4.8, -3.8>}       // most outer cutout
	    box{< -(L)/2, 2.4, 0.1><-(L+4)/2,4.8, -3.8>}       // most outer cutout 2
	    box{<  (L)/2, -0.01, 0.1>< (L+4)/2,4.8, -0.6>}     // most outer cutout
	    box{< -(L)/2, -0.01, 0.1><-(L+4)/2,4.8, -0.6>}     // most outer cutout 2
	    box{< -(L)/2+0.6, 1.5, -0.5><(L)/2-0.6,4.8, -3.3>} // big center hole
	    box{< -(L)/2+1.6, 1.5,  0.1><(L)/2-1.6,4.8, -3.3>} // second big center hole
	    box{< -(L)/2+0.6, -0.1,  0.1><(L)/2-0.6,0.3, -3.8>} // lower hole
            #local i = 1;
            #while(i<n+1)
	    box{<-0.3,0.2,0.1> <0.3,0.7,-3.8> translate<-(n+1)*1.25/2+i*1.25,0,0>}
            #local i = i + 1;
            #end	  }
	  translate<0.,0.,0.85> texture{pigment{White}}  
	}
        #end

}
#end
#macro USER_CON_SMD_MOLEX_53398_2()
object{USER_CON_SMD_MOLEX_53398_GND(2)}
#end
#macro USER_CON_SMD_MOLEX_53398_3()
object{USER_CON_SMD_MOLEX_53398_GND(3)}
#end
#macro USER_CON_SMD_MOLEX_53398_4()
object{USER_CON_SMD_MOLEX_53398_GND(4)}
#end
#macro USER_CON_SMD_MOLEX_53398_5()
object{USER_CON_SMD_MOLEX_53398_GND(5)}
#end
#macro USER_CON_SMD_MOLEX_53398_6()
object{USER_CON_SMD_MOLEX_53398_GND(6)}
#end
#macro USER_CON_SMD_MOLEX_53398_7()
object{USER_CON_SMD_MOLEX_53398_GND(7)}
#end
#macro USER_CON_SMD_MOLEX_53398_8()
object{USER_CON_SMD_MOLEX_53398_GND(8)}
#end
#macro USER_CON_SMD_MOLEX_53398_9()
object{USER_CON_SMD_MOLEX_53398_GND(9)}
#end
#macro USER_CON_SMD_MOLEX_53398_10()
object{USER_CON_SMD_MOLEX_53398_GND(10)}
#end
#macro USER_CON_SMD_MOLEX_53398_11()
object{USER_CON_SMD_MOLEX_53398_GND(11)}
#end
#macro USER_CON_SMD_MOLEX_53398_12()
object{USER_CON_SMD_MOLEX_53398_GND(12)}
#end
#macro USER_CON_SMD_MOLEX_53398_13()
object{USER_CON_SMD_MOLEX_53398_GND(13)}
#end
#macro USER_CON_SMD_MOLEX_53398_14()
object{USER_CON_SMD_MOLEX_53398_GND(14)}
#end
#macro USER_CON_SMD_MOLEX_53398_15()
object{USER_CON_SMD_MOLEX_53398_GND(15)}
#end




/********************************************************************************************************************************************
// MPX6115 pressure sensor
********************************************************************************************************************************************/
#macro USER_MPXH6115AC6T1()
union{
  object {
    Round_Box(<-4.25,0,-4.25>, <4.25,4.8,4.25>, 1, 0) // body
    texture{pigment{Gray30}}
  }
  object {
    difference{
      cylinder{<0,4.8,0><0,9.7,0>1.5}                 // port
      cylinder{<0,4.8,0><0,9.8,0>1.}
    }
    texture{pigment{Gray30}} 
  }
}
#end

/********************************************************************************************************************************************
// MPX6115 pressure sensor
********************************************************************************************************************************************/
#macro USER_MPXV5004DP()
union{
  object {
    Round_Box(<-6.,0,-6.>, <6.,9.7,6.>, 1, 0) // body
    texture{pigment{Gray30}}
  }
  #local port =
  object {
    difference{
      cylinder{<0,0.,0><0,0., 6.35>1.5}                 // port
      cylinder{<0,0.,0><0,0., 6.45>1. }
    }
    texture{pigment{Gray30}} 
  }
  object { port  translate<2.15 ,0.75,-12>}
  object { port  translate<-2.15,8.95,-12>}
}
#end

/********************************************************************************************************************************************
// PTH08080WAH switching power supply module
********************************************************************************************************************************************/
#macro USER_PTH_TH()
union{
  object {
    box{<-7.62,2.5,-6.35> <7.62,4.,6.35>} // body
    texture{pigment{rgb<0.117647,0.243137,0.015686>}}
  }
  #local pin =
  object {
    cylinder{<0,0.1,0><0,-5.55,0>0.5}
    translate<-7.62,4,-6.35>
    texture{Gold_Texture}
  }
  union{
    object {pin translate<1.52,0.,2.79>} // pin 1
    object {pin translate<1.52,0.,6.35>} // pin 2
    object {pin translate<1.52,0.,9.91>} // pin 3
    object {pin translate<13.71,0.,1.52>} // pin 4
    object {pin translate<13.71,0,11.17>} // pin 5
  }
}
#end

/********************************************************************************************************************************************
// 
********************************************************************************************************************************************/
#macro SPC_CTS_CRYSTAL(value)
  union{
    superellipsoid { <0.15, 0.15> scale <2.7, 0.455,1.7> translate <0, 0.6+0.455, 0> texture{T_Brass_5A} }
    superellipsoid { <0.15, 0.15> scale <2.55, 0.55,1.55> translate <0, 0.6+0.55, 0> texture{T_Brass_5A} }
    superellipsoid { <0.15, 0.15> scale <2.5, 0.61,1.5> translate <0, 0.6+0.61, 0> texture{T_Brass_5A} }
    
    box{<-2.3,1.8,-1><+2.3,1.83,+1> pigment{Gray50}}
    box{<-2,1.8,-1.3><+2,1.83,+1.3> pigment{Gray50}}
    cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<-2,0,+1> pigment{Gray50}}    
    cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<-2,0,-1> pigment{Gray50}}    
    cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<+2,0,+1> pigment{Gray50}}    
    cylinder{<0,1.8,0><0,1.83,0> 0.3 translate<+2,0,-1> pigment{Gray50}}    
    text {ttf global_fontfile_arial_bold "CTS" 0.05, 0 pigment{Gray30} scale <1,0,.8> rotate<90,0,0> translate<-2,1.84,+0.4>}  // Marking
    text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{Gray20} scale <0.8,1,1> rotate<90,0,0> translate<-1.5,1.84,-0.9>}  // Marking
    translate <0, -0.55, 0.>
  }
#end

/*******************************************************************************/
// Analog device ADXL320 accelerometer
/*******************************************************************************/
#macro USER_ADXL320()
union {
  difference {
    object {
      box{<-2,0,-2><2,1.45,2>}     // Body
      pigment{Gray30}
    } 
    cylinder{<0,1.35,0><0,1.55,0>0.2 translate<-1.5,0,1.5> texture{col_silver}}
  }
  object {
    text {ttf besch_font "ADXL" 0.5, 0 rotate<90,0,0> scale 0.8 translate<-1,1.46,0>}
    pigment { White }
  }
}
#end

/*******************************************************************************/
// Analog device ADXR gyro
/*******************************************************************************/
#macro USER_ADXR_GYRO()
union{
  object {
    box{<-3.5,0,-3.5><3.5,2.5,3.5>}     // Body
    pigment{rgb(<0.400, 0.320, 0.220>)}
  }
  object {
    text {ttf besch_font "ADXRS300" 0.5, 0 rotate<90,0,0> scale 0.8 translate<-2,2.51,0>}
    pigment { White }
  }
  translate<0,0.4,0>
}
#end

/*******************************************************************************/
// PNI MS2100 magnetometer
/*******************************************************************************/
#macro USER_QFN20()
union{
  difference {
    object {
      box{<-3.5,0,-3.5><3.5,1.35,3.5>}     // Body
      pigment{Gray30}
    }
    cylinder{<0,1.25,0><0,1.45,0>0.2 translate<-2.5,0,2.5> texture{col_silver}}
  }
  object {
    text {ttf besch_font "MS2100" 0.5, 0 rotate<90,0,0> scale 0.8 translate<-2,1.36,0>}
    pigment { White }
  }
  translate<0,0.4,0>
}
#end

/*******************************************************************************/
// STM32 in VFQFPN36 package
/*******************************************************************************/
#macro USER_VFQFPN36()
union{
  object {
    box{<-3,0,-3><3,0.9,3>}     // Body
    pigment{Gray30}
  }
  object {
    text {ttf besch_font "STM32" 0.5, 0 rotate<90,0,0> scale 0.8 translate<-2,0.901,0>}
    pigment { White }
  }
  translate<0,0.4,0>
}
#end

/*******************************************************************************/
// Fairchild FDMC7664 in MLP33 mosfet
/*******************************************************************************/
#macro USER_MLP33()
union{
  object {
    box{<-1.63,0,-1.63><1.63,0.8,1.63>}     // Body
    pigment{Gray30}
  }
  object {
    text {ttf besch_font "FDMC7664" 0.1, 0 rotate<90,0,0> scale 0.5 translate<-1.5,0.801,0>}
    pigment { White }
  }
  translate<0,0.4,0>
}
#end

/*******************************************************************************/
// National LM5101A in LLP-10 half bridge driver
/*******************************************************************************/
#macro USER_LLP10()
union{
  object {
    box{<-2,0,-2><2,0.8,2>}     // Body
    pigment{Gray30}
  }
  object {
    text {ttf besch_font "LM5101" 0.1, 0 rotate<90,0,0> scale 0.5 translate<-1.5,0.801,0>}
    pigment { White }
  }
  translate<0,0.4,0>
}
#end

/*******************************************************************************/
// National LM317L in Microbump6
/*******************************************************************************/
#macro USER_MICROBUMP6()
union{
  object {
    box{<-0.8075,0,-0.4775><0.8075,0.85,0.4775>}     // Body
    pigment{Gray30}
  }
  object {
    text {ttf besch_font "LM317L" 0.1, 0 rotate<90,0,0> scale 0.35 translate<-0.7,0.851,0>}
    pigment { White }
  }
  translate<0,0.4,0>
}
#end

/*******************************************************************************/
// ASE oscillator
/*******************************************************************************/
#macro USER_ASE_OSCILLATOR(value)
union{
  difference {
    box{<-1.6,0,-1.25>    <+1.6,0.8,+1.25>  pigment{Gray30}}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.3 translate < 1.6,0, 1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate < 1.6,0,-1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate <-1.6,0, 1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate <-1.6,0,-1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate <0.,0, 1.25>}
    cylinder {<0,-0.1,0>  <0,1.1,0> 0.2 translate <0.,0,-1.25>}
  }
  box{<-1.4,0.8,-1.05>  <+1.4,0.95,+1.05> texture{col_gold}}
  box{<-1.3,0.95,-0.95><+1.3,1.,+0.95>   texture{col_silver}}

  text {ttf global_fontfile_arial_bold "ASE" 0.05, 0 pigment{Gray30} scale <0.8,1.,.7> rotate<90,0,0> translate<-0.8,1.01,+0.1>}  // Marking
  text {ttf global_fontfile_arial_bold value 0.05, 0 pigment{Gray20} scale <0.6,1,0.6> rotate<90,0,0> translate<-0.8,1.01,-0.8>}  // Marking
  }
#end
