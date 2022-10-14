#ifndef BYTES_H_
#define BYTES_H_

typedef struct bytes_st Bytes;

Bytes *bytes_init(long size);

void bytes_free(Bytes *by);

unsigned char bytes_get(Bytes *by, long idx);

void bytes_set(Bytes *by, long idx, unsigned char v);

unsigned char *bytes_contents(Bytes *by);

long bytes_len(Bytes *by);

#endif /* BYTES_H_ */