#ifndef	_FRAME_H_
#define	_FRAME_H_

#include <stdlib.h>
#include <stdio.h>

#include "uthash.h"

#define VERI 0
#define CMDI 1
#define LENI 2
#define SIDI 4

// cmds
enum cmd_type {
	cmdSYN  = 0, 		// stream open
	cmdFIN,             // stream close, a.k.a EOF mark
	cmdPSH,             // data push
	cmdNOP,             // no operation
};

struct frame {
	char ver;
	char cmd;
	ushort len;
	uint32_t sid;
	char *data;
};

// const (
// 	sizeOfVer    = 1
// 	sizeOfCmd    = 1
// 	sizeOfLength = 2
// 	sizeOfSid    = 4
// 	headerSize   = sizeOfVer + sizeOfCmd + sizeOfSid + sizeOfLength
// )
struct frame *new_frame(char cmd, uint32_t sid);
int get_header_size();
struct frame *raw_frame(char *buf, const size_t buf_len);
void free_frame(struct frame *f);

#endif //_FRAME_H_