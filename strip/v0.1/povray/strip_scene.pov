
#version 3.5;

//Enable/Disable showing of wires
#declare show_wires=on;
//changes the apperance of resistors (1 Blob / 0 real)
#declare global_res_shape = 1;
//randomize color of resistors 1=random 0=same color
#declare global_res_colselect = 0;
//Number of the color for the resistors
//0=Green, 1="normal color" 2=Blue 3=Brown
#declare global_res_col = 1;
//Set to on if you want to render the PCB upside-down
#declare pcb_upsidedown = off;
//Set to x or z to rotate around the corresponding axis (referring to pcb_upsidedown)
#declare pcb_rotdir = z;
//Set the length off short pins over the PCB
#declare pin_length = 2.5;
#declare global_diode_bend_radius = 1;
#declare global_res_bend_radius = 1;
#declare global_solder = on;

#declare global_show_screws = on;
#declare global_show_washers = on;
#declare global_show_nuts = on;

#declare global_use_radiosity = on;

#declare global_ambient_mul = 1;
#declare global_ambient_mul_emit = 0;

//Animation
#declare global_anim = off;
#local global_anim_showcampath = no;

#declare global_fast_mode = off;

#declare col_preset = 0;
#declare pin_short = on;

#declare e3d_environment = on;

#local cam_x = 0;
#local cam_y = 214;
#local cam_z = -26;
#local cam_a = 20;
#local cam_look_x = 0;
#local cam_look_y = -1;
#local cam_look_z = 0;

#local pcb_rotate_x = 45;
#local pcb_rotate_y = -20;
#local pcb_rotate_z = -20;

#local pcb_board = on;
#local pcb_parts = on;
#local pcb_wire_bridges = off;
#if(global_fast_mode=off)
	#local pcb_polygons = on;
	#local pcb_silkscreen = on;
	#local pcb_wires = on;
	#local pcb_pads_smds = on;
#else
	#local pcb_polygons = off;
	#local pcb_silkscreen = off;
	#local pcb_wires = off;
	#local pcb_pads_smds = off;
#end

#local lgt1_pos_x = 25;
#local lgt1_pos_y = 38;
#local lgt1_pos_z = 6;
#local lgt1_intense = 0.711007;
#local lgt2_pos_x = -25;
#local lgt2_pos_y = 38;
#local lgt2_pos_z = 6;
#local lgt2_intense = 0.711007;
#local lgt3_pos_x = 25;
#local lgt3_pos_y = 38;
#local lgt3_pos_z = -4;
#local lgt3_intense = 0.711007;
#local lgt4_pos_x = -25;
#local lgt4_pos_y = 38;
#local lgt4_pos_z = -4;
#local lgt4_intense = 0.711007;

//Do not change these values
#declare pcb_height = 1.000000;
#declare pcb_cuheight = 0.035000;
#declare pcb_x_size = 67.000000;
#declare pcb_y_size = 11.500000;
#declare pcb_layer1_used = 1;
#declare pcb_layer16_used = 1;
#declare inc_testmode = off;
#declare global_seed=seed(645);
#declare global_pcb_layer_dis = array[16]
{
	0.000000,
	0.333333,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.000000,
	0.666667,
	1.035000,
}
#declare global_pcb_real_hole = 2.000000;

#include "e3d_tools.inc"
#include "e3d_user.inc"

global_settings{charset utf8}

#declare col_brd = texture{pigment{Black}}
#declare col_wrs = texture{pigment{Gray10}}
#declare col_pds = texture{T_Silver_5A}
#declare col_hls = texture{pigment{Black}}
#declare col_bgr = Gray50;
#declare col_slk = texture{pigment{White}}
#declare col_thl = texture{pigment{Gray10}}
#declare col_pol = texture{pigment{Gray10}}

#if(e3d_environment=on)
sky_sphere {pigment {Navy}
pigment {bozo turbulence 0.65 octaves 7 omega 0.7 lambda 2
color_map {
[0.0 0.1 color rgb <0.85, 0.85, 0.85> color rgb <0.75, 0.75, 0.75>]
[0.1 0.5 color rgb <0.75, 0.75, 0.75> color rgbt <1, 1, 1, 1>]
[0.5 1.0 color rgbt <1, 1, 1, 1> color rgbt <1, 1, 1, 1>]}
scale <0.1, 0.5, 0.1>} rotate -90*x}
plane{y, -10.0-max(pcb_x_size,pcb_y_size)*abs(max(sin((pcb_rotate_x/180)*pi),sin((pcb_rotate_z/180)*pi)))
texture{T_Chrome_2D
normal{waves 0.1 frequency 3000.0 scale 3000.0}} translate<0,0,0>}
#end

//Animation data
#if(global_anim=on)
#declare global_anim_showcampath = no;
#end

#if((global_anim=on)|(global_anim_showcampath=yes))
#declare global_anim_npoints_cam_flight=0;
#warning "No/not enough Animation Data available (min. 3 points) (Flight path)"
#end

#if((global_anim=on)|(global_anim_showcampath=yes))
#declare global_anim_npoints_cam_view=0;
#warning "No/not enough Animation Data available (min. 3 points) (View path)"
#end

#if((global_anim=on)|(global_anim_showcampath=yes))
#end

#if((global_anim_showcampath=yes)&(global_anim=off))
#end
#if(global_anim=on)
camera
{
	location global_anim_spline_cam_flight(clock)
	#if(global_anim_npoints_cam_view>2)
		look_at global_anim_spline_cam_view(clock)
	#else
		look_at global_anim_spline_cam_flight(clock+0.01)-<0,-0.01,0>
	#end
	angle 45
}
light_source
{
	global_anim_spline_cam_flight(clock)
	color rgb <1,1,1>
	spotlight point_at 
	#if(global_anim_npoints_cam_view>2)
		global_anim_spline_cam_view(clock)
	#else
		global_anim_spline_cam_flight(clock+0.01)-<0,-0.01,0>
	#end
	radius 35 falloff  40
}
#else
	camera
	{
		location <cam_x,cam_y,cam_z>
		look_at <cam_look_x,cam_look_y,cam_look_z>
		angle cam_a
		//translates the camera that <0,0,0> is over the Eagle <0,0>
		//translate<-33.500000,0,-5.750000>
	}
#end

background{col_bgr}
light_source{<lgt1_pos_x,lgt1_pos_y,lgt1_pos_z> White*lgt1_intense}
light_source{<lgt2_pos_x,lgt2_pos_y,lgt2_pos_z> White*lgt2_intense}
light_source{<lgt3_pos_x,lgt3_pos_y,lgt3_pos_z> White*lgt3_intense}
light_source{<lgt4_pos_x,lgt4_pos_y,lgt4_pos_z> White*lgt4_intense}

#include "strip.pov"

#include "wire.inc"

object{ 
union {
	STRIP(0,0,0,0,0,0)
#if(show_wires=on)
	PWIRE(rgb <0.8, 0.1, 0.1>, 1)
	PWIRE(Gray20, -1)
	PHWIRE(rgb <0.6, 0.6, 0.3>, 20.3454, 2)
	PHWIRE(rgb <0.3, 0.6, 0.3>,  31.0134, 1)
	PHWIRE(rgb <0.3, 0.3, 0.6>,   41.6814, 0)
#end
	translate<-29.500000,0,-5.750000>
	#if(pcb_upsidedown=on)
		rotate pcb_rotdir*180
	#end
	rotate<pcb_rotate_x,pcb_rotate_y, pcb_rotate_z>
}

}

