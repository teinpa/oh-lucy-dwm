/* user and group to drop privileges to */
static const char *user = "hooxoo";
static const char *group = "nobody"; // use "nobody" for arch

static const char *colorname[NUMCOLS] = {
    [INIT] = "#1e1d23",   /* after initialization */
    [INPUT] = "#938884",  /* during input */
    [FAILED] = "#ff7da3", /* wrong password */
};

/* lock screen opacity */
static const float alpha = 0.9;

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* time in seconds to cancel lock with mouse movement */
static const int timetocancel = 30;
