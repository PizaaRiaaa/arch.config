/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {"monospace:size=10","3270Medium Nerd Font:size=10"};
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "";
static const char col_gray2[]       = "";
static const char col_gray3[]       = "";
static const char col_gray4[]       = "";
static const char col_cyan[]        = "";
static const char col_urgborder[]   = "";


#include "/home/pizaariaaa/.cache/wal/colors-wal-dwm.h"

/* tagging */
static const char *tags[] = { "","2", "3", "4", "5"};
static const char *alttags[] = { "^", "2^", "3^", "4^", "5^" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
 	{ "[@]",      spiral },
 	{ "[\\]",      dwindle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>
static const char *brightup[]       = { "xbacklight", "-inc", "10", NULL};
static const char *brightdown[]     = { "xbacklight", "-dec", "10", NULL};
static Key keys[] = {
	/* modifier                     key               function              argument */
	{ MODKEY,		                 XK_BackSpace,     spawn,             	SHCMD("sysact") },
	{ MODKEY|ShiftMask,             XK_BackSpace,     spawn,             	SHCMD("sysact") },
 	{ MODKEY,	                    XK_F1, 	 	     spawn,              	SHCMD("st sudo pkill -u pizaariaaa") }, 
 	{ MODKEY,	                    XK_F2, 	 	     spawn,              	SHCMD("st sudo systemctl suspend") },   
 	{ MODKEY,	                    XK_F3, 	 	     spawn,              	SHCMD("st sudo systemctl reboot") },    
   { MODKEY,	                    XK_F4, 	 	     spawn,              	SHCMD("st sudo systemctl poweroff") },  
   { MODKEY,                       XK_F5,            spawn,                {.v = brightdown } },
   { MODKEY,       	              XK_F6,            spawn,                {.v = brightup } },
 	{ MODKEY,		                 XK_q,   	        spawn,             	SHCMD("st -e ranger ~/Videos") },
 	{ MODKEY,		                 XK_w,	 	        spawn,              	SHCMD("st -e ranger ~/Pictures/wallpapers") },
 	{ MODKEY,		                 XK_e,  	        spawn,              	SHCMD("st -e ranger ~/Documents/ebooks") },
 	{ MODKEY,		                 XK_n, 	 	        spawn,              	SHCMD("st -e ncmpcpp-ueberzug") },
 	{ MODKEY,		                 XK_k, 	 	        spawn,              	SHCMD("st -e ranger") },
 	{ MODKEY,	                    XK_j, 	 	        spawn,              	SHCMD("rofi -modi drun -show drun -show-icons") },
 	{ MODKEY,	                    XK_x, 	 	        spawn,              	SHCMD("rofi -show calc -modi calc -no-show-match -no-sort") },
 	{ MODKEY,	                    XK_p, 	 	        spawn,              	SHCMD("flameshot gui -d 200") },
	//{ MODKEY,                       XK_p,             spawn,                {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,        spawn,                {.v = termcmd } },
	{ MODKEY,                       XK_b,             togglebar,            {0} },
	{ MODKEY,                       XK_a,             focusstack,           {.i = +1 } },
	//{ MODKEY,                       XK_d,             focusstack,           {.i = -1 } },
	{ MODKEY,                       XK_i,             incnmaster,           {.i = +1 } },
	{ MODKEY,                       XK_d,             incnmaster,           {.i = -1 } },
	{ MODKEY,                       XK_h,             setmfact,             {.f = -0.05} },
	{ MODKEY,                       XK_l,             setmfact,             {.f = +0.05} },
	{ MODKEY,                       XK_Return,        zoom,                 {0} },
	{ MODKEY,                       XK_Tab,           view,                 {0} },
	{ MODKEY|ShiftMask,             XK_c,             killclient,           {0} },
	{ MODKEY,                       XK_t,             setlayout,            {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,             setlayout,            {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,             setlayout,            {.v = &layouts[2]} },
	{ MODKEY,                       XK_r,             setlayout,            {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_r,             setlayout,            {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,         setlayout,            {0} },
	{ MODKEY|ShiftMask,             XK_space,         togglefloating,       {0} },
	{ MODKEY|ShiftMask,             XK_f,   	        togglefullscr,      	{0} },
	{ MODKEY,                       XK_0,             view,                 {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,             tag,                  {.ui = ~0 } },
	{ MODKEY,                       XK_comma,         focusmon,             {.i = -1 } },
	{ MODKEY,                       XK_period,        focusmon,             {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,         tagmon,               {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,        tagmon,               {.i = +1 } },
	{ MODKEY,                       XK_minus,         setgaps,              {.i = -1 } },
	{ MODKEY,                       XK_equal,         setgaps,              {.i = +1 } },
	{ MODKEY|ShiftMask,	           XK_p,		        spawn,              	SHCMD("mpc pause ; pauseallmpv") },
	{ MODKEY,		                 XK_bracketleft,	  spawn,              	SHCMD("mpc seek -10") },
	{ MODKEY|ShiftMask,	           XK_bracketleft,	  spawn,              	SHCMD("mpc seek -60") },
	{ MODKEY,			              XK_bracketright,  spawn,              	SHCMD("mpc seek +10") },
	{ MODKEY|ShiftMask,	           XK_bracketright,  spawn,              	SHCMD("mpc seek +60") },
   { MODKEY|ShiftMask,	           XK_m,		        spawn,              	SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
  	{ MODKEY|ShiftMask,	           XK_minus,         spawn,             	SHCMD("pamixer --allow-boost -d 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,	           XK_equal,         spawn,             	SHCMD("pamixer --allow-boost -i 15; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,		                 XK_comma,      	  spawn,              	SHCMD("mpc prev") },
	{ MODKEY|ShiftMask,         	  XK_comma,         spawn,              	SHCMD("mpc seek 0%") },
	{ MODKEY,			              XK_period,        spawn,                SHCMD("mpc next") },
	{ MODKEY|ShiftMask,		        XK_period,        spawn,	               SHCMD("mpc repeat") },

   { 0, XF86XK_AudioMute,	                          spawn,             	SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,                     spawn,	               SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioLowerVolume,                     spawn,	               SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioPrev,	                          spawn,	               SHCMD("mpc prev") },
	{ 0, XF86XK_AudioNext,	                          spawn,	               SHCMD("mpc next") },
	{ 0, XF86XK_AudioPause,	                          spawn,	               SHCMD("mpc pause") },
	{ 0, XF86XK_AudioPlay,	                          spawn,	               SHCMD("mpc play") },
	{ 0, XF86XK_AudioStop,	                          spawn,	               SHCMD("mpc stop") },
	{ 0, XF86XK_AudioRewind,                          spawn,	               SHCMD("mpc seek -10") },
	{ 0, XF86XK_AudioForward,	                       spawn,               	SHCMD("mpc seek +10") },
	{ 0, XF86XK_AudioMedia,		                       spawn,               	SHCMD("st -e ncmpcpp") },
	{ 0, XF86XK_MonBrightnessUp,			              spawn,		            SHCMD("xbacklight -inc 10") },
	{ 0, XF86XK_MonBrightnessDown,			           spawn,		            SHCMD("xbacklight -dec 10") },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

