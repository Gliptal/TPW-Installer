//
// File created with TPW Settings. All comments are missing.
//
// It is not advisable to manually edit this file (unless instructed so), since it may break parsing.
//
//><
tpw_hint_active = 1;
//><
tpw_air_active = 1;
tpw_air_delay = 10;
tpw_air_time = 300;
tpw_air_max = 2;
tpw_air_heights[] = {50,250,500};
tpw_air_exclude = 1;
ADD TEST AFTER
//><
tpw_animal_active = 1;
tpw_animal_delay = 10;
tpw_animal_max = 15;
tpw_animal_maxradius = 200;
ADD TEST BEFORE
tpw_animal_minradius = 75;
tpw_animal_noisetime = 60;
//><
tpw_bleedout_active = 1;
tpw_bleedout_inc = 5;
tpw_bleedout_cthresh = 0.5;
tpw_bleedout_pthresh = 0.7;
tpw_bleedout_ithresh = 0.85;
//><
tpw_boat_active = 1;
tpw_boat_delay = 10;
tpw_boat_waypoints = 5;
tpw_boat_num = 3;
//><
tpw_car_active = 1;
tpw_car_delay = 10;
CHANGE TEST
tpw_car_num = 3;
tpw_car_radius = 1000;
tpw_car_nocombatspawn = 1;
//><
tpw_civ_active = 1;
tpw_civ_delay = 5;
tpw_civ_radius = 150;
tpw_civ_waypoints = 15;
tpw_civ_density = 5;
tpw_civ_maxsquadcas = 4;
tpw_civ_maxallcas = 50;
tpw_civ_casdisplay = 0;
tpw_civ_maxciv = 20;
tpw_civ_interact = 15;
tpw_civ_nocombatspawn = 1;
//><
tpw_ebs_active = 1;
tpw_ebs_thresh = 5;
tpw_ebs_delay = 1;
tpw_ebs_debug = 0;
tpw_ebs_radius = 500;
tpw_ebs_playersup = 1;
tpw_ebs_aisup = 1;
tpw_ebs_findcover = 1;
//><
tpw_fall_active = 1;
tpw_fall_sensitivity = 100;
tpw_fall_threshold = 300;
tpw_fall_delay = 10;
tpw_fall_ragdoll = 1;
tpw_fall_falltime = 15;
tpw_fall_player = 1;
tpw_fall_bullet = 1;
//><
tpw_fog_active = 1;
tpw_fog_radius = 250;
tpw_fog_delay = 5;
tpw_fog_breath = 1;
tpw_fog_groundfog = 1;
tpw_fog_rainfog = 1;
tpw_fog_heathaze = 1;
tpw_fog_cansnow = 1;
//><
tpw_houselights_active = 1;
tpw_houselights_delay = 10;
//><
tpw_hud_active = 1;
tpw_hud_range[] = {25,500};
tpw_hud_vehiclefactor = 1.5;
tpw_hud_colour[] = {1,1,1};
tpw_hud_friendlycolour[] = {0,1,1};
tpw_hud_civcolour[] = {1,1,1};
tpw_hud_enemycolour[] = {1,0.5,0};
tpw_hud_squadcolour[] = {0.5,1,0};
tpw_hud_alpha = 0.6;
tpw_hud_asl[] = {1,0.6,0.45,1};
tpw_hud_azt[] = {1,0.5,0.45,1};
tpw_hud_grd[] = {1,0.4,0.45,1};
tpw_hud_lmt[] = {1,0.4,0.5,1};
tpw_hud_tmp[] = {1,0.6,0.5,1};
tpw_hud_hlt[] = {1,0.4,0.55,1};
tpw_hud_rng[] = {1,0.5,0.55,1};
tpw_hud_vel[] = {1,0.6,0.55,1};
tpw_hud_prx[] = {1,0.5,0.5,1};
tpw_hud_unit[] = {1,1,0.25,0.75};
tpw_hud_offset[] = {0.35,0.28};
tpw_hud_scale = 0.8;
tpw_hud_textscale = 1;
tpw_hud_degradation = 1;
tpw_hud_thirdperson = 0;
tpw_hud_addtac = 1;
tpw_hud_audible = 1;
tpw_hud_icons[] = {24,23,30,29,24,23,30,29,22,20};
tpw_hud_asl_txt = "%1<t size='0.5'><br />ASL</t>";
tpw_hud_azt_txt = "%1<t size='0.5'><br />AZT %2</t>";
tpw_hud_grd_txt = "%1<t size='0.5'><br />GRD</t>";
tpw_hud_lmt_txt = "%1%2<t size='0.5'><br />LMT</t>";
tpw_hud_tmp_txt = "%1<t size='0.5'><br />TMP</t>";
tpw_hud_hlt_txt = "%1<t size='0.5'><br />HLT</t>";
tpw_hud_rng_txt = "%1<t size='0.5'><br />RNG</t>";
tpw_hud_vel_txt = "%1<t size='0.5'><br />VEL</t>";
tpw_hud_airvel_txt = "%1<t size='0.5'><br />VEL KTS</t>";
tpw_hud_prx_txt = "<t color='%5'>%1</t> <t color='%6'>%2</t> <t color='%7'>%3</t> <t color='%8'>%4</t><t size='0.5'><br />PRX</t>";
//><
tpw_los_active = 0;
tpw_los_debug = 0;
tpw_los_maxdist = 100;
tpw_los_mindist = 25;
tpw_los_delay = 10;
//><
tpw_park_active = 1;
tpw_park_perc = 25;
tpw_park_createdist = 300;
tpw_park_hidedist = 150;
tpw_park_simdist = 20;
tpw_park_max = 15;
//><
tpw_radio_active = 1;
tpw_radio_house = 1;
tpw_radio_car = 1;
tpw_radio_time = 60;
//><
tpw_rain_active = 1;
//><
tpw_skirmish_active = 1;
tpw_skirmish_enemysquad_max = 5;
tpw_skirmish_enemyvehicles_max = 2;
tpw_skirmish_friendlysquad_max = 5;
tpw_skirmish_friendlyvehicles_max = 2;
tpw_skirmish_minspawnradius = 500;
tpw_skirmish_maxspawnradius = 2000;
tpw_skirmish_support = 1;
tpw_skirmish_friendlytype = 1;
tpw_skirmish_enemytype = 1;
tpw_skirmish_spawntime = 10;
tpw_skirmish_friendlyunitstring = "";
tpw_skirmish_friendlyvehiclestring = "";
tpw_skirmish_enemyunitstring = "";
tpw_skirmish_enemyvehiclestring = "";
//><
tpw_streetlights_active = 1;
tpw_streetlights_factor = 10;
tpw_streetlights_range = 1000;
tpw_streetlights_colour = 0;
tpw_streetlights_moths = 1;
//><




