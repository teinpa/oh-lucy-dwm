/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1; /* -b  option; if 0, dmenu appears at bottom */

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {"Operator Mono:size=8"};
static const char *prompt = NULL; /* -p  option; prompt to the left of input field */

static const char *colors[][2] = {
    /*               fg         bg       */
    [SchemeNorm] = {"#938884", "#1e1d23"},
    [SchemeSel] = {"#efd472", "#1e1d23"},
    [SchemeOut] = {"#000000", "#00ffff"},
    [SchemeBorder] = {"#efd472", "#1e1d23"},
    [SchemeSelHighlight] = {"#73c49d", "#1e1d23"},
    [SchemeNormHighlight] = {"#ded7d0", "#1e1d23"},
};

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 5;
