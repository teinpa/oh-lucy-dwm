/* appearance */
static const unsigned int borderpx       = 5;   /* border pixel of windows */
static const unsigned int snap           = 10;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 15;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 15;  /* vert inner gap between windows */
static const unsigned int gappoh         = 65;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 65;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 30;   /* 0 means derive from font, >= 1 explicit height */
static const int vertpad                 = 5;  /* vertical padding of bar */
static const int sidepad                 = 15;  /* horizontal padding of bar */
static const int focusonwheel            = 0;
static int floatposgrid_x                = 5;  /* float grid columns */
static int floatposgrid_y                = 5;  /* float grid rows */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';

/* indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_NONE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_NONE;
static const char *fonts[]               = { "Operator Mono:size=8", "NanumSquare Neo:style=Bold:size=8", "JoyPixels:size=8" };
static const char dmenufont[]            = "Operator Mono:size=8";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#efd472";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#efd472";

static char titlenormfgcolor[]           = "#ded7d0";
static char titlenormbgcolor[]           = "#1e1d23";
static char titlenormbordercolor[]       = "#1e1d23";
static char titlenormfloatcolor[]        = "#bda9d4";

static char titleselfgcolor[]            = "#ded7d0";
static char titleselbgcolor[]            = "#1e1d23";
static char titleselbordercolor[]        = "#1e1d23";
static char titleselfloatcolor[]         = "#bda9d4";

static char tagsnormfgcolor[]            = "#ded7d0";
static char tagsnormbgcolor[]            = "#1e1d23";
static char tagsnormbordercolor[]        = "#1e1d23";
static char tagsnormfloatcolor[]         = "#bda9d4";

static char tagsselfgcolor[]             = "#efd472";
static char tagsselbgcolor[]             = "#1e1d23";
static char tagsselbordercolor[]         = "#1e1d23";
static char tagsselfloatcolor[]          = "#bda9d4";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#ded7d0";
static char urgbgcolor[]                 = "#1e1d23";
static char urgbordercolor[]             = "#efd472";
static char urgfloatcolor[]              = "#ff7da3";

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};


/* tags */
static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { "", "", "", "", "" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E" },
	[ALT_TAGS_DECORATION] = { "", "", "", "", "" },
};


/* rules */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	// RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "st", .isterminal = 1)
	// RULE(.class = "firefox", "Toolkit", .iscentered = 1, .isfloating = 1)
	RULE(.class = "firefox", "Toolkit", .isfloating = 1, .floatpos = "50% 50% 900W 500H")
};


/* bar rules */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,          click_status2d,          NULL,                    "status2d" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "TILE",      tile },    /* first entry is default */
	{ "MNCL",      monocle },
	{ "CMTR",      centeredmaster },
	{ "NULL",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* dmenu */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-X", "15",
	"-Y", "5",
	"-W", "2540",
	"-p", " RUN : ",
	NULL};

static const char *termcmd[]  = { "st", NULL };

/* keybindings */
#include <X11/XF86keysym.h>

static const Key keys[] = {
	/* modifier                     key            function                argument */
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = dmenucmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_Left, focusdir, {.i = 0}},  // left
    {MODKEY, XK_Right, focusdir, {.i = 1}}, // right
    {MODKEY, XK_Up, focusdir, {.i = 2}},    // up
    {MODKEY, XK_Down, focusdir, {.i = 3}},  // down
    {MODKEY | ShiftMask, XK_Down, pushdown, {0}},
    {MODKEY | ShiftMask, XK_Up, pushup, {0}},
    {MODKEY | ControlMask, XK_Left, setmfact, {.f = -0.05}},
    {MODKEY | ControlMask, XK_Right, setmfact, {.f = +0.05}},
    // {MODKEY | ControlMask, XK_Home, setmfact, {0}},
    {MODKEY | ControlMask, XK_Up, setcfact, {.f = +0.25}},
    {MODKEY | ControlMask, XK_Down, setcfact, {.f = -0.25}},
    // {MODKEY | ControlMask, XK_End, setcfact, {0}},
    {MODKEY, XK_g, zoom, {0}},
		{Mod1Mask, XK_Tab, swapfocus, {.i = -1}},
    {MODKEY, XK_Tab, transfer, {0}},
    {MODKEY, XK_q, killclient, {0}},
    {MODKEY | ShiftMask, XK_q, quit, {0}},
    {MODKEY | ControlMask | ShiftMask, XK_q, quit, {1}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_n, setlayout, {.v = &layouts[3]}},
    {MODKEY, XK_space, togglefloating, {0}},
    {MODKEY | ShiftMask, XK_f, togglefullscreen, {0}},
		{Mod1Mask, XK_x, xrdb, {.v = NULL }},
    // {MODKEY, XK_w, spawn, SHCMD("naver-whale-stable")},
    {MODKEY | ControlMask, XK_q, spawn, SHCMD("xkill")},
    {MODKEY, XK_w, spawn, SHCMD("firefox")},
    {MODKEY, XK_e, spawn, SHCMD("pcmanfm")},
    {MODKEY, XK_x, spawn, SHCMD("$HOME/.config/scripts/dmenu_power.sh")},
    {MODKEY, XK_p, spawn, SHCMD("$HOME/.config/scripts/dmenu_screenshot.sh")},
    {MODKEY, XK_c, spawn, SHCMD("$HOME/.config/scripts/dmenu_music.sh")},
    {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("volume.sh up")},
    {0, XF86XK_AudioLowerVolume, spawn, SHCMD("volume.sh down")},
    {0, XF86XK_AudioMute, spawn, SHCMD("volume.sh mute")},
    {ControlMask | Mod1Mask, XK_l, spawn, SHCMD("slock")},
    {ControlMask | Mod1Mask, XK_n, spawn, SHCMD("st -e nvim")},
    {ControlMask | Mod1Mask, XK_t, spawn, SHCMD("st -e tuir")},
    {ControlMask | Mod1Mask, XK_r, spawn, SHCMD("st -e lfrun")},
    {ControlMask | Mod1Mask, XK_s, spawn, SHCMD("st -e ncspot")},
    {ControlMask | Mod1Mask, XK_h, spawn, SHCMD("st -e htop")},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3) TAGKEYS(XK_5, 4)};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};


