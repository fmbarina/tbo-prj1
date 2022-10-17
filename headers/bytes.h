#ifndef BYTES_H_
#define BYTES_H_

typedef struct bytes_st Bytes;

Bytes *bytes_init(long size);

void bytes_free(Bytes *by);

double bytes_get(Bytes *by, long idx);

void bytes_set(Bytes *by, long idx, double v);

double *bytes_contents(Bytes *by);

long bytes_len(Bytes *by);

#endif /* BYTES_H_ */