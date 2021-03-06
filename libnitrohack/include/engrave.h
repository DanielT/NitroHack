/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/* NitroHack may be freely redistributed.  See license for details. */

#ifndef ENGRAVE_H
#define ENGRAVE_H

struct engr {
	struct engr *nxt_engr;
	char *engr_txt;
	unsigned engr_lth;	/* for save & restore; not length of text */
	long engr_time;		/* moment engraving was (will be) finished */
	xchar engr_x, engr_y;
	xchar engr_type;
#define DUST	   1
#define ENGRAVE    2
#define BURN	   3
#define MARK	   4
#define ENGR_BLOOD 5
#define HEADSTONE  6
#define N_ENGRAVE  6
};

#define newengr(lth) malloc((unsigned)(lth) + sizeof(struct engr))
#define dealloc_engr(engr) free((engr))

#endif /* ENGRAVE_H */
