/*******************************************************************************/
// Wires
/*******************************************************************************/
#macro WIRE(mac_posA, mac_posB, mac_offset_dir, mac_stripA, mac_stripB, mac_rad, mac_ins, mac_ins_col)
	union{
		#declare wir_rad = mac_rad;
		#declare wir_ins = mac_ins;
		#declare wir_ins_rad = wir_rad + wir_ins;
		#declare wir_ins_dia = wir_ins_rad * 2;
		#if(mac_offset_dir = 1)
			#declare wir_pcb_offset = (wir_rad + pcb_cuheight);
		#else
			#declare wir_pcb_offset = -1 * (wir_rad*2 + pcb_cuheight + pcb_height);
		#end

		#declare stripA = <mac_posA.x,            mac_posA.y+wir_pcb_offset, mac_posA.z>;
		#declare wireA  = <mac_posA.x,            mac_posA.y+wir_pcb_offset, mac_posA.z+mac_stripA>;
		#declare wireAB = <mac_posA.x,            mac_posA.y+wir_pcb_offset, mac_posB.z>;
		#declare wireB  = <mac_posB.x-mac_stripB, mac_posB.y+wir_pcb_offset, mac_posB.z>;
		#declare stripB = <mac_posB.x,            mac_posB.y+wir_pcb_offset, mac_posB.z>;

		cylinder{stripA wireA wir_rad pigment{P_Copper4} finish{F_MetalC ambient (0.1 * global_ambient_mul)}}
		cylinder{wireA wireAB wir_ins_rad pigment{mac_ins_col}}
		sphere{wireAB wir_ins_rad pigment{mac_ins_col}}
		cylinder{wireAB wireB wir_ins_rad pigment{mac_ins_col}}
		cylinder{wireB stripB wir_rad pigment{P_Copper4} finish{F_MetalC ambient (0.1 * global_ambient_mul)}}
	}
#end

#macro PWIRE(mac_ins_col, mac_y_offs)
	WIRE(<52.2732,0,2.8194+1.17>,<-5,0,-1>,mac_y_offs,-2.8194-1.17,-1,0.751,0.3,mac_ins_col)
/*
	union{
		cylinder{<-5,0,-1><-4.5,0,-1>0.715 pigment{P_Copper4} finish{F_MetalC ambient (0.1 * global_ambient_mul)}}
		cylinder{<-4.5,0,-1><52.2732,0,-1>1.015 pigment{mac_ins_col}}
		sphere{<52.2732,0,-1>1.015 pigment{mac_ins_col}}
		cylinder{<52.2732,0,-1><52.2732,0,0>1.015 pigment{mac_ins_col}}
		cylinder{<52.2732,0,0><52.2732,0,2.8194+1.17>0.715 pigment{P_Copper4} finish{F_MetalC ambient (0.1 * global_ambient_mul)}}
		translate<0,mac_y_offs,0>
	}
*/
#end
#macro PHWIRE(mac_ins_col, mac_x, mac_nr)
	#declare wir_rad = 0.385;
	#declare wir_ins = 0.25;
	#declare wir_ins_rad = wir_rad + wir_ins;
	#declare wir_ins_dia = wir_ins_rad * 2;
	WIRE(<mac_x,0,4.1014>,<64.5,0,11.5+wir_ins_rad+(wir_ins_dia*mac_nr)>,1,2.44,1,wir_rad,wir_ins,mac_ins_col)
#end
