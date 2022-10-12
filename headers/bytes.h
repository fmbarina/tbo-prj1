#ifndef BYTES_H_
#define BYTES_H_

typedef struct bytes_st Bytes;

Bytes *bytes_init(unsigned long int size);

void bytes_free(Bytes *by);

unsigned char bytes_get(Bytes *by, unsigned long int idx);

void bytes_set(Bytes *by, unsigned long int idx, unsigned char v);

unsigned char* bytes_contents(Bytes *by);

unsigned long int bytes_len(Bytes *by);

#endif /* BYTES_H_ */