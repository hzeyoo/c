#include "blake.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_blake.h"


void blake_hash(const char* input, char* output, uint32_t len)
{
    sph_blake256_context ctx_blake;
    sph_blake256_set_rounds(14);
    sph_blake256_init(&ctx_blake);
    sph_blake256(&ctx_blake, input, len);
    sph_blake256_close(&ctx_blake, output);
}

static void hexlify(char *hex, const unsigned char *bin, int len)
{
	hex[0] = 0;
	for(int i=0; i < len; i++)
		sprintf(hex+strlen(hex), "%02x", bin[i]);
}

void decred_hash(const char* input, char* output, uint32_t len)
{
	sph_blake256_context ctx_blake;

	sph_blake256_set_rounds(14);


	if (len > 180) len  = 180;



	sph_blake256_init(&ctx_blake);
	sph_blake256(&ctx_blake, input, len);
	sph_blake256_close(&ctx_blake, output);
}
